#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;
#define MAXN 100100

vector<int> grafo[MAXN]; // Lista de adjacência
int pai[MAXN];           // pai de cada vértice
int nivel[MAXN];         // nível de cada vértice

int distancia[MAXN]; // distância de cada vértice


int expandido[MAXN];         // indica se o vértice foi expandido
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

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int cards[n/2];

    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    int a, b;

    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);        
    }

    dfs(1);
    
    return 0;
}