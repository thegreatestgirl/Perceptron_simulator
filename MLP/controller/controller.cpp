#include "controller.h"

s21::Controller::Controller() { network_ = nullptr; }

void s21::Controller::SetNetworkPointer(s21::Network* network) {
  network_ = network;
}

s21::Network* s21::Controller::GetNetworkPointer() { return network_; }
