#include "Pares.h"

Pares::Pares(std::string ip, int accesos) {
  this->ip = ip;
  this->accesos = accesos;
}

Pares::Pares() {
  this->ip = " ";
  this->accesos = 0;
}

int Pares::getAcceso() { return this->accesos; }

std::string Pares::getIP() { return this->ip; }

std::string Pares::print() { return ip + " : " + std::to_string(accesos); }

bool Pares::operator==(const Pares &other) {
  return this->accesos == other.accesos;
}

std::string Pares::operator+(std::string &other) { return this->ip + other; }

bool Pares::operator!=(const Pares &other) {
  return this->accesos != other.accesos;
}

bool Pares::operator>(const Pares &other) {
  return this->accesos > other.accesos;
}

bool Pares::operator<(const Pares &other) {
  return this->accesos < other.accesos;
}

bool Pares::operator<=(const Pares &other) {
  return this->accesos <= other.accesos;
}

bool Pares::operator>=(const Pares &other) {
  return this->accesos >= other.accesos;
}
