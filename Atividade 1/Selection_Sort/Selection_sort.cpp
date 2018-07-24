#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;


void selection_sort(int num[],int tam){
    int aux,Min;
    for(int i=0;i<tam;i++)
    {
        Min = i;
        for(int j=i+1;j<tam;j++)
        {
            if(num[j]<num[Min])
            {
                Min = j;
            }
        }
        aux = num[i];
        num[i] = num[Min];
        num[Min] = aux;
    }
        for (int i = 0; i < tam; ++i)
        {
            std::cout << "Posicao: " << i+1 << " -> Numero: " << num[i] << std::endl;
        }

}

int main(){

  std::string entrada;
	int array[100000];
	int linhas = 0;

	std::cout << "Digite o nome do arquivo contendo os casos de teste: " << std::endl;
	std::cin >> entrada;

	 std::ifstream file;
	 file.open(entrada);
	 char output[1000];
	 if (file.is_open()) {
	 while (!file.eof()) {
	    file >> output;
	    array[linhas] = atoi(output);
	   	linhas++;
	 }
	}
	file.close();

    selection_sort(array, linhas);


return 0;
}

