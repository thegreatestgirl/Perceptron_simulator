#include "graph_network.h"

using s21::GraphNetwork;
using s21::NetworkAnswer;
using s21::Neuron;

GraphNetwork::GraphNetwork() {  // with bias (ordinary neuron, but output
                                // signal 1.0)
  std::vector<int> hidden_layers_neurons_quantity = {
      kDefaultHiddenLayerNeuronsQuantity, kDefaultHiddenLayerNeuronsQuantity,
      kDefaultHiddenLayerNeuronsQuantity, kDefaultHiddenLayerNeuronsQuantity,
      kDefaultHiddenLayerNeuronsQuantity};
  InitializeStartNeuron();
  InitializeInputLayer();
  InitializeHiddenNeurons(2, hidden_layers_neurons_quantity);
  InitializeOutputNeurons();
}

GraphNetwork::GraphNetwork(
    int hidden_layers_quantity,
    std::vector<int> neurons_on_hidden_layers_quantity,
    int output_classes_quantity) {  // with bias (ordinary neuron,
  // but output signal 1.0)
  SetOutputClassesQuantity(output_classes_quantity);
  InitializeStartNeuron();
  InitializeInputLayer();
  InitializeHiddenNeurons(hidden_layers_quantity,
                          neurons_on_hidden_layers_quantity);
  InitializeOutputNeurons();
}

void GraphNetwork::InitializeStartNeuron() {
  start_ = std::make_shared<Neuron>();
  start_.get()->output_signal_ = 0.0;
  start_.get()->error_ = 0.0;
}

std::vector<std::shared_ptr<Neuron>> GraphNetwork::InitializeNextNeurons(
    int neurons_quantity) {
  std::vector<std::shared_ptr<Neuron>> next_neurons_addresses;
  for (int i = 0; i < neurons_quantity + 1; ++i) {
    std::shared_ptr<Neuron> n = std::make_shared<Neuron>();
    if (i == neurons_quantity) {
      n.get()->output_signal_ = 1.0;
    } else {
      n.get()->output_signal_ = 0.0;
    }
    n.get()->error_ = 0.0;
    next_neurons_addresses.push_back(n);
  }
  return next_neurons_addresses;
}

void GraphNetwork::InitializeInputLayer() {
  std::vector<std::shared_ptr<Neuron>> next_neurons_addresses =
      InitializeNextNeurons(kInputSensorsQuantity);
  for (int i = 0; i < next_neurons_addresses.size(); ++i) {
    start_.get()->next_neurons_.push_back(
        {next_neurons_addresses[i], {0.0, 0.0}});  // not meaningful weights
  }
  last_added_ = start_.get()->next_neurons_;
}

void GraphNetwork::InitializeHiddenNeurons(
    int quantity, std::vector<int> neurons_on_layer_quantity) {
  for (int hidden_layers_quantity = 0; hidden_layers_quantity < quantity;
       ++hidden_layers_quantity) {
    std::vector<std::shared_ptr<Neuron>> next_neurons_addresses =
        InitializeNextNeurons(
            neurons_on_layer_quantity[hidden_layers_quantity]);

    for (int i = 0; i < last_added_.size(); ++i) {
      std::shared_ptr<Neuron> cur = last_added_[i].first;
      for (int j = 0; j < neurons_on_layer_quantity[hidden_layers_quantity] + 1;
           ++j) {
        cur.get()->next_neurons_.push_back(
            {next_neurons_addresses[j],
             {GenerateRandomNumberBetweenOneAndZero(), 0.0}});
      }
    }
    last_added_ = last_added_[0].first.get()->next_neurons_;
  }
}

void GraphNetwork::InitializeOutputNeurons() {
  std::vector<std::shared_ptr<Neuron>> next_neurons_addresses;
  for (int i = 0; i < GetOutputClassesQuantity(); ++i) {
    std::shared_ptr<Neuron> n = std::make_shared<Neuron>();
    n.get()->output_signal_ = 0.0;
    n.get()->error_ = 0.0;
    next_neurons_addresses.push_back(n);
  }
  for (int i = 0; i < last_added_.size(); ++i) {
    std::shared_ptr<Neuron> cur = last_added_[i].first;

    for (int j = 0; j < GetOutputClassesQuantity(); ++j) {
      cur.get()->next_neurons_.push_back(
          {next_neurons_addresses[j],
           {GenerateRandomNumberBetweenOneAndZero(), 0.0}});
    }
  }
  last_added_ = last_added_[0].first.get()->next_neurons_;
}

