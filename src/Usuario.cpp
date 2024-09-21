#include <iostream>
#include "../include/MaterialBibliografico.h"
#include "../include/Usuario.h"

Usuario::Usuario(std::string nombre, std::string id) {
	this-> nombre = nombre;
	this-> id = id;
	this-> sizeMaterialesPrestados = 0;
	for(int i = 0; i<5;i++) {
		materialesPrestados[i] = nullptr;
	}
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
			sizeMaterialesPrestados++;
			return;
		}
	}
	std::cout << "Tiene el maximo numero de materiales prestados" << std::endl;
	return;
}

void Usuario::devolverMaterial() {

}

void Usuario::mostrarMaterialesPrestados() {
	for(int i = 0; i < sizeMaterialesPrestados; i++){
		std::cout << materialesPrestados[i] -> mostrarInformacion() + " \n";
	}
	return;

}

std::string Usuario::toString() {
	return "[ ID = "+id+"  Nombre = "+nombre+" ]";
}

MaterialBibliografico** Usuario::getMaterialesPrestados() {
    return materialesPrestados;
}

int Usuario::getSizeMaterialesPrestados() {
	return sizeMaterialesPrestados;
}

void Usuario::setSizeMaterialesPrestados(int sizeMaterialesPrestados) {
	this->sizeMaterialesPrestados = sizeMaterialesPrestados;
}

Usuario::~Usuario() {
    for (int i = 0; i < 5; i++) {
        if (materialesPrestados[i] != nullptr) {
            materialesPrestados[i]->setPrestado(0);
            materialesPrestados[i] = nullptr;
        }
    }
}
