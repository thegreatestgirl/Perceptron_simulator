#ifndef SRC_DATASET_PARSER_H_
#define SRC_DATASET_PARSER_H_

#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace s21 {

constexpr char kDatasetFileDelimiter = ',';
constexpr int kAlphabetLettersQuantity = 26;
constexpr int kDefaultAlphabetLetterValue = 0;
constexpr int kAlphabetLetter = 1;

struct Letter {
  // int number_in_alphabet;
  std::vector<double> alphabet;
  std::vector<double> pixels_intensity;
};

class DatasetParser {
 public:
  using data_type = std::vector<Letter>;

 public:
  data_type Parse(const std::string& file_name) {
    data_type data;
    std::ifstream file(file_name);
    if (file.fail()) {
      throw std::runtime_error("File does not exists");
    }
    std::string file_string;
    while (std::getline(file, file_string)) {
      data.push_back(ParseLine(file_string));
    }
    file.close();
    return data;
  }

 private:
  // data_type data_;

 private:
  Letter ParseLine(const std::string& file_string) {
    Letter letter;
    for (int i = 0; i < kAlphabetLettersQuantity; ++i) {
      letter.alphabet.push_back(0.0);
    }
    std::stringstream ss(file_string);
    std::string item;
    int i = 0;
    while (getline(ss, item, kDatasetFileDelimiter)) {
      if (i == 0) {
        letter.alphabet[std::stod(item) - 1] = kAlphabetLetter;
        ++i;
      } else {
        letter.pixels_intensity.push_back(std::stod(item));
      }
    }
    return letter;
  }
};

}  // namespace s21

#endif  // SRC_DATASET_PARSER_H_