void GraphNetwork::Forward() {
  std::vector<std::pair<std::shared_ptr<Neuron>, std::pair<double, double>>>
      current;
  current = start_.get()->next_neurons_;
  while (current[0].first.get() != last_added_[0].first.get()) {
    for (int next_idx = 0;
         next_idx < current[0].first.get()->next_neurons_.size(); ++next_idx) {
      double input_sum = 0;
      for (int cur_idx = 0; cur_idx < current.size(); ++cur_idx) {
        input_sum +=
            current[cur_idx].first.get()->output_signal_ *
            current[cur_idx].first.get()->next_neurons_[next_idx].second.first;
      }
      current[0]
          .first.get()
          ->next_neurons_[next_idx]
          .first.get()
          ->output_signal_ = s21::ActivateFunction::Execute(input_sum);
      if (next_idx == current[0].first.get()->next_neurons_.size() - 1 &&
          (current[0].first.get()->next_neurons_[0].first !=
           last_added_[0].first)) {
        current[0]
            .first.get()
            ->next_neurons_[next_idx]
            .first.get()
            ->output_signal_ = 1.0;
      }
    }
    current = current[0].first.get()->next_neurons_;
  }
}

void GraphNetwork::Backpropagation(std::vector<double>& answers) {
  for (int i = 0; i < last_added_.size(); ++i) {
    last_added_[i].first.get()->error_ =
        -1.0 * last_added_[i].first.get()->output_signal_ *
        (1.0 - last_added_[i].first.get()->output_signal_) *
        (answers[i] - last_added_[i].first.get()->output_signal_);
  }
  std::vector<std::pair<std::shared_ptr<Neuron>, std::pair<double, double>>>
      current;
  std::vector<std::pair<std::shared_ptr<Neuron>, std::pair<double, double>>>
      next;
  next = last_added_;
  current = start_.get()->next_neurons_;
  while (next != start_.get()->next_neurons_) {
    current = start_.get()->next_neurons_;
    while (current[0].first.get()->next_neurons_[0].first.get() !=
           next[0].first.get()) {
      current = current[0].first.get()->next_neurons_;
    }

    for (int cur_idx = 0; cur_idx < current.size(); ++cur_idx) {
      double weight_sum = 0;
      for (int next_idx = 0; next_idx < next.size(); ++next_idx) {
        weight_sum +=
            current[cur_idx].first.get()->next_neurons_[next_idx].second.first *
            next[next_idx].first.get()->error_;
      }
      current[cur_idx].first.get()->error_ =
          current[cur_idx].first.get()->output_signal_ *
          (1.0 - current[cur_idx].first.get()->output_signal_) * weight_sum;
    }

    for (int cur_idx = 0; cur_idx < current.size(); ++cur_idx) {
      for (int next_idx = 0; next_idx < next.size(); ++next_idx) {
        current[cur_idx].first.get()->next_neurons_[next_idx].second.second =
            (current[cur_idx]
                 .first.get()
                 ->next_neurons_[next_idx]
                 .second.second *
             kAlpha) +
            ((1.0 - kAlpha) * kEducationalSpeed *
             next[next_idx].first.get()->error_ *
             current[cur_idx].first.get()->output_signal_);
      }
    }
    next = current;
    current = start_.get()->next_neurons_;
  }

  current = start_.get()->next_neurons_;
  while (current[0].first.get() != last_added_[0].first.get()) {
    for (int next_idx = 0;
         next_idx < current[0].first.get()->next_neurons_.size(); ++next_idx) {
      for (int cur_idx = 0; cur_idx < current.size(); ++cur_idx) {
        current[cur_idx].first.get()->next_neurons_[next_idx].second.first =
            current[cur_idx].first.get()->next_neurons_[next_idx].second.first -
            current[cur_idx].first.get()->next_neurons_[next_idx].second.second;
      }
    }
    current = current[0].first.get()->next_neurons_;
  }
}

void GraphNetwork::Train(const std::string& filename, int epoch_quantity) {
  std::cout << "> Start loading dataset..." << std::endl;
  LoadDatasetFromFile(filename);
  std::cout << "> Loading done. Education starts..." << std::endl;
  for (int epoch = 1; epoch <= epoch_quantity; ++epoch) {
    std::cout << "> Epoch: " << epoch << std::endl;
    ShuffleDataset();
    for (int letter_index = 0; letter_index < dataset_.size(); ++letter_index) {
      if (letter_index % 1000 == 0)
        std::cout << "> " << letter_index << " letters done..." << std::endl;
      InitializeInputNeurons(letter_index);
      Forward();
      Backpropagation(dataset_[letter_index].alphabet);
    }
  }
}

