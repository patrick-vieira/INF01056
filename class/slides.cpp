#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int somas[400003]; // árvore de segmentos de somas



int normalize(int a)
{
    return (a > 0? 1 : (a < 0 ? -1 : 0));
}

// chamar com: no = 1 (raiz), inicio = 0 (início do vetor), fim = n - 1 (fim do vetor)
void constroi(int vetor[], int no, int inicio, int fim)
{ // inicializa a árvore do vetor
    if (inicio == fim)
    {                           // se está numa folha
        somas[no] = normalize(vetor[fim-1]); // a soma na folha é o único elemento nela
    }
    else
    {
        int metade = (inicio + fim) / 2;               // metade do vetor
        constroi(vetor, 2 * no, inicio, metade);       // constrói o filho esquerdo
        constroi(vetor, 2 * no + 1, metade + 1, fim);  // constrói o filho direito
        somas[no] = somas[2 * no] * somas[2 * no + 1]; // a soma do nó é a soma dos filhos
    }
}
// // chamar com: no = 1 (raiz), inicio = 0 (início do vetor), fim = n - 1 (fim do vetor)
// int soma(int i, int j, int no, int inicio, int fim)
// {              // busca a soma do segmento [i,j]
//     if (i > j) // vetor vazio
//         return 0;
//     if (inicio == i && fim == j)
//     {                     // segmento coincide com intervalo do nó
//         return somas[no]; // retorna a soma do nó
//     }
//     int metade = (inicio + fim) / 2; // metade do intervalo do nó
//     // calcula a soma como soma dos sub-intervalos dos filhos
//     return soma(i, min(metade, j), 2 * no, inicio, metade) + soma(max(i, metade + 1), j, 2 * no + 1, metade + 1, fim);
// }

int produto(int i, int j, int no, int inicio, int fim) {
    if (i > j) // vetor vazio
        return 1;

    if (inicio == i && fim == j)
    {                     // segmento coincide com intervalo do nó
        return somas[no]; // retorna a soma do nó
    }
    int metade = (inicio + fim) / 2; // metade do intervalo do nó

    return produto(i, min(metade, j), 2 * no, inicio, metade) * produto(max(i, metade + 1), j, 2 * no + 1, metade + 1, fim);
}

void atualiza(int posicao, int valor, int no, int inicio, int fim)
{
    if (inicio == fim)
    { // se for uma filhas atualiza o valor
        somas[no] = normalize(valor);
    }
    else
    {
        int metade = (inicio + fim) / 2;                      // calcula metade
        if (posicao <= metade)                                // verifica se a atualização é à esquerda
            atualiza(posicao, valor, 2 * no, inicio, metade); // atualiza no filho esquerdo
        else                                                  // caso contrário a atualização é à direita
            atualiza(posicao, valor, 2 * no + 1, metade + 1, fim);
        somas[no] = somas[2 * no] * somas[2 * no + 1]; // atualiza a soma do nó
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

    int inputs[400003];
    int n_elements, k_rounds;

    while (cin >> n_elements >> k_rounds)
    {
        for (int i = 0; i < n_elements; i++)
        {
            cin >> inputs[i];
        }
        constroi(inputs, 1, 1, n_elements);

        for (int i = 0; i < k_rounds; i++)
        {
            char command;
            int a, b;
            cin >> command >> a >> b;

            if (command == 'C')
            {
                atualiza(a, b, 1, 1, n_elements);
            }
            else if (command == 'P')
            {
                int product = produto(a, b, 1, 1, n_elements);

                if (product > 0)
                {
                    cout << "+";
                }
                else if (product < 0)
                {
                    cout << "-";
                }
                else if (product == 0)
                {
                    cout << "0";
                }
            }
        }

        cout << endl;
    }

    return 0;
}