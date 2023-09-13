#include "matrix_network.h"

using s21::Layer;
using s21::MatrixNetwork;
using s21::NetworkAnswer;

Layer::Layer(const int neurons_quantity) { InitNeurons(neurons_quantity); }

Layer::Layer(const int neurons_quantity,
             const int next_layer_neurons_quantity) {
  InitNeuronsAndBiases(neurons_quantity);
  weights.Resize(neurons_quantity, next_layer_neurons_quantity);
  weights.Randomize();

  delta_weights.Resize(neurons_quantity, next_layer_neurons_quantity);
  for (int i = 0; i < delta_weights.GetRows(); ++i) {
    for (int j = 0; j < delta_weights.GetColumns(); ++j) {
      delta_weights(i, j) = 0.0;
    }
  }
}

void Layer::InitNeuronsAndBiases(const int neurons_quantity) {
  for (int i = 0; i < neurons_quantity; ++i) {
    if (i == neurons_quantity - 1) {
      neurons_output_signals.push_back(1.0);
      neurons_errors.push_back(0.0);
    } else {
      neurons_output_signals.push_back(0.0);
      neurons_errors.push_back(0.0);
    }
  }
}

void Layer::InitNeurons(const int neurons_quantity) {
  for (int i = 0; i < neurons_quantity; ++i) {
    neurons_output_signals.push_back(0.0);
    neurons_errors.push_back(0.0);
  }
}

// void Layer::Print() {
//   for (int i = 0; i < Size(); ++i) {
//     std::cout << i + 1;
//     if (i < 9) {
//       std::cout << " ";
//     }
//     std::cout << " ";
//     std::printf("Output signal: %6.8f\tError: %6.8f\n",
//                 neurons_output_signals[i], neurons_errors[i]);
//   }
// }

size_t Layer::Size() { return neurons_output_signals.size(); }

double Layer::GenerateRandomNumberBetweenOneAndZero() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist6(-50, 50);
  return static_cast<double>(dist6(rng)) / 100.0;
}

MatrixNetwork::MatrixNetwork() {}

MatrixNetwork::MatrixNetwork(int hidden_layers_quantity,
                             std::vector<int> hidden_layers_neurons_quantity,
                             int output_classes_quantity) {
  SetOutputClassesQuantity(output_classes_quantity);
  std::cout << hidden_layers_quantity << std::endl;
  layers_.push_back(new Layer(kInputSensorsQuantity + 1,
                              hidden_layers_neurons_quantity[0] + 1));
  for (int k = 0; k < hidden_layers_quantity; ++k) {
    if (k == hidden_layers_quantity - 1) {
      layers_.push_back(new Layer(hidden_layers_neurons_quantity[k] + 1,
                                  GetOutputClassesQuantity()));
    } else {
      layers_.push_back(new Layer(hidden_layers_neurons_quantity[k] + 1,
                                  hidden_layers_neurons_quantity[k + 1] + 1));
    }
  }
  layers_.push_back(new Layer(GetOutputClassesQuantity()));
}

MatrixNetwork::~MatrixNetwork() {
  for (int i = 0; i < layers_.size(); ++i) {
    delete layers_[i];
  }
}

// NetworkInfo GetInfo() {
//   NetworkInfo info;
//   info.hidden_layers_quantity = layers_.size() - 2;
//   for (int i = 1; i < layers_.size() - 1; ++i) {
//     info.hidden_layers_neurons_quantity.push_back(layers_[i]->Size())x;
//   }
//   return info;
// }

