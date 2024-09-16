#pragma once
#include "MaterialBibliografico.h"
#include "Usuario.h"
#include <iostream>

class Sistema {
	private:
		MaterialBibliografico* biblioteca[100];
		Usuario* usuarios[100];
	public:
		Sistema();
		void leer();

		bool agregarMaterialABiblioteca();
		void mostrarBiblioteca();
		bool buscarMaterial();
		void prestarMaterial();
		void devolverMaterial();

		bool agregarUsuario();
		bool buscarUsuario();
		bool eliminarUsuario();

		void guardarCambios();

};
