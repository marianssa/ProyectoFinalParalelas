#include <iostream>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;
using std::getline;

#include <sstream>
using std::stringstream;

using namespace std;
typedef struct nodo
{
	int num_equipos;
	string nombre_equipo;
	string nombre_estadio;
	float latitud;
	float longitud;
	struct nodo*link;
};
typedef nodo*lista;

void mostrar(lista l)//se puede modificar esta funcion para recorrer la lista tambien
{
	lista p;
	p=l;
	while(p!=NULL)
	{	
		
		cout<<"numero de equipo "<<p->num_equipos+1<<endl;
		cout<<"nombre de equipo "<<p->nombre_equipo<<endl;
		cout<<"nombre de estadio "<<p->nombre_estadio<<endl;
		cout<<"latitud "<<p->latitud<<endl;
		cout<<"longitud "<<p->longitud<<endl;
		p=p->link;
		cout<<endl;
	}
}

void guardar(string fichero)
{	lista l;
	lista p;
	l=NULL;
	int contador;
	contador=0;
   ifstream is(fichero +".cvs");
   
   if (is){
      string linea;
      
      // Mientras se pueda leer una linea del archivo ...
      while (getline(is, linea)){
         stringstream ss(linea);
		p=new(nodo);
		p->num_equipos=contador;

         // Obtenemos el nombre del equipo
         string aux;
         getline(ss,aux, ';');
         p->nombre_equipo=aux;
         
         // Obtenemos el nombre del estadio y descartamos el ';'
         string aux2;
         getline(ss, aux2, ';');
         p->nombre_estadio=aux2;

         
         // Obtenemos la longitud y descartamos el ';'
         float aux3;
         ss>>aux3;
         p->latitud=aux3;
         // Descartamos el caracter ';' a continuacion del dato
         char ch;
         ss >> ch;
         
         // Obtenemos la longitud, esta es el resto de la linea
         float aux4;
         ss>>aux4;
         p->longitud=aux4;
	 p->link=l;
	 l=p;
	 contador=contador+1;
         
      }
      
      is.close();
   }
}