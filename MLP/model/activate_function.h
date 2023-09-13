#ifndef SRC_ACTIVATE_FUNCTION_H_
#define SRC_ACTIVATE_FUNCTION_H_

#include <math.h>

#include <vector>

namespace s21 {

constexpr double exponent = 2.71828182845905;

class ActivateFunction {
 public:
  static double Execute(const double neuron_signal) {
    return 1.0 / (1.0 + pow(exponent, -1.0 * neuron_signal));
  }

  static double Derivative(const double neuron_signal) {
    double sigmoid = Execute(neuron_signal);
    return sigmoid * (1.0 - sigmoid);
  }
};

}  // namespace s21

#endif  // SRC_ACTIVATE_FUNCTION_H_
