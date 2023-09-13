#ifndef SRC_MLP_MODEL_MATRIX_NETWORK_H_
#define SRC_MLP_MODEL_MATRIX_NETWORK_H_

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "activate_function.h"
#include "dataset_parser.h"
#include "matrix.h"
#include "network.h"

namespace s21 {

class Layer {
 public:
  std::vector<double> neurons_output_signals;
  std::vector<double> neurons_errors;

  s21::Matrix<double> weights;
  s21::Matrix<double> delta_weights;

  Layer(const int neurons_quantity);
  Layer(const int neurons_quantity, const int next_layer_neurons_quantity);
  Layer(const Layer& other) = default;
  Layer(Layer&& other) = default;
  ~Layer() = default;

  void InitNeuronsAndBiases(const int neurons_quantity);
  void InitNeurons(const int neurons_quantity);
  // void Print();
  size_t Size();
  double GenerateRandomNumberBetweenOneAndZero();
};

class MatrixNetwork : public s21::Network {
 private:
  std::vector<Layer*> layers_;

 private:
  std::vector<double> Split(const std::string str,
                            const char delimiter) override;
  std::vector<int> GetHiddenLayersSizes(const std::string& s);
  void Forward() override;
  void Backpropagation(std::vector<double>& answers) override;
  void UpdateWeights();
  void InitializeInputNeurons(int letter_index);
  void ShuffleDataset();
  int GenerateRandomNumber(int min, int max);

 public:
  MatrixNetwork();
  MatrixNetwork(int hidden_layers_quantity,
                std::vector<int> hidden_layers_neurons_quantity,
                int output_classes_quantity);
  MatrixNetwork(const MatrixNetwork& other) = default;
  MatrixNetwork(MatrixNetwork&& other) = default;
  ~MatrixNetwork();

  void LoadFromFile(const std::string& filename) override;
  NetworkAnswer MakeAGuess(std::vector<double>& input_signals) override;
  void TrainOnImg(std::vector<double>& input_signals,
                  int right_class_number) override;

  // void PrintWeights();
  void Train(const std::string& filename, int epoch_quantity) override;
  void SaveNetworkSettingToFile(const std::string& file_name) override;
  std::vector<RightAndNetworkAnswer> Test(
      const std::string& filename, double segment_of_test_sample) override;
  void LoadDatasetFromFile(const std::string& file_name);

  void Print() override;
  void PrintNet() override;
};

}  // namespace s21

#endif  // SRC_MLP_MODEL_MATRIX_NETWORK_H_
