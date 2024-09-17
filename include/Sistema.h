#pragma once
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include <iostream>

class Sistema {
	private:
		static const int maxSize = 100;

		int sizeBiblioteca; //tamano actual del array biblioteca
		int sizeUsuario; //tamano actual del array usuario

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

		void agregarUsuario();
		void buscarUsuario();
		bool eliminarUsuario();

		void guardarCambios();

		bool agregarAListaBiblioteca(MaterialBibliografico* material);
		void agregarAListaUsuarios(Usuario* usuario);
		void mostrarUsuarios();

};