std::vector<s21::RightAndNetworkAnswer> GraphNetwork::Test(
    const std::string& filename, double segment_of_test_sample) {
  std::cout << "> Start loading test dataset..." << std::endl;
  LoadDatasetFromFile(filename);
  std::cout << "> Loading done. Testing starts..." << std::endl;
  std::vector<s21::RightAndNetworkAnswer> answers;
  for (int letter_index = 0;
       letter_index < (dataset_.size() * segment_of_test_sample);
       ++letter_index) {
    std::vector<double> input_sensors;
    for (int i = 0; i < dataset_[letter_index].pixels_intensity.size(); ++i) {
      input_sensors.push_back(dataset_[letter_index].pixels_intensity[i]);
    }
    answers.push_back(
        {MakeAGuess(input_sensors), dataset_[letter_index].alphabet});
  }
  return answers;
}

NetworkAnswer GraphNetwork::MakeAGuess(std::vector<double>& input_signals) {
  // PrintWeights();
  for (int i = 0; i < input_signals.size(); ++i) {
    start_.get()->next_neurons_[i].first.get()->output_signal_ =
        input_signals[i] / 255.0;
  }
  Forward();
  NetworkAnswer answer;
  answer.probability = -1.0;
  for (int i = 0; i < GetOutputClassesQuantity(); ++i) {
    if (last_added_[i].first.get()->output_signal_ > answer.probability) {
      answer.probability = last_added_[i].first.get()->output_signal_;
      answer.letter = i;
    }
  }
  // Print();
  return answer;
}

void GraphNetwork::TrainOnImg(std::vector<double>& input_signals,
                              int right_class_number) {
  for (int i = 0; i < input_signals.size(); ++i) {
    start_.get()->next_neurons_[i].first.get()->output_signal_ =
        input_signals[i] / 255.0;
  }
  Forward();
  std::vector<double> answer;
  for (int i = 0; i < GetOutputClassesQuantity(); ++i) {
    answer.push_back(0.0);
  }
  answer[right_class_number] = 1.0;
  Backpropagation(answer);
}

int GraphNetwork::GetHiddenLayersQuantity() {
  std::vector<std::pair<std::shared_ptr<Neuron>, std::pair<double, double>>>
      current;
  int layers_quantity = 1;
  current = start_.get()->next_neurons_;
  while (current[0].first.get() != last_added_[0].first.get()) {
    layers_quantity++;
    current = current[0].first.get()->next_neurons_;
  }
  return layers_quantity - 2;
}

std::vector<int> GraphNetwork::GetHiddenLayersSizesFromFile(
    const std::string& s) {
  std::vector<int> result;
  std::stringstream ss(s);
  std::string item;
  while (getline(ss, item, ' ')) {
    result.push_back(std::stoi(item));
  }
  return result;
}

std::vector<double> GraphNetwork::Split(const std::string str,
                                        const char delimiter) {
  std::stringstream str_stream(str);
  std::string segment;
  std::vector<double> data;
  while (std::getline(str_stream, segment, delimiter)) {
    double weight = std::stod(segment);
    data.push_back(weight);
  }
  return data;
}

void GraphNetwork::LoadFromFile(const std::string& filename) {
  // how to clean neuron net??
  int hidden_layers_quantity = 0;
  std::ifstream config_file(filename);
  std::string file_string;
  std::getline(config_file, file_string);
  SetOutputClassesQuantity(std::stoi(file_string));
  std::getline(config_file, file_string);  // hidden layers quantity
  hidden_layers_quantity = std::stoi(file_string);
  std::getline(config_file, file_string);  // hidden layer neurons
  std::vector<int> hidden_layers_sizes =
      GetHiddenLayersSizesFromFile(file_string);
  for (int i = 0; i < hidden_layers_sizes.size(); ++i) {
    hidden_layers_sizes[i] -= 1;
  }
  GraphNetwork new_network(hidden_layers_quantity, hidden_layers_sizes,
                           GetOutputClassesQuantity());

  std::vector<std::pair<std::shared_ptr<Neuron>, std::pair<double, double>>>
      current;
  current = new_network.start_.get()->next_neurons_;

  while (current[0].first.get() != new_network.last_added_[0].first.get()) {
    std::getline(config_file, file_string);
    for (int i = 0; i < current.size(); ++i) {
      std::shared_ptr<Neuron> cur = current[i].first;  // input layer neuron
      std::getline(config_file, file_string);
      std::vector<double> weights = Split(file_string, ' ');
      if (weights.empty()) {
        --i;
        continue;
      }
      for (int j = 0; j < cur.get()->next_neurons_.size(); ++j) {
        cur.get()->next_neurons_[j].second.first = weights[j];
      }
    }
    current = current[0].first.get()->next_neurons_;
  }
  start_ = new_network.start_;
  last_added_ = new_network.last_added_;
}

