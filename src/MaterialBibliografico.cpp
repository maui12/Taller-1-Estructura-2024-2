#include <iostream>
#include "../include/MaterialBibliografico.h"


MaterialBibliografico::MaterialBibliografico(std::string nombre, std::string autor, std::string isbn, int prestado) {
	this -> nombre = nombre;
	this -> autor = autor;
	this -> isbn = isbn;
	this -> prestado = prestado;
}

std::string MaterialBibliografico::getNombre() {
	return nombre;
}

std::string MaterialBibliografico::getAutor() {
	return autor;
}

std::string MaterialBibliografico::getIsbn() {
	return isbn;
}

int MaterialBibliografico::getPrestado() {
	return prestado;
}

void MaterialBibliografico::setNombre(std::string nombre) {
	this ->nombre = nombre;
}

void MaterialBibliografico::setAutor(std::string autor) {
	this ->autor = autor;
}

void MaterialBibliografico::setIsbn(std::string isbn) {
	this ->isbn = isbn;
}

void MaterialBibliografico::setPrestado(int prestado) {
	this ->prestado = prestado;
}

std::string MaterialBibliografico::	getTipoMaterial() {
	return tipoMaterial;
}

std::string MaterialBibliografico::mostrarInformacion() {
	return "";
}

MaterialBibliografico::~MaterialBibliografico() {

}




