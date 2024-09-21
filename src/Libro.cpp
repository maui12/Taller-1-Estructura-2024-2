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
	if(prestado == 0) {
		return "[ Libro: ISBN = "+isbn+" Nombre = "+nombre+" Autor = "+autor+" Prestado = NO ]\n"+"-Resumen = "+resumen+"\n-Fecha de publicacion = "+fechaPublicacion+"\n";
	}
	else if(prestado = 1) {
		return "[ Libro: ISBN = "+isbn+" Nombre = "+nombre+" Autor = "+autor+" Prestado = SI ]\n"+"-Resumen = "+resumen+"\n-Fecha de publicacion = "+fechaPublicacion+"\n";
	}
	return "[ Libro: ISBN = "+isbn+" Nombre = "+nombre+" Autor = "+autor+" Prestado = "+std::to_string(prestado)+" ]\n"+"-Resumen = "+resumen+"\n-Fecha de publicacion = "+fechaPublicacion+"\n";
}

Libro::~Libro() {

}
