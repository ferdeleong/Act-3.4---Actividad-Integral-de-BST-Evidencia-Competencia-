#ifndef _BITACORA_H_
#define _BITACORA_H_


#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include "Registro.h"
#include "MaxHeap.h"
//#include "DLinkedList.h"

class Bitacora {

  private:
    std::vector<Registro> listaRegistros;

    void heapify(int, int);

  public:
    Bitacora();
    Bitacora(std::string fileName);
    ~Bitacora();
    void toFile(std::string);    
    void heapSort();
};



#endif  // _BITACORA_H_