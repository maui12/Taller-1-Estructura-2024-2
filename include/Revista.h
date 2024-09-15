#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Revista: public MaterialBibliografico {
	public:
		std::string numeroEdicion;
		std::string mesPublicacion;

	private:
		Revista(std::string nombre, std::string autor, std::string isbn, int prestado, std::string numeroEdicion, std::string mesPublicacion);
		std::string getNumeroEdicion();
		std::string getMesPublicacion();
		void setNumeroEdicion(std::string numeroEdicion);
		void setMesPublicacion(std::string mesPublicacion);
		std::string mostrarInformacion();
		~Revista();


};
