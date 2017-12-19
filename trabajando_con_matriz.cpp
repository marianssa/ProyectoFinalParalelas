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
using namespace std;

void vaciar(int ultimo_visitado[],int n)
{
	int i;
	for(i=0;i<n;i=i+1)
	{
		ultimo_visitado[i]=0;
	}
}

int comprobar(int ultimo_visitado[], int dato)
{
	if(ultimo_visitado[dato]==1)
	return 1;
	else
	return 0;
}
int buscar(int matriz_ubicacion[], int n, int i, int j)
{
	int k;
	for(k=0;k<n;k=k+1)
	{
		if((matriz_ubicacion[k]==j)&&(matriz_ubicacion[k]!=i))
		return 1;
	}
return 0;
}





int main()
{
float matriz[6][6];
int i,j;

matriz[0][0]=0;
matriz[0][1]=1.2;
matriz[0][2]=3.1;
matriz[0][3]=4.4;
matriz[0][4]=6.1;
matriz[0][5]=2.6;
matriz[1][0]=1.2;
matriz[1][1]=0;
matriz[1][2]=3.3;
matriz[1][3]=5.2;
matriz[1][4]=3.7;
matriz[1][5]=8.9;
matriz[2][0]=3.1;
matriz[2][1]=3.3;
matriz[2][2]=0;
matriz[2][3]=1.5;
matriz[2][4]=7.1;
matriz[2][5]=2.2;
matriz[3][0]=4.4;
matriz[3][1]=5.2;
matriz[3][2]=1.5;
matriz[3][3]=0;
matriz[3][4]=7.7;
matriz[3][5]=5.6;
matriz[4][0]=6.1;
matriz[4][1]=3.7;
matriz[4][2]=7.1;
matriz[4][3]=7.7;
matriz[4][4]=0;
matriz[4][5]=0.2;
matriz[5][0]=2.6;
matriz[5][1]=8.9;
matriz[5][2]=2.2;
matriz[5][3]=5.6;
matriz[5][4]=0.2;
matriz[5][5]=0;


int fecha;
fecha=10;
int local[6];
int visita[6];

int matriz_visitada[6][6];

for(i=0;i<6;i=i+1)
{
	for(j=0;j<6;j=j+1)
	{
		matriz_visitada[i][j]=0;
	}
}

for(i=0;i<6;i=i+1)
{
	matriz_visitada[i][i]=1;
}

int ct=0;
int k=0;
float min;
int ultimo_visitado[6];
min=1000000000000;
int pos;
int a;
int x;
x=0;
int matriz_ubicacion[6];
for(i=0;i<6;i=i+1)
{
	matriz_ubicacion[i]=i;
}

for(i=0;i<6;i=i+1)
{
	for(j=0;j<6;j=j+1)
	{
		cout<<matriz[i][j]<<endl;
	}
}
while(k!=fecha/2)
{
	cout<<"Fecha "<<k+1<<endl;
	vaciar(ultimo_visitado,6);
	for(i=0;i<6;i=i+1)
	{
		a=comprobar(ultimo_visitado,i);
		cout<<"1 "<<a<<endl;
		if(a==0)
		{
			for(j=0;j<6;j=j+1)
			{
	
				a=comprobar(ultimo_visitado,j);
				cout<<"2 "<<a<<endl;
				if(a==0)
				{
					if(matriz_visitada[i][j]==0)
					{

						if(matriz[i][j]<min)
						{

							min=matriz[i][j];
							pos=j;
							cout<<"i "<<i<<endl;
							cout<<"j "<<pos<<endl;
							cout<<"min "<<min<<endl;
							matriz_ubicacion[pos]=i;


						}
					}
				}
			}
			ultimo_visitado[i]=1;
			ultimo_visitado[pos]=1;
			local[x]=i;
			cout<<"Local "<<local[x]<<endl;
			visita[x]=pos;
			cout<<"Visita "<<visita[x]<<endl;
			x=x+1;
			matriz_visitada[i][pos]=1;
			matriz_visitada[pos][i]=1;



		}
		min=1000000000000;
	}
	k=k+1;
	x=0;
}
return 0;
}
