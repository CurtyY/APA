#include <bits/stdc++.h>
#define MAX_TAMANHO 30

typedef struct arestas
{
    int u,v,peso;

}arestas;

typedef struct lista_arestas
{
    arestas data[MAX_TAMANHO];
    int n;

}lista_arestas;

    lista_arestas new_lista;
    int Matriz[MAX_TAMANHO][MAX_TAMANHO],n;

    lista_arestas espalhamento;


int find(int parentes[],int v) /*find do union_find*/
{
        return(parentes[v]);
}

void Union(int parentes[],int c1,int c2) /* union_find*/
{
        for(int i=0;i<n;i++)
        {
            if(parentes[i]==c2)
            {
                parentes[i]=c1;
            }
        }
}

void kruskal()
{
        int parentes[MAX_TAMANHO],cno1,cno2;

        new_lista.n=0;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(Matriz[i][j]!=0)
                {
                    new_lista.data[new_lista.n].u=i;
                    new_lista.data[new_lista.n].v=j;
                    new_lista.data[new_lista.n].peso=Matriz[i][j];
                    new_lista.n++;
                }
            }
        }

                    /* sort */
        arestas temp;
        for(int i=1;i<new_lista.n;i++)
        {
            for(int j=0;j<new_lista.n-1;j++)
            {
                if(new_lista.data[j].peso>new_lista.data[j+1].peso)
                {
                    temp=new_lista.data[j];
                    new_lista.data[j]=new_lista.data[j+1];
                    new_lista.data[j+1]=temp;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
             parentes[i]=i;
        }

        espalhamento.n=0;

        for(int i=0;i<new_lista.n;i++)
        {
                cno1 = find(parentes,new_lista.data[i].u);
                cno2 = find(parentes,new_lista.data[i].v);

                    if(cno1!=cno2)
                    {
                        espalhamento.data[espalhamento.n]=new_lista.data[i];
                        espalhamento.n=espalhamento.n+1;
                        Union(parentes,cno1,cno2);
                    }
        }
}


void print()
{
    int cost=0;

        for(int i=0;i<espalhamento.n;i++)
        {
            std::cout<<espalhamento.data[i].u<<" --- "<<espalhamento.data[i].v<<" Peso: "<<espalhamento.data[i].peso<<std::endl;
            cost=cost+espalhamento.data[i].peso;
        }

    std::cout<<"Custo da arvore de espalhamento: "<<cost<<std::endl;
}

int main()
{

        std::cout<<"Entre com o numero de vertices: "<<std::endl;

        std::cin>>n;

        std::cout<<"Entre com a matriz de adjacencia: "<<std::endl;

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    std::cin>>Matriz[i][j];
                }
            }

        kruskal();
        print();
}

/*
        {0, 23, 17, 19},
        {23, 0, 22, 20},
        {17, 22, 0, 25},
        {19, 20, 25, 0}
*/
