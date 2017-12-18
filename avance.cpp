#include <iostream>
#include <fstream>
#include <string>
#include  <cmath>
#define PI 3.141592654 
using namespace std;
#include <sstream>
using std::stringstream;
struct match{
	string visita;
	string local;
	string fecha;
};
struct nodo
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
	lista p = NULL;
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

void guardar(string fichero,lista &l)
{	
	lista p;
	l= NULL;
	int contador;
	contador=0;
	fstream is;
	is.open(fichero+".csv");
   
   
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

float enRadianes(float valor)
{
	valor= valor* 180/PI;
	return valor;
}
float calcularDistancia(float latitud1,float latitud2,float longitud1,float longitud2)
{
	//Formula Haversine --> Radio ecuatorial = 6378km
	int R = 6378;
	float diferencialat,aux1;
	float diferencialong,aux2;
	float distancia;
	float a,c;
	aux1= latitud2 - latitud1;
	aux2 = longitud2-longitud1;
	diferencialat = enRadianes(aux1);
	diferencialong= enRadianes(aux2);
	a = pow(sin(diferencialat/2),2)+ cos(enRadianes(latitud1)* cos(enRadianes(latitud2))*pow(sin(diferencialong/2),2));
	c= 2 * atan2(sqrt(a),sqrt(1-a));
	distancia = R * c;

	return distancia;
}

int contadorlineas(string mifichero)
{
	fstream miarchivo;
	miarchivo.open(mifichero+".csv");
   	std::size_t contador_de_lineas =0;
   	std::string linea;
   	while (std::getline(miarchivo , linea))
        ++contador_de_lineas;

    return contador_de_lineas;
}

/*void llenadomatriz(float matriz[][100],int n)
{
	for(int i = 0; i<n;i++)
	{
		for(int j = 0; j<n;j++)
		{
			if(i==j)
				matriz[i][j]=0;	
			else
			{
				matriz[i][j]=calcularDistancia()
			}
		}
	}
}*/


int main()
{
	 lista l;
	 int numero_de_equipos;
	 numero_de_equipos=contadorlineas("datos");
	 guardar("datos",l);
	 float matrizequipos[numero_de_equipos][numero_de_equipos];
	 mostrar(l);
	 cout<<numero_de_equipos;
	 
}
