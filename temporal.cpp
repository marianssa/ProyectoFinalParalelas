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
#include  <cmath>
#define PI 3.141592654 

using namespace std;

float enRadianes(float valor)
{
	valor= valor* 180/PI;
	return valor;
}
float calcularDistancia(float latitud1,float latitud2, float longitud1,float longitud2)
{
	//Formula Haversine --> Radio ecuatorial = 6378km
	int R = 6378;
	float distancia;
	float diferencialat,aux1;
	float diferencialong,aux2;
	float a,c;
	aux1= latitud2 - latitud1;
	aux2 = longitud2-longitud1;
	diferencialat = enRadianes(aux1);
	diferencialong= enRadianes(aux2);
	/*a = pow(sin(diferencialat/2),2)+ cos(enRadianes(latitud1)* cos(enRadianes(latitud2))*pow(sin(diferencialong/2),2));
	c= 2 * atan2(sqrt(a),sqrt(1-a));*/
	c=2*R;
	a=asin(sqrt((pow(sin(enRadianes(diferencialat/2)),2))+((cos(enRadianes(latitud1)))*(cos(enRadianes(latitud2)))*(pow(sin(enRadianes(diferencialong/2)),2)))));//encontre esta otra forma de hacerla..pero tampoco arroja bien los resultados
	//distancia = R * c;
	distancia=c*a;
	cout<<"el valor es "<<distancia<<endl;

	return distancia;
}

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



int main()
{	lista l;
	lista p;
	l=NULL;
	int contador;
	contador=0;
   ifstream is("datos.cvs");
   
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

	float distancias[contador][contador];
	lista t;
	lista q;
	t=l;
	while(t!=NULL)
	{
		q=l;
		while(q!=NULL)
		{
			if(t->num_equipos==q->num_equipos)
			{
				distancias[t->num_equipos][q->num_equipos]=0;
			}
			else
			{
				distancias[t->num_equipos][q->num_equipos]= calcularDistancia(t->latitud,q->latitud,t->longitud,q->longitud);
			}
		q=q->link;
		}
	t=t->link;
	}


   	for(int i=0;i<contador;i=i+1)
	{
		for(int j=0;j<contador;j=j+1)
		{
			cout<<distancias[i][j]<<endl;
		}

	}
   return 0;
}
