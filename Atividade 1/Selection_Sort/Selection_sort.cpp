#include <iostream>
#include <stdlib.h>
#include <stdio.h>

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
}

int main(){

        int tamanho;
        cin>>tamanho;
        int vetor[tamanho];

        for(int i=0;i<tamanho;i++)
            {
                cin>>vetor[i];
            }

        cout<<"Vetor ordenado: ";
            for(int i=0;i<tamanho;i++)
                {
                 cout<<vetor[i]<<" ";
                }

        selection_sort(vetor,tamanho);

         cout<<"Vetor ordenado: ";
            for(int i=0;i<tamanho;i++)
                {
                 cout<<vetor[i]<<" ";
                }

return 0;
}

