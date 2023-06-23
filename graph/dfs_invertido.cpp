#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAXN 100100
int expandido[MAXN];         // indica se o vértice foi expandido
vector<int> grafo[MAXN];     // Lista de adjacência
vector<int> invertido[MAXN]; // Grafo invertido em lista de adjacência
list<int> topologico;        // fila com os vértices ordenados topologicamente

void dfs(int vertice)
{
    expandido[vertice] = 1; // Marca o vértice como expandido
    for (int i = 0; i < grafo[vertice].size(); i++)
    { // Percorre os adjacentes
        int adjacente = grafo[vertice][i];
        if (expandido[adjacente] == 0)
        {
            dfs(adjacente); // se o adjacente não foi expandido, então o expande
        }
    }
    topologico.push_back(vertice);
}
void dfs_invertido(int vertice)
{
    expandido[vertice] = 1; // Marca o vértice como expandido
    for (int i = 0; i < invertido[vertice].size(); i++)
    { // Percorre os adjacentes
        int adjacente = invertido[vertice][i];
        if (expandido[adjacente] == 0)
            dfs_invertido(adjacente); // se o adjacente não foi expandido, então o expande
    }
    topologico.push_back(vertice);
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, a, b;
    cin >> n >> m; // Lê o número de vértices e arestas
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;             // Lê a aresta
        grafo[a].push_back(b);     // Adiciona b como adjacente de a no grafo
        invertido[b].push_back(a); // Adiciona a como adjacente de b no grafo invertido
    }
    for (int i = 1; i <= n; i++)
        if (expandido[i] == 0)
        {
            topologico.clear(); // Limpa a fila topológica
            dfs(i); // Chama o dfs invertido no vértice
            for (list<int>::iterator it = topologico.begin(); it != topologico.end(); ++it)
            {
                cout << *it << " ";
            }

            cout << endl;
        }
    return 0;
}