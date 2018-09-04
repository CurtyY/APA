#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;


void HeapMaximo(int *arr, int i, int n)
{
        int j = 2*i;
        int temporario = arr[i];

    while(j<=n)
    {
        if(j<n && arr[j+1] > arr[j])
            j++;

        if (temporario > arr[j])
            break;
        else if (temporario <= arr[j])
        {
            arr[j/2]=arr[j];
            j=2*j;
        }
    }

    arr[j/2] = temporario;
return;
}

void Heap_Max_build(int *arr, int n)
{
    for (int i = n/2;i>=1;i--)
    {
        HeapMaximo(arr,i,n);
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
            Heap_Max_build(vetor,linhas);
    print(vetor,linhas);



return 0;
}
