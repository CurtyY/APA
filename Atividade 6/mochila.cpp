#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>

using namespace std;

int MochilaInteira(int n, int M, int pesos_vector[], int valores_vector[])
{	// tabela
	int V[n + 1][M + 1];

	// inicializando a primeira linha e primeira coluna com 0
	for(int w = 0; w <= M; w++)
    {
        V[0][w] = 0;
    }
	for(int i = 1; i <= n; i++)
    {
		V[i][0] = 0;
	}

	for(int i = 1; i <= n; i++)
	{
		for(int w = 1; w <= M; w++)
		{
			// elemento pode fazer parte da solução
			if(pesos_vector[i - 1] <= w)
			{   // max
				if((valores_vector[i - 1] + V[i - 1][w - pesos_vector[i - 1]]) > V[i - 1][w]){
					V[i][w] = valores_vector[i - 1] + V[i - 1][w - pesos_vector[i - 1]];
				}
				else{
					V[i][w] = V[i - 1][w];
				}
			}
			else{
				V[i][w] = V[i - 1][w]; // wi > w
			}
		}
	}
	// retorna o valor máximo colocado na mochila
	return V[n][M];
}

int main(void)
{
    int M;
    int n;
    int ord[100000];


    ifstream in;
    in.open("mochila01.txt");
    char numero[10];
    int fim = 0;
        while(!in.eof()){
            in >> numero;
            ord[fim] = atoi(numero);
            fim++;
        }
            n = ord[0];
            M = ord[1];

	int pesos_vector[n];
    int valores[n];
    int j =0;
        for (int i=2; i < 2*n+2; i = i+2)
        {
            pesos_vector[j] = ord[i];
            valores[j] = ord[i+1];
            j++;
        }

    cout << "Valor: " <<  MochilaInteira(n,M,pesos_vector,valores) << endl;
    return 0;
}
