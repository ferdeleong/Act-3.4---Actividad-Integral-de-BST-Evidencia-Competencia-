#include "Bitacora.h"

Bitacora::Bitacora() {}

Bitacora::Bitacora(std::string fileName) {
  std::string month, day, hours, minutes, seconds, ipAdd, port, error;
  std::ifstream file(fileName);
  if (!file.good()) {
    file.close();
    throw std::invalid_argument("File not found");
  } else {
    while (!file.eof()) {
      std::getline(file, month, ' ');
      std::getline(file, day, ' ');
      std::getline(file, hours, ':');
      std::getline(file, minutes, ':');
      std::getline(file, seconds, ' ');
      std::getline(file, ipAdd, ':');
      std::getline(file, port, ' ');
      std::getline(file, error);
      Registro tmpRegistro(month, day, hours, minutes, seconds, ipAdd, port,
                           error);
      listaRegistros.push_back(tmpRegistro);
    }
    file.close();
  }
}

Bitacora::~Bitacora() {
  listaRegistros.clear();
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void Bitacora::heapify(int n, int i) {

// Initialize largest as root
	int largest = i;

// left = 2*i + 1
	int l = 2 * i + 1;

// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < n && listaRegistros[l] > listaRegistros[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (r < n && listaRegistros[r] > listaRegistros[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		std::swap(listaRegistros[i], listaRegistros[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(n, largest);
	}
}

// Main function to do heap sort
void Bitacora::heapSort() {
  int n = listaRegistros.size();
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(n, i);

	// One by one extract an element
	// from heap
	for (int i = n - 1; i > 0; i--) {
	
		// Move current root to end
		std::swap(listaRegistros[0], listaRegistros[i]);

		// call max heapify on the reduced heap
		heapify(i, 0);
	}
}


void Bitacora::toFile(std::string outFile) {
  std::ofstream resultados;
  resultados.open(outFile);
  if (!resultados.good()) 
    return;
  for (int i = 0; i < (int)listaRegistros.size(); i++) {
    resultados << listaRegistros[i].getAll() << std::endl;
  }
  resultados.close();
}



/*
 - Contar repeticiones de cada IP 
 - Por cada IP distinta creas un objeto Pares (IP, repeticiones)
 - Insertar ese objeto en u

*/