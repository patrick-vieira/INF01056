#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* 
        Resume: 
            input format: numero linhas, analisa cada caractere da linha
            data structure: matriz
            output format: matriz            
    */ 
    int n_cells;

    while (cin >> n_cells)
    {

        int cells[n_cells][n_cells];
        int cells_controll_count[n_cells];
        int controlled_by[n_cells][n_cells];

        string line_cell;
        char controll;

        for (int i = 0, j = 0; i < n_cells; i++, j = 0)
        {
            cin >> line_cell;
            stringstream s(line_cell);
            while (s >> controll)
            {
                // convert char to int
                controll -= '0';
                cells[i][j] = controll;
                
                // controll count
                if (controll == 1){
                    cells_controll_count[i]++;
                    controlled_by[j][i] = 1;
                } else {
                    controlled_by[j][i] = 0;
                }

                j++;
            }
        }

        for (int i = 0; i < n_cells; i++)
        {
            for (int j = 0; j < n_cells; j++)
            {
                cout << cells[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << endl;

        for (int i = 0; i < n_cells; i++)
        {
            for (int j = 0; j < n_cells; j++)
            {
                cout << controlled_by[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << endl  << endl;

    return 0;
}