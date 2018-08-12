#include <iostream>
#include <stdlib.h>
#include <fstream>

void junta_quebrado(int vetor[], int ini, int meio, int fim, int Aux[]) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) && ((dir >= fim) || (vetor[esq] < vetor[dir]))) {
            Aux[i] = vetor[esq];
            ++esq;
        }
        else {
            Aux[i] = vetor[dir];
            ++dir;
        }
    }
    //copiando o vetor de volta ao original
    for (int i = ini; i < fim; ++i) {
        vetor[i] = Aux[i];
    }
}

void Merge(int vetor[], int inicio, int fim, int vetor_aux[]) {

    if ((fim - inicio) < 2) return;

    int meio = ((inicio + fim)/2);

    Merge(vetor, inicio, meio, vetor_aux);
    Merge(vetor, meio, fim, vetor_aux);
    junta_quebrado(vetor, inicio, meio, fim, vetor_aux);
}

void Merge_Sort(int vetor[], int tamanho) {
    //criando vetor auxiliar
    int vetor_aux[tamanho];

    Merge(vetor, 0, tamanho, vetor_aux);
}
void Print(int array[], int tam){

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
	 if (file.is_open()) {
	 while (!file.eof()) {
	    file >> output;
	    vetor[linhas] = atoi(output);
	   	linhas++;
	 }
	}
	file.close();

    Merge_Sort(vetor, linhas);
   	Print(vetor, linhas);
	return 0;


return 0;
}
