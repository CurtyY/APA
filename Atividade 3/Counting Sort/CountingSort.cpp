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

void Counting_Sort(int Vet[],int Vet_saida[],int alcance,int k){

	int countador[alcance];


		//Atribuindo o valor zero para cada posição do vetor auxiliar
	for (int i=0;i<k;i++){
		countador[i] = 0;
	}
        //armazena nas posiçoes
	for (int i=0;i<k;i++){
		countador[Vet[i]] = countador[Vet[i]]+1;

	}

	for (int i=1;i<alcance;i++){
		countador[i] = countador[i] + countador[i-1];
	}

	for(int i=k-1;i>=0;i--){
		Vet_saida[countador[Vet[i]]-1] = Vet[i];
		countador[Vet[i]] = countador[Vet[i]]-1;

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
    int saida[linhas];
	print(vetor,linhas);
        Counting_Sort(vetor,saida,alcance,linhas);
	print(saida,linhas);


return 0;
}
