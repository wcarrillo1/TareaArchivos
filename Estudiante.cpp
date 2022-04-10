#include<iostream>
#include <stdio.h>  
#include <string.h>


using namespace std;
class Estudiante{
	
	private : char nombre[50];
			  char apellido[50];
			  char direccion[50];
			  int codigo, telefono;
			  char *nombre_archivo = "archivo.dat";
			  
			  
	
	public :
		Estudiante(){
		}
		Estudiante(char nom[50], char ape[50], char dir[50], int cod, int tel){
			nombre[50] = nom[50];
			apellido[50] = ape[50];
			direccion[50]= dir[50];
			codigo = cod;
			telefono = tel;
			
		}
		


	void abrir_estudiante(){
	
	
	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombre_archivo, "w+b");
		cout<<"Archivo Creado exitosamente";
		system("pause");
	};
	
	Estudiante estudiante;
	
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"TELEFONO"<<" "<<"DIRECCION"<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" "<<estudiante.telefono<<" "<<estudiante.direccion<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
         cout<<endl;
    
		fclose(archivo);
		system("pause");
	}
	
	
	void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombre_archivo, "ab"); // ab
	
	
		Estudiante estudiante;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();
}

void modificar_estudiante(){
	
	FILE* archivo = fopen(nombre_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	Estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
}

void eliminar_estudiante(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	Estudiante estudiante;
	FILE* archivo = fopen(nombre_archivo, "rb");
	FILE* archivo_temp=fopen(nombre_archivo_temp,"w+b");
	int id=0,i=0;
		cout<<"ingrese el id a eliminar:"; 
	cin>>id; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
			
			if (i != id){
				fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
			} 
			
			i++; 
		}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	                
		archivo_temp=fopen(nombre_archivo_temp,"rb"); 
		archivo=fopen(nombre_archivo,"wb"); 
	 
		while(fread(&estudiante,sizeof(Estudiante),1, archivo_temp)){ 
			fwrite(&estudiante,sizeof(Estudiante),1, archivo); 
		}
	                
	fclose(archivo_temp); 
	fclose(archivo); 
	abrir_estudiante();
		system("PAUSE");
}

	
	
};
