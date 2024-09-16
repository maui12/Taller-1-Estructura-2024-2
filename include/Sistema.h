#pragma once
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include <iostream>

class Sistema {
	private:
		static const int maxSize = 100;
		int sizeBiblioteca;
		int sizeUsuario;
		MaterialBibliografico* biblioteca[maxSize];
		Usuario* usuarios[maxSize];
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

		bool agregarAListaBiblioteca(MaterialBibliografico* material);

};
