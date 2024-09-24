#pragma once
#include <iostream>
#include "MaterialBibliografico.h"

class Libro:public MaterialBibliografico {
	private:
		std::string fechaPublicacion;
		std::string resumen;

	public:
		Libro(std::string nombre, std::string autor, std::string isbn, int prestado, std::string fechaPublicacion, std::string resumen);
		std::string getFechaPublicacion();
		std::string getResumen();
		void setFechaPublicacion(std::string fechaPublicacion);
		void setResumen(std::string resumen);
		std::string mostrarInformacion();
	    std::string guardarInformacion() const override;
		~Libro();
};
