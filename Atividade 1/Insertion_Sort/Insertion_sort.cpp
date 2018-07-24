#include <iostream>
#include <stdlib.h>
#include <fstream>


void insertin_sort(int num[],int tam){

   for(int i=1;i<tam;i++)
       {
            int atual = num[i];
            int j=i-1;

                while((j>=0)&&(num[j]>atual))
                {
                    num[j+1] = num [j];
                    j--;
                }
                num[j+1]=atual;

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

    insertin_sort(array, linhas);


return 0;
}
