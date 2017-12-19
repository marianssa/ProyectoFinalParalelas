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

using namespace std;

float enRadianes(float valor)
{
	double PI = 4.0*atan(1.0);
	valor= valor* (PI/180);
	return valor;
}
double calcularDistancia(double lat1,double lat2,double long1,double long2){       
        double PI = 4.0*atan(1.0);
        
        //Formula Haversine --> Radio ecuatorial = 6378km
        double dlat1=lat1*(PI/180);

        double dlong1=long1*(PI/180);
        double dlat2=lat2*(PI/180);
        double dlong2=long2*(PI/180);

        double dLong=dlong1-dlong2;
        double dLat=dlat1-dlat2;

        double aHarv= pow(sin(dLat/2.0),2.0)+cos(dlat1)*cos(dlat2)*pow(sin(dLong/2),2);
        double cHarv=2*atan2(sqrt(aHarv),sqrt(1.0-aHarv));
 
        const double earth=6378;
        double distancia=earth*cHarv;

        return distancia;
}

typedef struct nodo
{
	int num_equipos;
	string nombre_equipo;
	string nombre_estadio;
	double latitud;
	double longitud;
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
         double aux3;
         ss>>aux3;
         p->latitud=aux3;
         // Descartamos el caracter ';' a continuacion del dato
         char ch;
         ss >> ch;
         
         // Obtenemos la longitud, esta es el resto de la linea
         double aux4;
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
