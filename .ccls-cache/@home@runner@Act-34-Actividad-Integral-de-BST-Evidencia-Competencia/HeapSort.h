#ifndef __HEAPSORT_H_
#define __HEAPSORT_H_

// C++ program for implementation of Heap Sort
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
datos Complejidad: O(1)
*/
template <class T> bool MaxHeap<T>::empty() { return (actualSize <= 0); }

template <class T> void MaxHeap<T>::printMaxHeap() {
  for (int i = 0; i < actualSize; i++)
    std::cout << data[i] << " ";
  std::cout << std::endl;
}

template <class T> int MaxHeap<T>::parent(int i) { return (i - 1) / 2; }

template <class T> int MaxHeap<T>::left(int i) { return (2 * i + 1); }

template <class T> int MaxHeap<T>::right(int i) { return (2 * i + 2); }

/*
Complejidad: O(1)
*/
template <class T> T MaxHeap<T>::top() { return data[0]; }

/*
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
  // Reparar las propiedades del max heap si son violadas
  while (i != 0 && data[parent(i)] < data[i]) {
    std::swap(data[i], data[parent(i)]);
    i = parent(i);
  }
}

/*
Complejidad: O(nlogn)
*/

template <class T> void MaxHeap<T>::pop() {
  if (actualSize == 1) {
    throw std::out_of_range("La fila priorizada necesita al menos 1 dato, no "
                            "se pueden eliminar mas valores");
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
Complejidad: O(1)
*/
template <class T> int MaxHeap<T>::size() { return actualSize; }

 
// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int n, int i)
{
   
  // Initialize largest as root
    int largest = i;
   
  // left = 2*i + 1
    int l = 2 * i + 1;
   
  // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, n, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int n)
{
   
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element
    // from heap
    for (int i = n - 1; i > 0; i--) {
       
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}



#endif // __HEAPSORT_H_