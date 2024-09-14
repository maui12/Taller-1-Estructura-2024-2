#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Usuario {
	public:
		std::string nombre;
		std::string id;
		MaterialBibliografico* materialesPrestados[5];
	private:
		Usuario(std::string nombre, std::string id);
		std::string getNombre();
		std::string getId();
		void setNombre(std::string nombre);
		void setId(std::string id);

		void prestarMaterial();
		void devolverMaterial();
		void mostrarMaterialesPrestados();
};


