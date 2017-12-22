#include <iostream>
#include "xlsxwriter.h"
#include <fstream>
#include <string>
#include "mpi.h"
#include  <cmath>
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

void mostrarlista(lista l)//se puede modificar esta funcion para recorrer la lista tambien
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

void mostrarMatriz(float **matriz,int numero_de_equipos){
	for(int i = 0; i<numero_de_equipos;i++)
	{
		cout<<endl;
		for(int j = 0; j<numero_de_equipos;j++)
		{
			cout<<matriz[i][j];
			if(j<numero_de_equipos-1)
				cout<<" - ";
		}
		cout<< endl;
	}
}

void guardar(string fichero,lista &l)
{   
	lista p;
	l= NULL;
	int contador;
	contador=0;
	fstream is;
	is.open("datos.csv");


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


int contadorlineas(string mifichero)
{
	fstream miarchivo;
	miarchivo.open("datos.csv");
	std::size_t contador_de_lineas =0;
	std::string linea;
	while (std::getline(miarchivo , linea))
		++contador_de_lineas;

	return contador_de_lineas;
}

void llenadomatriz(float **matriz,lista l,int n)
{

	lista q,t;
	t=l;

	float latitud1,
	latitud2,
	longitud1,
	longitud2;

	while(t!=NULL)
	{
		q=l;
		while(q!=NULL)
		{
			if(t->num_equipos==q->num_equipos)
			{
				matriz[t->num_equipos][q->num_equipos]=0;
			}
			else
			{
				matriz[t->num_equipos][q->num_equipos]= calcularDistancia(t->latitud,q->latitud,t->longitud,q->longitud);
			}
			q=q->link;
		}
		t=t->link;
	}

}
string nombre_equipo (lista l, int pos)
{
	lista p;
	p=l;
	while(p!=NULL)
	{   

		if(p->num_equipos+1==pos)
		{
			return p->nombre_equipo;
		}
		p=p->link;
	}
}

bool escribir_en_excel(lista l, int fila, int columna, int contador_filas[], int n)
{
	string nombreVisita;
    string nombreLocal;
	lxw_workbook  *workbook  = workbook_new("Datos_partidos.xlsx");
	lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
	int row ;
	int col ;
	char nombreequipolocal[200];
	char nombreequipovisita[200];
	nombreLocal=nombre_equipo(l, fila);
	nombreVisita=nombre_equipo(l, columna);
	strcpy(nombreequipolocal,nombreLocal.c_str());
	strcpy(nombreequipovisita,nombreVisita.c_str());
	worksheet_write_string  (worksheet, ( ( ( (n/2) + 1 ) * fila ) + contador_filas[fila -1] ) , 0,    nombreequipolocal, NULL);
	worksheet_write_string (worksheet, ( ( ( (n/2) + 1 ) * fila ) + contador_filas[fila -1] ) , 1, nombreequipovisita, NULL);
	contador_filas[fila -1]++;
	return workbook_close(workbook);
}

int main(int argc, char* argv[])
{
	int rank, tamano, status, status1, status2;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &tamano);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status rec_stat;
	lista l;
	int numero_equipos;
	numero_equipos=contadorlineas("datos");
	guardar("datos",l);
	float matrizequipos[numero_equipos][numero_equipos];
	mostrarlista(l);
	cout << endl;
	lxw_workbook  *workbook  = workbook_new("Datos_partidos.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    int row = 0;
    int col = 0;
    lxw_format *bold = workbook_add_format(workbook);
    format_set_bold(bold);
	for (int e=0;e<(2*(numero_equipos-1));e++)
	{
		  char auxiliar[100];
        sprintf(auxiliar,"%d",e+1);
        char auxiliar2[100]="Fecha: ";
        strcat(auxiliar2,auxiliar);
        worksheet_write_string(worksheet, ( ( (numero_equipos/2) + 1 ) * e ) , 0, auxiliar2, bold);
	}
return workbook_close(workbook);
    /*lxw_workbook  *workbook  = workbook_new("Datos_partidos.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    int row = 0;
    int col = 0;
    lxw_format *bold = workbook_add_format(workbook);
    format_set_bold(bold);
    */


    //puntero de punteros para problema de envio de matriz con tamaño dinamico
	float *array[numero_equipos];
	for(size_t w=0;w<numero_equipos; w++){
		array[w]=matrizequipos[w];
	}


	llenadomatriz(array,l,numero_equipos);
	mostrarMatriz(array, numero_equipos);






// matriz equipos =>    int distancias_original[numero_equipos][numero_equipos];//matriz de distancias original, que no cambia
    float distancias[numero_equipos][numero_equipos];//matriz de distancias, cambia con los calculos de fechas

    //llenar con 0
    for(int i = 0; i<numero_equipos;i++)
    {
    	cout<<endl;
    	for(int j = 0; j<numero_equipos;j++)
    	{
    		distancias[i][j]=0;
    	}
    }

    //termina llenado matriz
    for(int i = 0; i<numero_equipos;i++)
    {
    	for(int j = 0; j<numero_equipos;j++)
    	{
    		if(i!=j)
    			if (matrizequipos[j][i]!=0)
    			{
    				distancias[i][j]= matrizequipos[j][i];
    				distancias[j][i]= matrizequipos[j][i];
    			}
    		}
    	}



    //mostrar matriz
    	for(int i = 0; i<numero_equipos;i++)
    	{
    		cout<<endl;
    		for(int j = 0; j<numero_equipos;j++)
    		{
    			cout<<distancias[i][j];
    			if(j<numero_equipos-1)
    				cout<<" - ";
    		}
    		cout<< endl;
    	}



    //desplazamientos
    int disponibilidad[numero_equipos];//para ver si puede viajar en la fecha o si ya lo hizo-- valores de 0 o 1
    for(int i=0; i<numero_equipos; i++){
    	disponibilidad[i]=1;
    }

    int posicion_actual[numero_equipos];//para saber posicion actual de equipo; cambia
    for(int i=0; i<numero_equipos; i++){//cada equipo en su estadio inicialmente
        posicion_actual[i]=i+1;//---- guarda valores desde 1 (no el 0)
    }

    int posicion_original[numero_equipos];//para guardar posicion en donde estaba antes de fecha---------------------------------
    for(int i=0; i<numero_equipos; i++){//cada equipo en su estadio inicialmente
        posicion_original[i]=i+1;//---- guarda valores desde 1 (no el 0)
    }




    int min=999999999;//para encontrar menor distancia en matriz distancia
    int fila, columna;//auxiliares para guardar posicion del menor encontrado
    int numero_fecha=0;//variable para imprimir numero de fecha correspondiente
    int numero_f=0;//aux para variable numero_fecha

    float n = numero_equipos;
    int n_partidos= numero_equipos*numero_equipos - numero_equipos;
    int x=2*(numero_equipos-1);

    string nombreVisita;
    string nombreLocal;
    int columnasporproce =0;
    int aux = 0;
    
    //Division de columnas por procesador para generar el excel
    if((numero_equipos/(tamano -1 ))%tamano==0)
    	columnasporproce = numero_equipos/(tamano -1 );
    else
    {
    	columnasporproce = numero_equipos/(tamano -1 );
    	aux = numero_equipos %(tamano-1);
    }
    /*lxw_workbook  *workbook  = workbook_new("Datos_partidos.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    int row ;
    int col ;
    lxw_format *bold = workbook_add_format(workbook);
    format_set_bold(bold);
*/
    if(rank==0)
    {
    	InicioCalculoFechas:
    for(int m=0; m< x; m++)//for para repetir cosas hasta completar fechas= 2*(numero_equipos - 1),  +1 para asegurar todos los partidos
    {
        for(int z=0; z< n/2; z++)//se repite hasta completar una fecha; numero_equipos/2  por fecha
        {   
            for(int i=0; i<n; i++){//recorrer matriz distancia para encontrar menor
            	for(int j=0; j<n; j++){
            		if(i!=j){
            			if(distancias[j][i]>0)
            			{
            				if(disponibilidad[i]==1 && disponibilidad[j]==1)
            				{
            					if(distancias[j][i]<min){
            						min=distancias[j][i];
            						fila=i;
            						columna=j;
            					}
            				}
            			}
            		}   
            	}
            }
            for(int a=1; a<tamano; a++)
            {	
            	status= MPI_Send(&numero_fecha, 1, MPI_INT, a, 0, MPI_COMM_WORLD);
            	status1= MPI_Send(&fila, 1, MPI_INT, a, 0, MPI_COMM_WORLD);
            	status2= MPI_Send(&columna, 1, MPI_INT, a, 0, MPI_COMM_WORLD);
            }        	
//          cout<<"ciudad : "<<columna+1<<" viaja a ciudad "<<fila+1<<" recorriendo "<<min<<" km."<<endl;//---------------------
            
            posicion_actual[columna]=fila+1;//asigna posicion del visitante por la del local    
/*          cout<< "Posiciones : ";//------------------------------------------------------------------------------------------
            for(int i=0; i<n; i++)
                cout <<" c"<<i+1<<"= "<<posicion_actual[i];
            cout<<endl;*/

            disponibilidad[fila]=0; //declara indisponible a este equipo para poder viajar o recibir visita
            disponibilidad[columna]=0; //declara indisponible a este equipo para poder viajar o recibir visita
/*          cout<< "Disponibilidad : ";//--------------------------------------------------------------------------------------
            for(int i=0; i<n; i++)
                cout <<" c"<<i+1<<"= "<<disponibilidad[i];
            cout<<endl;*/


            distancias[columna][fila]=-1;
/*          //mostrar matriz
            for(int i = 0; i<n;i++)
            {
                cout<<endl;
                for(int j = 0; j<n;j++)
                {
                    cout<<distancias[i][j];
                    if(j<n-1)
                        cout<<" - ";
                }
                cout<< endl;
            }*/
            n_partidos--;
            min=999999999;//reset de min para poder volver a buscar un nuevo minimo
        }
        //Termina 1 fecha
        for(int i=0; i<n; i++)//todos disponibles otra vez para poder viajar o recibir visitas 
        {
        	disponibilidad[i]=1;
        }

        //fechas
        //char auxiliar[100];
        //char auxiliar3[100];
        //char auxiliar4[100];
        //numero_f=numero_fecha;
        //cout<<"Fecha: "<<numero_f+1<<endl;
            //sprintf(auxiliar,"%d",numero_f+1);
            //char auxiliar2[100]="Fecha: ";
            //strcat(auxiliar2,auxiliar);
            //worksheet_write_string(worksheet, row, col, auxiliar2, bold);
 /*   lxw_workbook  *workbook  = workbook_new("Datos_partidos.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    int row ;
    int col ;
    lxw_format *bold = workbook_add_format(workbook);
    format_set_bold(bold);
    char auxiliar[100];
        sprintf(auxiliar,"%d",numero_f+1);
        char auxiliar2[100]="Fecha: ";
        strcat(auxiliar2,auxiliar);
        worksheet_write_string(worksheet, ( ( (n/2) + 1 ) * fila ) , 0, auxiliar2, bold);
    //return workbook_close(workbook);
    */

        //row=row+1;
        /*for(int k=0;k<n;k++){// imprime la cantidad de veces que hay por fecha; --------------------- 
            if(posicion_actual[k]!=
            	posicion_original[k])
            {

                cout<<"Local: "<< posicion_actual[k] <<" - Visitante: "<< k+1 <<endl;*/
                //n_partidos--;
               /* char nombreequipolocal[200];
                char nombreequipovisita[200];
                nombreLocal=nombre_equipo(l, posicion_actual[k]);
                nombreVisita=nombre_equipo(l, k+1);
                //cout<<"nombre local: "<<nombreLocal<< "- ";
                //cout<<"nombre visita: "<<nombreVisita<<endl;
            strcpy(nombreequipolocal,nombreLocal.c_str());
            strcpy(nombreequipovisita,nombreVisita.c_str());
                worksheet_write_string  (worksheet, row, col,    nombreequipolocal, NULL);
                worksheet_write_string (worksheet, row, col + 1, nombreequipovisita, NULL);
                row = row + 1;
            }
        }*/
        numero_fecha++;
        

//      cout<<"Posiciones finales por fecha: ";
        for(int h=0; h<n; h++){//asigna posicion actual como la siguiente posicion original
            posicion_original[h]=posicion_actual[h];//---- guarda valores desde 1 (no el 0)
        //  cout<< posicion_actual[h]<<", ";
        }


        for(int i=0; i<n; i++)
        {
        	for(int j=0; j<n; j++)
        	{
        		if(i!=j)
        		{
        			if(distancias[i][j]>0)
        			{
        				distancias[i][j]=matrizequipos[posicion_actual[i]-1][j];
        			}
        		}

        	}
        }


/*      //mostrar matriz
        for(int i = 0; i<n;i++)
        {
            cout<<endl;
            for(int j = 0; j<n;j++)
            {
                cout<<distancias[i][j];
                if(j<n-1)
                    cout<<" - ";
            }
            cout<< endl;
        }*/

        cout<<endl;
        cout<<endl;
    }


    if(n_partidos!=0){
        x=1;
        goto InicioCalculoFechas;
    }

    //imprimir en excel
    //en fila
    //( ( (n/2) + 1 ) * fila )  , 0
   /* lxw_workbook  *workbook  = workbook_new("Datos_partidos.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    int row ;
    int col ;
    lxw_format *bold = workbook_add_format(workbook);
    format_set_bold(bold);
    char auxiliar[100];
    sprintf(auxiliar,"%d",numero_f+1);
    char auxiliar2[100]="Fecha: ";
    strcat(auxiliar2,auxiliar);
    worksheet_write_string(worksheet, ( ( (n/2) + 1 ) * fila ) , 0, auxiliar2, bold);
    return workbook_close(workbook);
*/
}

if(rank!=0)
{
	int contador_filas[30];
	for(int f = 0; f< ( numero_equipos * numero_equipos - numero_equipos ) ;f++)
	{
		status= MPI_Recv(&numero_fecha, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &rec_stat);
		status1= MPI_Recv(&fila, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &rec_stat);
		status2= MPI_Recv(&columna, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &rec_stat);
		fflush(stdout);
		if( (columnasporproce*rank + aux) <= fila && fila >= (columnasporproce*rank + aux + columnasporproce) )
		{
			escribir_en_excel(l, fila, columna, contador_filas, numero_equipos);
			//imprimir en excel
			//en fila 
			//( ( ( (n/2) + 1 ) * fila ) + contador_filas[fila -1] ) , 0
			//( ( ( (n/2) + 1 ) * fila ) + contador_filas[fila -1] ) , 1
			

		}
	}
	//return workbook_close(workbook);	
}

MPI_Finalize();

return 0;
}
