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

void bfs(int raiz)
{
    list<int> expandir;       // Fila de vértices que precisa expandir
    int expandido[MAXN];      // indica se o vértice foi adicionado na fila
    expandir.push_back(raiz); // Indica que precisa expandir o vértice
    expandido[raiz] = 1;      // Marca como expandido
    nivel[raiz] = 0;          // marca a raiz como de nível 0
    while (!expandir.empty())
    {                                   // enquanto a fila não estiver vazia
        int vertice = expandir.front(); // obtem o primeiro elemento da lista
        expandir.pop_front();           // retira o primeiro vértice da fila
        for (int i = 0; i < grafo[vertice].size(); i++)
        { // Percorre os adjacentes
            int adjacente = grafo[vertice][i];
            if (expandido[adjacente] == 0)
            {                                          // verifica se o adjacente não foi adicionado
                expandir.push_back(adjacente);         // o adiciona na fila para expandir
                expandido[adjacente] = 1;              // Marca que foi adicionado na fila expandido
                pai[adjacente] = vertice;              // coloca v como pai do adjacente
                nivel[adjacente] = nivel[vertice] + 1; // adiciona 1 ao nível do adjacente
            }
        }
    }
}

void bfs_para_distancias(int origem)
{
    list<int> expandir;         // Fila de vértices que precisa expandir
    int expandido[MAXN];        // indica se o vértice foi adicionado na fila
    expandir.push_back(origem); // Indica que precisa expandir o vértice
    expandido[origem] = 1;      // Marca como expandido
    distancia[origem] = 0;      // marca a origem como de nível 0
    while (!expandir.empty())
    {                                   // enquanto a fila não estiver vazia
        int vertice = expandir.front(); // obtem o primeiro elemento da lista
        expandir.pop_front();           // retira o primeiro vértice da fila
        for (int i = 0; i < grafo[vertice].size(); i++)
        { // Percorre os adjacentes
            int adjacente = grafo[vertice][i];
            if (expandido[adjacente] == 0)
            {                                                  // verifica se o adjacente não foi adicionado
                expandir.push_back(adjacente);                 // o adiciona na fila para expandir
                expandido[adjacente] = 1;                      // Marca que foi adicionado na fila expandido
                distancia[adjacente] = distancia[vertice] + 1; // aumenta em 1 a distância
            }
        }
    }
}

int bfs_para_distancias_nos(int origem, int destino)
{
    list<int> expandir;         // Fila de vértices que precisa expandir
    int expandido[MAXN];        // indica se o vértice foi adicionado na fila
    
    memset(expandido, 0, sizeof(expandido));

    expandir.push_back(origem); // Indica que precisa expandir o vértice
    expandido[origem] = 1;      // Marca como expandido
    distancia[origem] = 0;      // marca a origem como de nível 0
    while (!expandir.empty())
    {                                   // enquanto a fila não estiver vazia
        int vertice = expandir.front(); // obtem o primeiro elemento da lista
        expandir.pop_front();           // retira o primeiro vértice da fila
        for (int i = 0; i < grafo[vertice].size(); i++)
        { // Percorre os adjacentes
            int adjacente = grafo[vertice][i];
            if (expandido[adjacente] == 0)
            {                                                  // verifica se o adjacente não foi adicionado
                expandir.push_back(adjacente);                 // o adiciona na fila para expandir
                expandido[adjacente] = 1;                      // Marca que foi adicionado na fila expandido
                distancia[adjacente] = distancia[vertice] + 1; // aumenta em 1 a distância
            }

            if (adjacente == destino)
            {
                return distancia[adjacente];
            }
        }
    }

    return -1;
}

int ancestral_mais_proximo(int u, int v)
{
    if (nivel[u] > nivel[v]) // sempre chama primeiro o menor nível e depois o maior
        return ancestral_mais_proximo(v, u);
    while (nivel[v] > nivel[u]) // enquanto não tiverem o mesmo nível
        v = pai[v];             // subir pelo de maior nível
    while (v != u)
    {               // enquanto não forem iguais
        u = pai[u]; // subir u
        v = pai[v]; // subir v
    }
    return v; // retorna o ancestral comum mais próximo
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

    int dist = 0;
    
    memset(distancia, 0, sizeof(distancia));
    dist = bfs_para_distancias_nos(1, 3);
    cout << "1-3 " << dist << endl;
    
    memset(distancia, 0, sizeof(distancia));
    dist = bfs_para_distancias_nos(1, 3);
    cout << "1-3 " << dist << endl;

    // for (int i = 1; i < m; i++)
    // {
    //     bfs_para_distancias(i);
    //     for (int j = 1; j < m; j++)
    //     {
    //         cout << distancia[j] << " ";
    //     }

    //     memset(distancia, 0, sizeof(distancia));

    //     cout << endl;
    // }

    return 0;
}