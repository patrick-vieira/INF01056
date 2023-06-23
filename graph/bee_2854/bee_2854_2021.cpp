//
// Created by vieir on 09/09/2021.
//


#include <iostream>
#include <vector>

#include <set>
#include <list>

using namespace std;

#define MAXM 301
#define MAXN 201

vector<int> grafo[MAXM]; //Lista de adjacência
int expandido[MAXM] = {0}; //indica se o vértice foi expandido


int getIndex(vector<string> &input, string searched) {

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == searched) {
            return i;
        }
    }

    return -1;
}

void dfs(int vertice, int tag) {
    expandido[vertice] = tag;//Marca o vértice como expandido usando tag
    for (int i = 0; i < grafo[vertice].size(); i++) { //Percorre os adjacentes
        int adjacente = grafo[vertice][i];
        if (expandido[adjacente] == 0) {
//            cout << "expandindo: " << adjacente << "\n";
            dfs(adjacente, tag);//se o adjacente não foi expandido, então o expande
        }
    }
}

int main() {

    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, n; // m pessoas , n relações
    cin >> m >> n;


    vector<string> pessoas;
    vector<string>::iterator pitr;

    string a, r, b;

    // cria o grafo; e a lista de pessoas.
    for (int i = 0; i < n; i++) {
        cin >> a >> r >> b;//Lê a relação

        int aIndex = getIndex(pessoas, a); // pega o index da pessoa a
        int bIndex = getIndex(pessoas, b); // pega o index da pessoa b

        if(aIndex < 0) { // se não existe no vetor de pessoas
            pessoas.push_back(a); // adiciona no vetor de pessoas
            aIndex = pessoas.size()-1; 
        }
        if(bIndex < 0) { // se não existe no vetor de pessoas
            pessoas.push_back(b); // adiciona no vetor de pessoas
            bIndex = pessoas.size()-1; 
        }

        grafo[aIndex].push_back(bIndex); // adiciona a relação no grafo
        grafo[bIndex].push_back(aIndex); // adiciona a relação no grafo

    }

    int familia = 1;
    for(int i = 0; i < m; i++){ // para cada pessoa
        if(expandido[i] == 0) {  // se não foi expandido  
            dfs(i, familia); // o tag no DFS é para marcar cada expansão com um valor diferente 
            familia++; // incrementa a familia
        } 
    }

    cout << familia-1 << "\n"; // imprime o numero de familias

    // set vazio para contar quantos dfs foram feitos
    set<int> desconexos;

    // para cada tag adiciona no set desconexos
    for (int i=0; i<m; i++)
    {
        if (desconexos.find(expandido[i])==desconexos.end()) // se não existe no set 
        {
            desconexos.insert(expandido[i]); // adiciona no set
        }
    }

    cout<<desconexos.size()<<endl;
    return 0;
}