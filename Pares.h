#ifndef __PARES_H_
#define __PARES_H_

#include <iostream>
#include <vector>
#include "Bitacora.h"
#include "MaxHeap.h"

class Pares{
  private: 
    std::string ip; 
    int accesos;
  public: 
    Pares(std::string ip, int accesos);
    int getAcceso();
    std::string getIP();

};

#endif
