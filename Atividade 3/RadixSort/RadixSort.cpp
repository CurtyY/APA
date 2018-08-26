#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;


void print(int array[], int tam){

	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << array[i] << endl;

	}

}

void Counting_Sort(int Vet[],int e,int k){

	int countador[10]={0};
    int Vet_saida[k];

	for (int i=0;i<k;i++){
		countador[ (Vet[i]/e)%10 ] = countador[ (Vet[i]/e)%10 ]+1;

	}

	for (int i=1;i<10;i++){
		countador[i] = countador[i] + countador[i-1];
	}

	for(int i=k-1;i>=0;i--){
		Vet_saida[countador[ (Vet[i]/e)%10 ] - 1 ] = Vet[i];
		countador[ (Vet[i]/e)%10 ] = countador[ (Vet[i]/e)%10 ]-1;

	}
	for(int i=0;i<k;i++)
        Vet[i]=Vet_saida[i];
}


int max_val(int vetor[],int n){

    int Max = vetor[0];

    for(int i=1;i<n;i++)
    {
        if (vetor[i]>Max)
            Max = vetor[i];
    }
    return Max;
}
void Radix_Sort(int vetor[],int a){

    int m = max_val(vetor,a);
    for(int e=1; m/e > 0; e = e*10){
        Counting_Sort(vetor,e,a);
    }
}

int main (){
    char entrada[15];
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
    print(vetor,linhas);
        Radix_Sort(vetor,linhas);
	print(vetor,linhas);


return 0;
}
