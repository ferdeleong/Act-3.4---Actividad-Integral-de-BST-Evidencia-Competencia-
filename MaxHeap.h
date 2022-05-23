#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include <iostream>
#include <stdexcept>
#include <vector>

template <class T> class MaxHeap {
private:
  // contiene los elementos del heap
  std::vector<T> data;
  // capacidad maxima del heap
  int maxSize;
  // tamaño actual del heap
  int actualSize;
  int parent(int i);
  int left(int i);
  int right(int i);

public:
  MaxHeap(int capacity);
  ~MaxHeap();
  bool empty();
  int getCapacity();
  void printMaxHeap();
  void push(T key);
  T top();
  void pop();
  int size();
};

template <class T> MaxHeap<T>::MaxHeap(int capacity) {
  std::cout << "--->Creando un MaxHeap: " << this << std::endl;
  actualSize = 0;
  maxSize = capacity;
  data.resize(maxSize);
}

template <class T> MaxHeap<T>::~MaxHeap() {
  std::cout << "--->Liberando memoria del MaxHeap: " << this << std::endl;
  data.clear();
}

/*
Salida: Un valor booleano que diga si la fila priorizada está vacía o tiene
datos Complejidad: O(1)
*/
template <class T> bool MaxHeap<T>::empty() { return (actualSize <= 0); }

template <class T> int MaxHeap<T>::getCapacity() { return maxSize; }

template <class T> void MaxHeap<T>::printMaxHeap() {
  for (int i = 0; i < actualSize; i++)
    std::cout << data[i] << " ";
  std::cout << std::endl;
}

template <class T> int MaxHeap<T>::parent(int i) { return (i - 1) / 2; }

template <class T> int MaxHeap<T>::left(int i) { return (2 * i + 1); }

template <class T> int MaxHeap<T>::right(int i) { return (2 * i + 2); }

/*
Salida: El dato que tiene mayor prioridad dentro de la fila priorizada
Complejidad: O(1)
*/

template <class T> T MaxHeap<T>::top() { return data[0]; }

/*
Salida: Nada
Complejidad: O(nlogn)
*/
template <class T> void MaxHeap<T>::push(T key) {
  if (actualSize == maxSize) {
    throw std::out_of_range("Overflow: no se puede insertar la llave: " + key);
  }
  // Insertamos la nueva llave al final del vector
  int i = actualSize;
  data[i] = key;
  actualSize++;
  // Reparar las propiedades del max heap
  while (i != 0 && data[parent(i)] < data[i]) {
    std::swap(data[i], data[parent(i)]);
    i = parent(i);
  }
}

/*
Salida: Nada
Complejidad: O(nlogn)
Referencias: https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/
*/

template <class T> void MaxHeap<T>::pop() {
  if (actualSize == 0) {
    return;
  }
  int i = 0, j;
  data[i] = data[--actualSize];
  while (true) {
    j = i;
    if (data[left(i)] > data[i]) j = left(i);
    if (data[right(i)] > data[j]) j = right(i);
    if (data[j] > data[i]) {
      std::swap(data[i], data[j]);
      i = j;
    } else {
      break;
    }
  }
}

/*
Salida: Un valor entero que representa la cantidad de datos de la fila
priorizada Complejidad: O(1)
*/
template <class T> int MaxHeap<T>::size() { return actualSize; }

#endif // __MAXHEAP_H_