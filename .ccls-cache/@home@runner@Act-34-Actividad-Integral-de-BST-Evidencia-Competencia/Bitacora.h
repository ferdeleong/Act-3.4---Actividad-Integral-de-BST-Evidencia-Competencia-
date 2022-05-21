#ifndef _BITACORA_H_
#define _BITACORA_H_


#include <fstream>
#include <stdexcept>
#include <string>
#include "Registro.h"
#include "DLinkedList.h"

class Bitacora {

  private:
    //std::vector<Registro> listaRegistros;
    DLinkedList<Registro> listaRegistros;

  public:
    Bitacora();
    Bitacora(std::string fileName);
};



#endif  // _BITACORA_H_