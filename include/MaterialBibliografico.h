#pragma once
#include <iostream>

class MaterialBibliografico {

	private:
		std::string nombre;
		std::string autor;
		std::string isbn;
		int prestado;
	public:
		MaterialBibliografico(std::string nombre, std::string autor, std::string isbn, int prestado);
		std::string getNombre();
		std::string getAutor();
		std::string getIsbn();
		int getPrestado();
		void setNombre(std::string nombre);
		void setAutor(std::string autor);
		void setIsbn(std::string isbn);
		void setPrestado(int prestado);
		virtual std::string mostrarInformacion();
		virtual ~MaterialBibliografico();

};
