#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include "Estudiante.cpp"


using namespace std;




int main(){
	
	string nombre,apellido,direccion;
	int op,codigo,telefono;
	
	cout<<"Crud De Archivos"<<endl;
	cout<<"1.Ver Registros"<<endl;
	cout<<"2.Ingresar Alumnos"<<endl;
	cout<<"3.modificar Alumnos"<<endl;
	cout<<"4.Eliminar Alumnos"<<endl;
	cout<<"5.Salir"<<endl;
	cout<<"Seleccion una opcion"<<endl;
	cin>>op;
	
	
	do
	{
		system("cls");
		cout<<"Crud De Archivos"<<endl;
		cout<<"1.Ver Registros"<<endl;
		cout<<"2.Ingresar Alumnos"<<endl;
		cout<<"3.modificar Alumnos"<<endl;
		cout<<"4.Eliminar Alumnos"<<endl;
		cout<<"5.Salir"<<endl;
		cout<<"Seleccion una opcion"<<endl;
		cin>>op;
		
		
		
		if(op == 1){
			system("cls");
			
			Estudiante Est = Estudiante();
			Est.abrir_estudiante();
	}
	
	if(op == 2){
			system("cls");
			Estudiante Est2 = Estudiante();
			Est2.ingresar_estudiante();
		
	}
	
	if(op == 3){
			system("cls");
			Estudiante Est3 = Estudiante();
			Est3.modificar_estudiante();
		
	}
	
	if(op == 4){
			system("cls");
			Estudiante Est4 = Estudiante();
			Est4.eliminar_estudiante();		
	}
		
		
		
	}while(op != 5);
	

	
}
