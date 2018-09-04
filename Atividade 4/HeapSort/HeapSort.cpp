#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;


void amontoar(int arr[], int n, int i)
{
   int maior = i;
   int esquerda = 2*i + 1;
   int direita = 2*i + 2;

   if (esquerda < n && arr[esquerda] > arr[maior])
     maior = esquerda;

   if (direita < n && arr[direita] > arr[maior])
     maior = direita;

   if (maior != i)
   {
     swap(arr[i], arr[maior]);
     amontoar(arr, n, maior);
   }
}

void heapSort(int arr[], int n)
{
   for (int i = n / 2-1; i >= 0; i--)
     amontoar(arr, n, i);

   for (int i=n-1; i>=0; i--)
   {
     swap(arr[0], arr[i]);

     amontoar(arr, i, 0);
   }
}

void print(int array[], int tam){


	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << array[i] << endl;

	}

}


int main (){

    char entrada[15];
   	int alcance = 100000;
	int vetor[100000];
	int linhas = 0;

	cout << "Digite o nome do arquivo contendo os casos de teste: " << std::endl;
	cin >> entrada;

	 ifstream file;
    file.open(entrada);
	 char output[1000];

	 if (file.is_open())
        {
         while (!file.eof())
             {
                file >> output;
                vetor[linhas] = atoi(output);
                linhas++;
             }
        }
	file.close();
           heapSort(vetor,linhas);
    print(vetor,linhas);



return 0;
}
