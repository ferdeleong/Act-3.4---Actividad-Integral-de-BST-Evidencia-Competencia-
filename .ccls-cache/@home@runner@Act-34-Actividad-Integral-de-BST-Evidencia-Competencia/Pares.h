#ifndef __PARES_H_
#define __PARES_H_

#include "Bitacora.h"
#include "MaxHeap.h"
#include <iostream>
#include <string>
#include <vector>

class Pares {
private:
  std::string ip;
  int accesos;
  unsigned int ipValue;

public:
  Pares(std::string ip, int accesos);
  Pares();
  int getAcceso();
  std::string getIP();
  std::string print();
  bool operator==(const Pares &);
  std::string operator+(std::string &);
  bool operator!=(const Pares &);
  bool operator>(const Pares &);
  bool operator<(const Pares &);
  bool operator<=(const Pares &);
  bool operator>=(const Pares &);
};

#endif
