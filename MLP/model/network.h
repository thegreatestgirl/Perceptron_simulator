#ifndef SRC_MLP_MODEL_NETWORK_H_
#define SRC_MLP_MODEL_NETWORK_H_

#include <array>
#include <vector>

#include "dataset_parser.h"

namespace s21 {
constexpr int kInputSensorsQuantity = 784;
constexpr int kDefaultHiddenLayerNeuronsQuantity = 100;
constexpr int kOneMore = 200;
// constexpr int kOutputClassesQuantity = 26;
constexpr int kBiasQuantity = 1;

constexpr double kEducationalSpeed = 0.1;
constexpr double kAlpha = 0.1;

struct NetworkInfo {
  int hidden_layers_quantity;
  std::vector<int> hidden_layers_neurons_quantity;
};

struct NetworkAnswer {
  double probability;
  int letter;
};

struct RightAndNetworkAnswer {
  NetworkAnswer net_answer;
  std::vector<double>& right_answer;
};

class Network {
 private:
  int output_classes_quantity_ = 26;

 protected:
  s21::DatasetParser::data_type dataset_;
  s21::DatasetParser parser_;

 public:
  virtual void Forward() = 0;
  virtual void Backpropagation(std::vector<double>& answers) = 0;
  virtual NetworkAnswer MakeAGuess(std::vector<double>& input_signals) = 0;
  virtual std::vector<double> Split(const std::string str,
                                    const char delimiter) = 0;
  virtual void LoadFromFile(const std::string& filename) = 0;
  virtual void Train(const std::string& filename, int epoch_quantity) = 0;
  virtual std::vector<RightAndNetworkAnswer> Test(
      const std::string& filename, double segment_of_test_sample) = 0;
  virtual void SaveNetworkSettingToFile(const std::string& file_name) = 0;
  virtual void TrainOnImg(std::vector<double>& input_signals,
                          int right_class_number) = 0;

  virtual void Print() = 0;
  virtual void PrintNet() = 0;

  void SetOutputClassesQuantity(int output_classes_quantity) {
    output_classes_quantity_ = output_classes_quantity;
  }

  int GetOutputClassesQuantity() { return output_classes_quantity_; }
};
}  // namespace s21

#endif  // SRC_MLP_MODEL_NETWORK_H_
