#include <iostream>
#include "../include/MaterialBibliografico.h"
#include "../include/Revista.h"

Revista::Revista(std::string nombre, std::string autor, std::string isbn, int prestado, std::string numeroEdicion, std::string mesPublicacion): MaterialBibliografico(nombre, autor, isbn, prestado) {
	this -> numeroEdicion = numeroEdicion;
	this -> mesPublicacion = mesPublicacion;
}

std::string Revista::getNumeroEdicion() {
	return numeroEdicion;
}

std::string Revista::getMesPublicacion() {
	return mesPublicacion;
}

void Revista::setNumeroEdicion(std::string numeroEdicion) {
	this -> numeroEdicion = numeroEdicion;
}

void Revista::setMesPublicacion(std::string mesPublicacion) {
	this -> mesPublicacion = mesPublicacion;
}

std::string Revista::mostrarInformacion() {
	if(prestado == 0) {
		return "[ Revista: ISBN = "+isbn+" Nombre = "+nombre+" Autor = "+autor+" Prestado = Prestado = NO ]\n"+"-N° edicion = "+numeroEdicion+"\n-Mes de publicacion = "+mesPublicacion+"\n";

	}
	else if(prestado == 1) {
		return "[ Revista: ISBN = "+isbn+" Nombre = "+nombre+" Autor = "+autor+" Prestado = Prestado = SI ]\n"+"-N° edicion = "+numeroEdicion+"\n-Mes de publicacion = "+mesPublicacion+"\n";

	}
	return "[ Revista: ISBN = "+isbn+" Nombre = "+nombre+" Autor = "+autor+" Prestado = "+std::to_string(prestado)+" ]\n"+"-N° edicion = "+numeroEdicion+"\n-Mes de publicacion = "+mesPublicacion+"\n";
}

std::string Revista::guardarInformacion() const {
    return "Revista," + isbn + "," + nombre + "," + autor + "," + numeroEdicion + "," + mesPublicacion + "," + std::to_string(prestado) + "\n";
}

Revista::~Revista() {
	std::cout<<"Se elimino Revista " + nombre <<std::endl;
}
