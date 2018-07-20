#include <iostream>
#include <stdlib.h>

using namespace std;

void insertin_sort(int num[],int tam){
   for(int i=1;i<tam;i++){
    int atual = num[i];
    int j=i-1;
        while((j>=0)&&(num[j]>atual))
        {
            num[j+1] = num [j];
            j--;
        }
        num[j+1]=atual;
    }
}


int main(){
    int tamanho;
    cin>>tamanho;
    int vetor[tamanho];

    for(int i=0;i<tamanho;i++){
        cin>>vetor[i];
    }

     for(int i=0;i<tamanho;i++){
        cout<<vetor[i]<<" ";
        }

        insertin_sort(vetor,tamanho);

     for(int i=0;i<tamanho;i++){
        cout<<vetor[i]<<" ";
        }






return 0;
}