void MatrixNetwork::LoadFromFile(const std::string& filename) {
  layers_.clear();
  int hidden_layers_quantity = 0;
  std::ifstream config_file(filename);
  std::string file_string;
  std::getline(config_file, file_string);
  SetOutputClassesQuantity(std::stoi(file_string));
  std::getline(config_file, file_string);  // hidden layers quantity
  hidden_layers_quantity = std::stoi(file_string);
  std::getline(config_file, file_string);  // hidden layerneurons

  std::vector<int> hidden_layer_sizes = GetHiddenLayersSizes(file_string);

  // Create inputlayer
  layers_.push_back(
      new Layer(kInputSensorsQuantity + 1, hidden_layer_sizes[0]));

  for (int k = 0; k < hidden_layer_sizes.size(); ++k) {
    if (k == hidden_layer_sizes.size() - 1) {
      layers_.push_back(
          new Layer(hidden_layer_sizes[k], GetOutputClassesQuantity()));
    } else {
      layers_.push_back(
          new Layer(hidden_layer_sizes[k], hidden_layer_sizes[k + 1]));
    }
  }
  layers_.push_back(new Layer(GetOutputClassesQuantity()));

  for (int k = 0; k < layers_.size() - 1; ++k) {
    Layer* l = layers_[k];
    std::getline(config_file, file_string);
    for (int i = 0; i < l->Size(); ++i) {
      std::getline(config_file, file_string);
      std::vector<double> weights = Split(file_string, ' ');
      if (weights.empty()) {
        --i;
        continue;
      }
      for (int j = 0; j < layers_[k + 1]->Size(); ++j) {
        l->weights(i, j) = weights[j];
      }
    }
  }

  config_file.close();
}

NetworkAnswer MatrixNetwork::MakeAGuess(std::vector<double>& input_signals) {
  // PrintWeights();
  for (int i = 0; i < input_signals.size(); ++i) {
    layers_[0]->neurons_output_signals[i] = input_signals[i] / 255.0;
  }
  Forward();
  NetworkAnswer answer;
  answer.probability = -1.0;
  for (int i = 0; i < GetOutputClassesQuantity(); ++i) {
    if (layers_[layers_.size() - 1]->neurons_output_signals[i] >
        answer.probability) {
      answer.probability =
          layers_[layers_.size() - 1]->neurons_output_signals[i];
      answer.letter = i;
    }
  }
  // layers_[layers_.size() - 1]->Print();
  return answer;
}

void MatrixNetwork::TrainOnImg(std::vector<double>& input_signals,
                               int right_class_number) {
  for (int i = 0; i < input_signals.size(); ++i) {
    layers_[0]->neurons_output_signals[i] = input_signals[i] / 255.0;
  }
  Forward();
  std::vector<double> answer;
  for (int i = 0; i < GetOutputClassesQuantity(); ++i) {
    answer.push_back(0.0);
  }
  answer[right_class_number] = 1.0;
  Backpropagation(answer);
}

