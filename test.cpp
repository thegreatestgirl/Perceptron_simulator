#include <gtest/gtest.h>

#include <iostream>

#include "MLP/model/graph_network.h"
#include "MLP/model/matrix_network.h"

TEST(GraphNetworkTest, grph_net_test_1) {
  s21::GraphNetwork graph_network;
  std::cout << "Start loading train dataset..." << std::endl;
  graph_network.Train("../datasets/emnist-letters-train.csv", 1);
  graph_network.SaveNetworkSettingToFile(
      "network_configs/network_from_test_1_epoch.conf");
  s21::GraphNetwork graph_network_from_file;
  graph_network_from_file.LoadFromFile(
      "network_configs/network_from_test_1_epoch.conf");
  std::vector<s21::RightAndNetworkAnswer> answers;
  std::vector<s21::RightAndNetworkAnswer> answers_from_file;
  answers = graph_network.Test("../datasets/emnist-letters-test.csv", 1);
  answers_from_file =
      graph_network_from_file.Test("../datasets/emnist-letters-test.csv", 1);
  double counter_answers = 0, counter_answers_from_file = 0;
  for (int i = 0; i < answers.size(); ++i) {
    if (answers[i].right_answer[answers[i].net_answer.letter] == 1)
      counter_answers++;
  }
  for (int i = 0; i < answers_from_file.size(); ++i) {
    if (answers_from_file[i]
            .right_answer[answers_from_file[i].net_answer.letter] == 1)
      counter_answers_from_file++;
  }
  ASSERT_EQ(counter_answers, counter_answers_from_file);
}

TEST(GraphNetworkTest, grph_net_test_2) {
  s21::GraphNetwork graph_network;
  std::cout << "Start loading train dataset..." << std::endl;
  // graph_network.Train("../datasets/emnist-letters-train.csv", 3);
  graph_network.LoadFromFile("network_configs/network_3_epoch.conf");
  std::vector<s21::RightAndNetworkAnswer> answers;
  std::cout << "Start loading test dataset..." << std::endl;
  answers = graph_network.Test("../datasets/emnist-letters-test.csv", 1);
  double counter = 0;
  for (int i = 0; i < answers.size(); ++i) {
    if (answers[i].right_answer[answers[i].net_answer.letter] == 1) counter++;
  }
  std::cout << counter / answers.size() << std::endl;
  ASSERT_GE((counter / answers.size()), 0.001);
}

TEST(MatrixNetworkTest, mtrx_net_test_1) {
  s21::MatrixNetwork graph_network;
  std::cout << "Start loading train dataset..." << std::endl;
  graph_network.Train("../datasets/emnist-letters-train.csv", 1);
  graph_network.SaveNetworkSettingToFile(
      "network_configs/network_from_test_1_epoch.conf");
  s21::MatrixNetwork graph_network_from_file;
  graph_network_from_file.LoadFromFile(
      "network_configs/network_from_test_1_epoch.conf");
  std::vector<s21::RightAndNetworkAnswer> answers;
  std::vector<s21::RightAndNetworkAnswer> answers_from_file;
  answers = graph_network.Test("../datasets/emnist-letters-test.csv", 1);
  answers_from_file =
      graph_network_from_file.Test("../datasets/emnist-letters-test.csv", 1);
  double counter_answers = 0, counter_answers_from_file = 0;
  for (int i = 0; i < answers.size(); ++i) {
    if (answers[i].right_answer[answers[i].net_answer.letter] == 1)
      counter_answers++;
  }
  for (int i = 0; i < answers_from_file.size(); ++i) {
    if (answers_from_file[i]
            .right_answer[answers_from_file[i].net_answer.letter] == 1)
      counter_answers_from_file++;
  }
  ASSERT_EQ(counter_answers, counter_answers_from_file);
}

TEST(MatrixNetworkTest, mtrx_net_test_2) {
  s21::MatrixNetwork graph_network;
  std::cout << "Start loading train dataset..." << std::endl;
  // graph_network.Train("../datasets/emnist-letters-train.csv", 3);
  graph_network.LoadFromFile("network_configs/network_3_epoch.conf");
  std::vector<s21::RightAndNetworkAnswer> answers;
  std::cout << "Start loading test dataset..." << std::endl;
  answers = graph_network.Test("../datasets/emnist-letters-test.csv", 1);
  double counter = 0;
  for (int i = 0; i < answers.size(); ++i) {
    if (answers[i].right_answer[answers[i].net_answer.letter] == 1) counter++;
  }
  std::cout << counter / answers.size() << std::endl;
  ASSERT_GE((counter / answers.size()), 0.001);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
