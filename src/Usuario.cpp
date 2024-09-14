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

void Usuario::prestarMaterial() {

}

void Usuario::devolverMaterial() {

}

void Usuario::mostrarMaterialesPrestados() {

}