std::vector<double> MatrixNetwork::Split(const std::string str,
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

std::vector<int> MatrixNetwork::GetHiddenLayersSizes(const std::string& s) {
  std::vector<int> result;
  std::stringstream ss(s);
  std::string item;
  while (getline(ss, item, ' ')) {
    result.push_back(std::stoi(item));
  }
  return result;
}

void MatrixNetwork::Forward() {
  for (int layer_index = 1; layer_index < layers_.size(); ++layer_index) {
    Layer* prev_layer = layers_[layer_index - 1];
    Layer* current_layer = layers_[layer_index];

    for (int curr_idx = 0; curr_idx < current_layer->Size(); ++curr_idx) {
      double input_sum = 0;
      for (int prev_idx = 0; prev_idx < prev_layer->Size(); ++prev_idx) {
        input_sum += prev_layer->weights(prev_idx, curr_idx) *
                     prev_layer->neurons_output_signals[prev_idx];
      }
      if (curr_idx != current_layer->Size() - 1) {
        current_layer->neurons_output_signals[curr_idx] =
            s21::ActivateFunction::Execute(input_sum);
      }
    }
  }
}

void MatrixNetwork::Backpropagation(std::vector<double>& answers) {
  // Step 6
  // Calculate neurons_errors for output layer
  Layer* output_layer = layers_[layers_.size() - 1];
  for (int k = 0; k < output_layer->Size(); ++k) {
    output_layer->neurons_errors[k] =
        -1.0 * output_layer->neurons_output_signals[k] *
        (1.0 - output_layer->neurons_output_signals[k]) *
        (answers[k] - output_layer->neurons_output_signals[k]);
  }
  // Step 7
  for (int k = layers_.size() - 2; k >= 0; --k) {
    Layer* curr_layer = layers_[k];
    Layer* next_layer = layers_[k + 1];

    // Calculate neurons_errors for current_layer
    for (int curr_idx = 0; curr_idx < curr_layer->Size(); ++curr_idx) {
      double weight_sum = 0;
      for (int next_idx = 0; next_idx < next_layer->Size(); ++next_idx) {
        weight_sum += curr_layer->weights(curr_idx, next_idx) *
                      next_layer->neurons_errors[next_idx];
      }
      curr_layer->neurons_errors[curr_idx] =
          curr_layer->neurons_output_signals[curr_idx] *
          (1.0 - curr_layer->neurons_output_signals[curr_idx]) * weight_sum;
    }

    for (int curr_idx = 0; curr_idx < curr_layer->Size(); ++curr_idx) {
      for (int next_idx = 0; next_idx < next_layer->Size(); ++next_idx) {
        curr_layer->delta_weights(curr_idx, next_idx) =
            (curr_layer->delta_weights(curr_idx, next_idx) * kAlpha) +
            ((1.0 - kAlpha) * kEducationalSpeed *
             next_layer->neurons_errors[next_idx] *
             curr_layer->neurons_output_signals[curr_idx]);
      }
    }
  }
  // Step 8
  UpdateWeights();
}

void MatrixNetwork::UpdateWeights() {
  for (int i = 0; i < layers_.size() - 1; ++i) {
    Layer* l = layers_[i];
    for (int i = 0; i < l->weights.GetRows(); ++i) {
      for (int j = 0; j < l->weights.GetColumns(); ++j) {
        l->weights(i, j) = l->weights(i, j) - l->delta_weights(i, j);
      }
    }
  }
}

// void MatrixNetwork::PrintWeights() {
//   for (int i = 0; i < layers_.size(); ++i) {
//     std::cout << "Layer: " << i << std::endl;
//     layers_[i]->weights.Print();
//   }
// }

void MatrixNetwork::Train(const std::string& filename, int epoch_quantity) {
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
  // layers_[layers_.size() - 1]->Print();
  SaveNetworkSettingToFile("network.conf");
}

void MatrixNetwork::SaveNetworkSettingToFile(const std::string& file_name) {
  std::ofstream network_config(file_name);
  network_config << GetOutputClassesQuantity() << std::endl;
  int hidden_layers_quantity = layers_.size() - 2;
  network_config << hidden_layers_quantity << std::endl;
  for (int i = 1; i < layers_.size() - 1; ++i) {
    network_config << layers_[i]->Size() << " ";
  }
  network_config << std::endl;
  network_config << std::endl;
  for (int i = 0; i < layers_.size(); ++i) {
    s21::Matrix<double>* matrix = &(layers_[i]->weights);
    for (int i = 0; i < matrix->GetRows(); ++i) {
      for (int j = 0; j < matrix->GetColumns(); ++j) {
        network_config << matrix->GetValue(i, j) << " ";
      }
      network_config << std::endl;
    }
    network_config << std::endl;
    network_config << std::endl;
  }

  network_config.close();
}

std::vector<s21::RightAndNetworkAnswer> MatrixNetwork::Test(
    const std::string& filename, double segment_of_test_sample) {
  std::cout << "> Start loading test dataset..." << std::endl;
  LoadDatasetFromFile(filename);
  std::cout << "> Loading done. Testing starts..." << std::endl;

  std::vector<RightAndNetworkAnswer> answers;
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

void MatrixNetwork::InitializeInputNeurons(int letter_index) {
  for (int i = 0; i < dataset_[letter_index].pixels_intensity.size(); ++i) {
    layers_[0]->neurons_output_signals[i] =
        dataset_[letter_index].pixels_intensity[i] / 255.0;
  }
}

void MatrixNetwork::ShuffleDataset() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine random_engine(seed);
  std::shuffle(std::begin(dataset_), std::end(dataset_), random_engine);
}

void MatrixNetwork::LoadDatasetFromFile(const std::string& file_name) {
  dataset_ = parser_.Parse(file_name);
}

int MatrixNetwork::GenerateRandomNumber(int min, int max) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist6(min, max);
  return static_cast<int>(dist6(rng));
}

void MatrixNetwork::Print(){};

void MatrixNetwork::PrintNet(){};
