#include <iostream>
#include "../include/Sistema.h"


Sistema::Sistema(){
	this-> sizeBiblioteca = 0;
	this-> sizeUsuario = 0;
}

void Sistema::leer() {

}

bool Sistema::agregarMaterialABiblioteca() {
    std::cout << "===== Agregar Material ===== \nSeleccione el tipo de material: \n1)Libro 2)Revista" << std::endl;
    int tipo;
    std::cin >> tipo;

    if (tipo != 1 && tipo != 2) {
        std::cerr << "Dato invalido" << std::endl;
        return false;
    }

    std::cout << "-Ingrese nombre del nuevo Material: " << std::endl;
    std::string nombre;
    std::cin >> nombre;

    std::cout << "-Ingrese autor: " << std::endl;
    std::string autor;
    std::cin >> autor;

    std::cout << "-Ingrese isbn: " << std::endl;
    std::string isbn;
    std::cin >> isbn;

    MaterialBibliografico* material = nullptr;

    switch (tipo) {
        case 1: {
            std::cout << "[Libro] Indique la fecha de publicacion: " << std::endl;
            std::string fecha;
            std::cin >> fecha;

            std::cout << "[Libro] Ingrese resumen: " << std::endl;
            std::string resumen;
            std::cin >> resumen;

            material = new Libro(nombre, autor, isbn, 0, fecha, resumen);
            break;
        }
        case 2: {
            std::cout << "[Revista] Ingrese numero de edicion: " << std::endl;
            std::string num;
            std::cin >> num;

            std::cout << "[Revista] Indique mes de publicacion: " << std::endl;
            std::string mes;
            std::cin >> mes;

            material = new Revista(nombre, autor, isbn, 0, num, mes);
            break;
        }
    }

    if (material == nullptr) {
        std::cerr << "Error: No se pudo crear el material." << std::endl;
        return false;
    }

    return agregarAListaBiblioteca(material);
}

void Sistema::mostrarBiblioteca() {

}

bool Sistema::buscarMaterial() {

}

void Sistema::prestarMaterial() {

}

void Sistema::devolverMaterial() {

}

bool Sistema::agregarUsuario() {

}

bool Sistema::buscarUsuario() {

}

bool Sistema::eliminarUsuario() {

}

void Sistema::guardarCambios() {

}

bool Sistema::agregarAListaBiblioteca(MaterialBibliografico* material) {
	if (sizeBiblioteca < maxSize) {
		biblioteca[sizeBiblioteca] = material;
	    sizeBiblioteca++;
	    std::cout << "Agregado a la Biblioteca exitosamente \n";
	    return true;
	} else {
	    std::cerr << "La biblioteca esta llena.\n";
	    return false;
	}
	return false;
}
