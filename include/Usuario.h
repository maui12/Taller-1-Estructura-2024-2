#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Usuario {
	private:
		std::string nombre;
		std::string id;
		MaterialBibliografico* materialesPrestados[5];
		int sizeMaterialesPrestados;
		
	public:
		Usuario(std::string nombre, std::string id);
		std::string getNombre();
		std::string getId();
		int getSizeMaterialesPrestados();
		void setSizeMaterialesPrestados(int sizeMaterialesPrestados);
		void setNombre(std::string nombre);
		void setId(std::string id);

		void prestarMaterial(MaterialBibliografico* material);
		void devolverMaterial();
		void mostrarMaterialesPrestados();
		MaterialBibliografico** getMaterialesPrestados();

		std::string toString();
		~Usuario();
};


