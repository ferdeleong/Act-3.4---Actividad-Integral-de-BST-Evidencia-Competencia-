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

int main() {
  Bitacora miBitacora("bitacoraHeap.txt");
  miBitacora.heapSort();
  miBitacora.toFile("bitacora_ordenada.txt");
  // miBitacora.createMaxHeap();

  return 0;
}

/*
Referencias:
-https://www.geeksforgeeks.org/heap-sort/

-https://stackoverflow.com/questions/39906504/how-to-count-duplicates-in-a-vector-c
*/