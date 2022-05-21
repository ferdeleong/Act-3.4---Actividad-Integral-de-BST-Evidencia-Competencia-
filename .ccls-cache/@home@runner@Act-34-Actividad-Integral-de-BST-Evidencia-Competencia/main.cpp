/*
Nombre y matricula: 
Fernanda De Leon. A01197340
Elena Ballinas García. A01173324

Fecha de creacion: 30 de abril del 2022

código de compilacion: g++ -std=c++11 main.cpp

Compilacion para debug:  
    g++ -std=c++17 -g -o main *.cpp 
Ejecucion con valgrind:
    nix-env -iA nixpkgs.valgrind
    valgrind --leak-check=full ./main
  
*/

/Main
int main () {
  Bitacora miBitacora("bitacoraHeap.txt");
  miBitacora.sortIterativoBitacora("bitacora_ordenada_iterativo.txt");
  miBitacora.buscarFechas("resultado_busqueda.txt");
  return 0;
}
