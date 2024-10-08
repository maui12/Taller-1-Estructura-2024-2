#include <iostream>
#include <limits>
#include "../include/Sistema.h"

using namespace std;


bool menu(Sistema* sistema) {

   	int entrada = 0;

   	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return true;
	}

   	cout<<"---------------------------------"<<endl;
   	cout<<":    Gestion de Biblioteca	:"<<endl;
   	cout<<"---------------------------------"<<endl;
   	cout<<"1.- Agregar Material a la Biblioteca"<<endl;
   	cout<<"2.- Mostrar Material disponible"<<endl;
   	cout<<"3.- Buscar Material"<<endl;
   	cout<<"4.- Prestar Material"<<endl;
	cout<<"5.- Devolver material"<<endl;
   	cout<<"6.- Registrar un nuevo Usuario"<<endl;
   	cout<<"7.- Ver Usuarios"<<endl;
   	cout<<"8.- Buscar Usuario"<<endl;
   	cout<<"9.- Eliminar Usuario"<<endl;
   	cout<<"10.- Guardar cambios y salir"<<endl;
   	cout<<"----------------------------------"<<endl;
   	cout<<"-Ingrese una opcion: "<<endl;

   	cin>>entrada;

   	if (cin.fail()) {
		cerr << "Opcion invalida. Ingrese un numero." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return true;
	}


   	switch(entrada) {

   	case 1:
   		sistema->agregarMaterialABiblioteca();
   		break;
   	case 2:
   		sistema->mostrarBiblioteca();
   		break;
   	case 3:
   		sistema->buscarMaterial();
   		break;
   	case 4:
		sistema->prestarMaterial();
   		break;
	case 5:
		sistema -> devolverMaterial();
		break;
   	case 6:
   		sistema->agregarUsuario();
   		break;
   	case 7:
   	   	sistema->mostrarUsuarios();
   	   	break;
   	case 8:
   	   	sistema->buscarUsuario();
   	   	break;
   	case 9:
   	   	sistema->eliminarUsuario();
   	   	break;
   	case 10:
   	   	sistema->guardarCambios();
   	   	return false;
   	default:
   		//cerr<<"Opcion invalida. Ingrese otra opcion "<<endl;
   		break;
   	}
   	return true;
}


int main() {

	Sistema* sistema = new Sistema();
	sistema->leer();

	bool salir = true;

	do {
		salir = menu(sistema);
	}
	while(salir);

	sistema->liberarMemoria();
	delete sistema;

    return 0;
}
