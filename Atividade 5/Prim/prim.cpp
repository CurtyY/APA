#include <iostream>
#include <cstring>
using namespace std;

#define V 4

void prim(int G[V][V])
{
  int aresta;
  int selected[V];

  memset (selected, false, sizeof(selected));
  aresta = 0;
  selected[0] = true;
  //linha / coluna
  int x;
  int y;

  cout << "Arestas" << " : " << "Pesos";
  cout << endl;

  while (aresta < V - 1) {

      int min = 9999;
      x = 0;
      y = 0;

      for (int i = 0; i < V; i++)
      {
        if (selected[i])
        {
            for (int j = 0; j < V; j++)
            {
              if (!selected[j] && G[i][j])
              {
                  if (min > G[i][j])
                  {
                      min = G[i][j];
                      x = i;
                      y = j;
                  }
              }
          }
        }
      }
      cout << x <<  " - " << y << "  :  " << G[x][y];
      cout << endl;
      selected[y] = true;
      aresta++;
    }
}

int main () {

    int G[V][V] = {
            {0, 23, 17, 19},
            {23, 0, 22, 20},
            {17, 22, 0, 25},
            {19, 20, 25, 0}
    };

    prim(G);

  return 0;
}
