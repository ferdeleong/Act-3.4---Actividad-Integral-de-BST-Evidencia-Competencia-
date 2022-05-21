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
      // Crear un objeto de la clase Registro
      Registro tmpRegistro(month, day, hours, minutes, seconds, ipAdd, port,
                           error);
      // Agregar a la lista ligada de registros
      listaRegistros.addLast(tmpRegistro);
    }
    file.close();
  }
}