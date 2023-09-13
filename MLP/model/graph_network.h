#ifndef SRC_MLP_MODEL_GRAPH_NETWORK_H_
#define SRC_MLP_MODEL_GRAPH_NETWORK_H_

#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <memory>
#include <random>
#include <vector>

#include "activate_function.h"
#include "dataset_parser.h"
#include "matrix.h"
#include "network.h"

namespace s21 {

class Neuron {
 public:
  double output_signal_;
  double error_;
  std::vector<std::pair<std::shared_ptr<Neuron>, std::pair<double, double>>>
      next_neurons_;
};

class GraphNetwork : public s21::Network {
 private:
  std::shared_ptr<Neuron> start_;
  std::vector<std::pair<std::shared_ptr<Neuron>, std::pair<double, double>>>
      last_added_;

 public:
  GraphNetwork();
  GraphNetwork(int hidden_layers_quantity,
               std::vector<int> neurons_on_hidden_layers_quantity,
               int output_classes_quantity);
  GraphNetwork(const GraphNetwork& other) = default;
  GraphNetwork(GraphNetwork&& other) = default;
  ~GraphNetwork() = default;

  void Train(const std::string& filename, int epoch_quantity) override;
  std::vector<RightAndNetworkAnswer> Test(
      const std::string& filename, double segment_of_test_sample) override;
  NetworkAnswer MakeAGuess(std::vector<double>& input_signals) override;
  void TrainOnImg(std::vector<double>& input_signals,
                  int right_class_number) override;
  void LoadFromFile(const std::string& filename) override;
  void SaveNetworkSettingToFile(const std::string& file_name) override;
  void LoadDatasetFromFile(const std::string& file_name);
  void Print() override;
  void PrintNet() override;

 private:
  void InitializeStartNeuron();
  std::vector<std::shared_ptr<Neuron>> InitializeNextNeurons(
      int neurons_quantity);
  void InitializeInputLayer();
  void InitializeHiddenNeurons(int quantity,
                               std::vector<int> neurons_on_layer_quantity);
  void InitializeOutputNeurons();
  void Forward() override;
  void Backpropagation(std::vector<double>& answers) override;
  int GetHiddenLayersQuantity();
  std::vector<int> GetHiddenLayersSizesFromFile(const std::string& s);
  std::vector<double> Split(const std::string str,
                            const char delimiter) override;
  void InitializeInputNeurons(int letter_index);
  void ShuffleDataset();
  double GenerateRandomNumberBetweenOneAndZero();
};
}  // namespace s21

#endif  // SRC_MLP_MODEL_GRAPH_NETWORK_H_
