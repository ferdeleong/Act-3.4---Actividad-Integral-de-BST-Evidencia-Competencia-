#include "Bitacora.h"
#include "Registro.h"
#include <fstream>
/*
Nombre y matricula: 
Fernanda De Leon. A01197340
Elena Ballinas García. A01173324

Fecha de creacion: 22 de mayo del 2022

código de compilacion: g++ -std=c++11 main.cpp

Compilacion para debug:  
    g++ -std=c++17 -g -o main *.cpp 
Ejecucion con valgrind:
    nix-env -iA nixpkgs.valgrind
    valgrind --leak-check=full ./main
  
*/

int main () {
  Bitacora miBitacora("bitacoraShort.txt");
  miBitacora.toFile("bitacora_ordenada.txt");
  return 0;
}

// bitacora_ordenada.txt
