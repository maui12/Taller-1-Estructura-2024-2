#include <iostream>
#include "../include/MaterialBibliografico.h"
#include "../include/Usuario.h"

Usuario::Usuario(std::string nombre, std::string id) {
	this-> nombre = nombre;
	this-> id = id;
}

std::string Usuario::getNombre() {
	return nombre;
}

std::string Usuario::getId() {
	return id;
}

void Usuario::setNombre(std::string nombre) {
	this -> nombre = nombre;
}

void Usuario::setId(std::string id) {
	this -> id = id;
}

void Usuario::prestarMaterial(MaterialBibliografico* material) {
	for(int i = 0 ; i < 5 ; i++){
		if(materialesPrestados[i] == nullptr){
			materialesPrestados[i] = material;
			return;
		}
	}
	std::cout << "tiene el maximo numero de materiales prestados" + "\n";
	return;
}

void Usuario::devolverMaterial() {

}

void Usuario::mostrarMaterialesPrestados() {

}

std::string Usuario::toString() {
	return "[ ID = "+id+"  Nombre = "+nombre+" ]";
}
