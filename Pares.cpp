#include "Pares.h"

Pares::Pares(std::string ip, int accesos){
  this-> ip = ip;
  this-> accesos = accesos;
}

int Pares::getAcceso(){
  return this->accesos;
}

std::string Pares::getIP(){
  return this->ip;
}