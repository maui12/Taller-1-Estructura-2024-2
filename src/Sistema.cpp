#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Sistema.h"


Sistema::Sistema(){
	this-> sizeBiblioteca = 0;
	this-> sizeUsuario = 0;
}

void Sistema::leer() {
	std::string nombreArchivo = "Usuarios.txt";
	std::ifstream archivo(nombreArchivo);

	if (!archivo.is_open()) {
		std::cerr << "Error al abrir archivo: " << nombreArchivo << std::endl;
		return;
	}

	std::string linea;
	int cont = 0;
	while (std::getline(archivo, linea)) {
		std::stringstream ss(linea);
		std::string id, nombre;

		if (std::getline(ss, id, ',') && std::getline(ss, nombre, ',')) {
			Usuario* usuario = new Usuario(nombre, id);
			usuarios[cont] = usuario;
			sizeUsuario++;
			cont++;
		}
	}

	archivo.close();

	nombreArchivo = "MaterialesBibliograficos.txt";

}


void Sistema::agregarMaterialABiblioteca() {
    std::cout << "===== Agregar Material ===== \nSeleccione el tipo de material: \n1)Libro 2)Revista" << std::endl;
    int tipo;
    std::cin >> tipo;

    if (tipo != 1 && tipo != 2) {
        std::cerr << "Dato invalido" << std::endl;
        return;
    }

    std::cout << "-Ingrese nombre del nuevo Material: " << std::endl;
    std::string nombre;
    std::cin >> nombre;

    std::cout << "-Ingrese autor: " << std::endl;
    std::string autor;
    std::cin >> autor;

    std::cout << "-Ingrese isbn: " << std::endl;
    std::string isbn;
    std::cin >> isbn;

    if(sizeBiblioteca != 0) {
		for(int i = 0; i < sizeBiblioteca; i++) {
			if(biblioteca[i]->getIsbn() == isbn) {
				std::cerr << "Este ISBN ya existe" << std::endl;
				return;
			}
		}
    }

    MaterialBibliografico* material = nullptr;

    switch (tipo) {
        case 1: {
            std::cout << "[Libro] Indique la fecha de publicacion: " << std::endl;
            std::string fecha;
            std::cin >> fecha;

            std::cout << "[Libro] Ingrese resumen: " << std::endl;
            std::string resumen;
            std::cin >> resumen;

            material = new Libro(nombre, autor, isbn, 0, fecha, resumen);
            break;
        }
        case 2: {
            std::cout << "[Revista] Ingrese numero de edicion: "<< std::endl;
            std::string num;
            std::cin >> num;

            std::cout << "[Revista] Indique mes de publicacion: " << std::endl;
            std::string mes;
            std::cin >> mes;

            material = new Revista(nombre, autor, isbn, 0, num, mes);
            break;
        }
    }

    if (material == nullptr) {
        std::cerr << "Error: No se pudo crear el material." << std::endl;
        return;
    }

    agregarAListaBiblioteca(material);
    return;
}

void Sistema::mostrarBiblioteca() {
    if(sizeBiblioteca == 0) {
		std::cout << "No hay material bibliografico \n";
        return;
	}
	for(int i = 0 ; i < sizeBiblioteca; i++) {
		std::cout << biblioteca[i]->mostrarInformacion()  + "\n";
	}

}

bool Sistema::buscarMaterial() {
	std::cout << "Ingrese el isbn del material bibliografico: \n";
	std::string isbn;
	std::cin >> isbn;
	for(int i = 0 ; i < sizeBiblioteca ; i++){
		if(biblioteca[i] -> getIsbn() == isbn){
			return true;
		}
		return false;
	}
}

void Sistema::prestarMaterial() {

	if(sizeBiblioteca == 0) {
        std::cerr << "No hay materiales para prestar" << std::endl;
        return;
	}
    std::cout << "Ingrese el isbn del material bibliografico que quieres pedir prestado: \n";
    mostrarBiblioteca();
    std::string isbn;
    std::cin >> isbn;

    std::cout << "Ingrese el ID de la persona que quiere pedir prestado el material bibliografico : \n";
    mostrarUsuarios();
    std::string id;
    std::cin >> id;

    for(int i = 0 ; i < sizeBiblioteca ; i++){
        if(biblioteca[i] -> getIsbn() == isbn){
            biblioteca[i] -> setPrestado(1);
            for(int i = 0 ; i < sizeUsuario ; i++){
                if(usuarios[i]-> getId() == id){
                    usuarios[i]->prestarMaterial(biblioteca[i]);
                    std::cout << "Se ha prestado el material bibliografico de ISBN " + isbn + " con autor del prestamo a ID: "+id+" Nombre: "+usuarios[i]->getNombre() +"\n";
                }
                else{
                    std::cout << "No se ha encontrado el usuario \n";
                    return;
                }
            }
        }
        else{
        std::cout << "No se ha encontrado el material bibliografico con ese isbn: \n";
        }
        return ;
    }

}

void Sistema::devolverMaterial() {

}

void Sistema::agregarUsuario() {
	std::cout << "===== Registrar Nuevo Usuario ===== \n" << std::endl;

	std::cout << "-Ingrese nombre: " << std::endl;
	std::string nombre;
	std::cin >> nombre;

	Usuario* usuario;

	if(sizeUsuario == 0) {
		usuario = new Usuario(nombre,"0");
	}
	else {
		usuario = new Usuario(nombre,std::to_string(std::stoi(usuarios[sizeUsuario - 1]->getId()) + 1));
	}
	agregarAListaUsuarios(usuario);
}

void Sistema::buscarUsuario() {

}

bool Sistema::eliminarUsuario() {
    if (sizeUsuario == 0) {
        std::cout << "No hay usuarios para eliminar.\n";
        return false;
    }

    mostrarUsuarios();

    std::cout << "Ingrese la ID del usuario a eliminar: ";
    std::string id;
    std::cin >> id;

    // buscar usuario por id
    int index = -1;
    for (int i = 0; i < sizeUsuario; i++) {
        if (usuarios[i]->getId() == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cerr << "Usuario con ID " << id << " no encontrado \n";
        return false;
    }

    delete usuarios[index];

    // mover elementos a la izquierda
    for (int i = index; i < sizeUsuario - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }

    sizeUsuario--;
    std::cout << "Usuario eliminado correctamente \n";
    return true;
}

void Sistema::guardarCambios() {

}

bool Sistema::agregarAListaBiblioteca(MaterialBibliografico* material) {
	if (sizeBiblioteca < maxSize) { //verifica que no exceda el tamano del array
		biblioteca[sizeBiblioteca] = material;
	    sizeBiblioteca++;
	    std::cout << "Agregado a la Biblioteca exitosamente \n";
	    return true;
	} else {
	    std::cerr << "La biblioteca esta llena.\n";
	    return false;
	}
	return false;
}

void Sistema::agregarAListaUsuarios(Usuario* usuario) {
	if(sizeUsuario < maxSize) { //verifica que no exceda el tamano del array
		usuarios[sizeUsuario] = usuario;
		sizeUsuario++;
		std::cout << "Usuario registrado correctamente \n";
	}
	else {
		std::cerr << "La lista de Usuarios esta llena.\n";
	}
}

void Sistema::mostrarUsuarios() {
	if(sizeUsuario == 0) {
		std::cout << "No hay usuarios \n";
	}
	for(int i = 0 ; i < sizeUsuario; i++) {
		std::cout << usuarios[i]->toString() + "\n";
	}
}

void Sistema::liberarMemoria() {

}