void GraphNetwork::SaveNetworkSettingToFile(const std::string& file_name) {
  std::ofstream network_config(file_name);
  network_config << GetOutputClassesQuantity() << std::endl;
  int hidden_layers_quantity = GetHiddenLayersQuantity();
  network_config << hidden_layers_quantity << std::endl;

  std::vector<std::pair<std::shared_ptr<Neuron>, std::pair<double, double>>>
      current;
  current = start_.get()->next_neurons_;
  while (current[0].first.get() != last_added_[0].first.get()) {
    if (current == start_.get()->next_neurons_ || current == last_added_) {
    } else {
      network_config << current.size() << " ";
    }
    current = current[0].first.get()->next_neurons_;
  }

  network_config << std::endl;
  network_config << std::endl;

  current = start_.get()->next_neurons_;
  while (current[0].first.get() != last_added_[0].first.get()) {
    for (int i = 0; i < current.size(); ++i) {
      std::shared_ptr<Neuron> cur = current[i].first;

      for (int j = 0; j < cur.get()->next_neurons_.size(); ++j) {
        network_config << cur.get()->next_neurons_[j].second.first << " ";
      }
      network_config << std::endl;
    }
    network_config << std::endl;
    network_config << std::endl;
    current = current[0].first.get()->next_neurons_;
  }

  network_config.close();
}

void GraphNetwork::InitializeInputNeurons(int letter_index) {
  for (int i = 0; i < dataset_[letter_index].pixels_intensity.size(); ++i) {
    start_.get()->next_neurons_[i].first.get()->output_signal_ =
        dataset_[letter_index].pixels_intensity[i] / 255.0;
  }
}

void GraphNetwork::ShuffleDataset() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine random_engine(seed);
  std::shuffle(std::begin(dataset_), std::end(dataset_), random_engine);
}

void GraphNetwork::LoadDatasetFromFile(const std::string& file_name) {
  dataset_ = parser_.Parse(file_name);
}

double GraphNetwork::GenerateRandomNumberBetweenOneAndZero() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist6(-50, 50);
  return static_cast<double>(dist6(rng)) / 100.0;
}

void GraphNetwork::Print() {
  std::cout << "OUTPUT NEURONS: " << std::endl;
  for (int i = 0; i < last_added_.size(); ++i) {
    std::shared_ptr<Neuron> cur = last_added_[i].first;
    std::cout << "Neuron: " << i + 1
              << "\toutput signal: " << cur.get()->output_signal_ << std::endl;
  }
}

void GraphNetwork::PrintNet() {
  std::cout << "Start addres: " << &start_ << std::endl;

  std::vector<std::pair<std::shared_ptr<Neuron>, std::pair<double, double>>>
      current;
  current = start_.get()->next_neurons_;

  for (int i = 0; i < current.size(); ++i) {
    std::cout << "Neuron: " << i
              << "\tneuron address: " << current[i].first.get() << std::endl;
  }
  std::cout << std::endl << std::endl << std::endl;

  while (current[0].first.get() != last_added_[0].first.get()) {
    for (int i = 0; i < current.size(); ++i) {
      std::shared_ptr<Neuron> cur = current[i].first;  // input layer neuron
      std::cout << "INPUT NEURON: " << i << "\taddress: " << cur.get()
                << std::endl;

      for (int j = 0; j < cur.get()->next_neurons_.size(); ++j) {
        std::cout << "Neuron: " << j
                  << "\toutput signal: " << cur.get()->output_signal_
                  << "\t\terror: " << cur.get()->error_ << "\tnext neuron: "
                  << cur.get()->next_neurons_[j].first.get()
                  << "\tweight: " << cur.get()->next_neurons_[j].second.first
                  << std::endl;
      }
    }
    current = current[0].first.get()->next_neurons_;
    std::cout << std::endl
              << "///////////////////////////////////////////////////////////"
                 "//////////////////////////////////////"
              << std::endl;
  }

  std::cout << "OUTPUT NEURONS: " << std::endl;
  for (int i = 0; i < last_added_.size(); ++i) {
    std::shared_ptr<Neuron> cur = last_added_[i].first;  // input layer
    std::cout << "Neuron: " << i + 1
              << "\toutput signal: " << cur.get()->output_signal_
              << "\t\terror: " << cur.get()->error_ << std::endl;
  }
  std::cout << "_____________________________________________________________"
               "____________________________________________"
            << std::endl
            << std::endl
            << std::endl;
}
