#include <iostream>
#include <vector>

using namespace std;
#define MAXN 100100

int expandido[MAXN];     // indica se o vértice foi expandido
int ordem[MAXN];         //indica quando o vértice foi expandido
int alcanca[MAXN];       //indica se o alcance do vértice
vector<int> grafo[MAXN]; // Lista de adjacência

int ordem_atual = 0; // indica a ordem do ultimo vértice expandido

void dfs(int vertice)
{
    expandido[vertice] = 1; // Marca o vértice como expandido
    for (int i = 0; i < grafo[vertice].size(); i++)
    { // Percorre os adjacentes
        int adjacente = grafo[vertice][i];
        if (expandido[adjacente] == 0)
        {
            cout << "v-in " << vertice << " " << adjacente << endl;
            dfs(adjacente); // se o adjacente não foi expandido, então o expande
            cout << "v-out " << vertice << " " << adjacente << endl;
        }
    }
}

void dfs_para_pontes(int vertice, int pai = -1)
{
    expandido[vertice] = 1;         // Marca o vértice como expandido
    ordem_atual++;                  // expande mais 1
    ordem[vertice] = ordem_atual;   // associa a ordem de expansão
    alcanca[vertice] = ordem_atual; // indica que o alcance é ele mesmo
    for (int i = 0; i < grafo[vertice].size(); i++)
    { // Percorre os adjacentes
        int adjacente = grafo[vertice][i];
        if (expandido[adjacente] == 1 && adjacente != pai)
        {
            // Se o adjacente foi expandido, escolhe o mínimo que pode alcançar
            alcanca[vertice] = min(alcanca[vertice], ordem[adjacente]);
        }
        else if (expandido[adjacente] == 0)
        {
            dfs_para_pontes(adjacente, vertice); // expandir adjacente se não foi expandido
            // alcança o mínimo alcançado entre o vértice e o adjacente
            alcanca[vertice] = min(alcanca[vertice], alcanca[adjacente]);
            if (alcanca[adjacente] > ordem[vertice])
            {
                // Se o adjacente não alçanda um expandido antes do vértice,
                // então a aresta não está em um ciclo e é ponte
                cout << "(" << vertice << ", " << adjacente << ") eh ponte" << endl;
            }
        }
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, a, b;
    cin >> m; // Lê o número de arestas
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;         // Lê a aresta
        grafo[a].push_back(b); // Adiciona b como adjacente de a
        grafo[b].push_back(a); // Adiciona a como adjacente de b
    }
    // dfs(1); // Começa pelo primeiro vértice

    dfs_para_pontes(1); // Começa pelo primeiro vértice
    return 0;
}