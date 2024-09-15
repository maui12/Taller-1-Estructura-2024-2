#include <iostream>
#include "../include/MaterialBibliografico.h"
#include "../include/Libro.h"

Libro::Libro(std::string nombre, std::string autor, std::string isbn, int prestado, std::string fechaPublicacion, std::string resumen): MaterialBibliografico(nombre, autor, isbn, prestado) {
	this -> fechaPublicacion = fechaPublicacion;
	this -> resumen = resumen;
}

std::string Libro::getFechaPublicacion() {
	return fechaPublicacion;
}

std::string Libro::getResumen() {
	return resumen;
}

void Libro::setFechaPublicacion(std::string fechaPublicacion) {
	this -> fechaPublicacion = fechaPublicacion;
}

void Libro::setResumen(std::string resumen) {
	this -> resumen = resumen;
}

std::string Libro::mostrarInformacion() {
	return "";
}

Libro::~Libro() {

}
