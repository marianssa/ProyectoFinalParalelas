#include <iostream>
#include <fstream>
#include <string>
#include  <cmath>
#define PI 3.141592654 
using namespace std;

struct coordenada{
	float latitud;
	float longitud;
};
struct equipo{
	string nombre;
	string estadio;
	coordenada ubicacion;
};

float enRadianes(float valor)
{
	valor= valor* 180/PI;
	return valor;
}
float calcularDistancia(float latitud1;float latitud2; float longitud1;float longitud2)
{
	//Formula Haversine --> Radio ecuatorial = 6378km
	int R = 6378;
	float diferencialat,aux1;
	float diferencialong,aux2;
	float distanciakm;
	float a,c;
	aux1= latitud2 - latitud1;
	aux2 = longitud2-longitud1;
	diferencialat = enRadianes(aux1);
	diferencialong= enRadianes(aux2);
	a = pow(sin(diferencialat/2),2)+ cos(enRadianes(latitud1)* cos(enRadianes(latitud2))*pow(sin(diferencialong/2),2))
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

void llenadomatriz(float matriz[][100],int n)
{
	for(int i = 0; i<n;i++){
		for(int j = 1; j<n;j++){

		}
	}
}
int main()
{
 
 int numero_de_equipos;
 numero_de_equipos=contador_de_lineas("equipos");
 float matrizequipos[numero_de_equipos][numero_de_equipos];

}