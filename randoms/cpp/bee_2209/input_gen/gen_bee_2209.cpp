#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main()
{

#ifndef ONLINE_JUDGE    
    freopen("input-gen.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n_elements = 100, k_rounds=100;

    cout << n_elements << " " << k_rounds << endl;
    for( int i = 0; i< n_elements;i++){
        cout << i << " ";
    }
    cout << endl;

    for(int i = 0; i < k_rounds; i++) {
        cout << "C " << i+1 << " " << i+1 << endl;
        cout << "P " << i+1 << " " << i+1 << endl;
    }
    return 0;
}