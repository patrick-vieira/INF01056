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

    int name_count, relations_count;
    string a, r, b;
    cin >> name_count >> relations_count; // Lê o número de arestas

    map<string, int> people;
    int people_index = 0;

    string people_names[name_count + 1];

    for (int i = 0; i < relations_count; i++)
    {
        cin >> a >> r >> b; // Lê a aresta

        if (people[a] == 0)
        {
            people_names[people_index] = a; // Se a pessoa não estiver no map
            people[a] = people_index++;     // Adiciona a pessoa no map
        }

        if (people[b] == 0)
        {
            people_names[people_index] = b; // Se a pessoa não estiver no map
            people[b] = people_index++;     // Adiciona a pessoa no map
        }

        grafo[people[a]].push_back(people[b]); // Adiciona b como adjacente de a
        grafo[people[b]].push_back(people[a]); // Adiciona a como adjacente de b
    }

    int families = 0;

   
    for (int i = 1; i < name_count; i++)
    {
       if (expandido[i] == 0)
        {
            topologico.clear(); // Limpa a fila topológica
            dfs(i);
            families++;
        }
    }

    cout << families << endl;

    return 0;
}