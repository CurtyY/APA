#include <iostream>
#include <stdlib.h>
#include <fstream>

void quicksort(int values[], int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = values[(began + end) / 2];

	while(i <= j)
        {
            while(values[i] < pivo && i < end)
                {
                    i++;
                }
            while(values[j] > pivo && j > began)
                {
                    j--;
                }
            if(i <= j)
                {
                    aux = values[i];
                    values[i] = values[j];
                    values[j] = aux;
                    i++;
                    j--;
                }
        }
	if(j > began)
        {
            quicksort(values, began, j+1);
        }
	if(i < end)
        {
            quicksort(values, i, end);
        }
}

void Mostra_Array_Ordenado(int array[], int tam){

	for (int i = 0; i < tam; ++i)
        {
            std::cout << "Order: " << i+1 << " - Number: " << array[i] << std::endl;
        }

}

int main(){
    std::string entrada;
	int vetor[100000];
	int linhas = 0;

	std::cout << "Digite o nome do arquivo contendo os casos de teste: " << std::endl;
	std::cin >> entrada;

	 std::ifstream file;
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

    quicksort(vetor,0,linhas);
   	Mostra_Array_Ordenado(vetor, linhas);
	return 0;


return 0;
}
