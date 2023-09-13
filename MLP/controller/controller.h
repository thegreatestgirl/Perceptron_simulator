#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>

#include "model/graph_network.h"
#include "model/matrix_network.h"

namespace s21 {

enum NetworkTypes : int { kMatrixNetwork = 1, kGraphNetwork };

class Controller {
 private:
  s21::Network* network_;

 public:
  Controller();
  Controller(const Controller& other) = default;
  Controller(Controller&& other) = default;
  ~Controller() = default;

  void SetNetworkPointer(s21::Network* network);
  s21::Network* GetNetworkPointer();
};

}  // namespace s21

#endif  // CONTROLLER_H
