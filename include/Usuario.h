#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Usuario {
	private:
		std::string nombre;
		std::string id;
		MaterialBibliografico* materialesPrestados[5];
		
	public:
		Usuario(std::string nombre, std::string id);
		std::string getNombre();
		std::string getId();
		MaterialBibliografico** getMaterialesPrestados();
		void setNombre(std::string nombre);
		void setId(std::string id);

		void prestarMaterial(MaterialBibliografico* material);
		void devolverMaterial();
		void mostrarMaterialesPrestados();
		MaterialBibliografico**getMaterialesPrestados();

		std::string toString();
};


