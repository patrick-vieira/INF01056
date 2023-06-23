#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int product_range(int a, int b, int* initial_values) {
    if (a == b) {
        return initial_values[a-1];
    } else {
        int mid = (a + b) / 2;
        int left_product = product_range(a, mid, initial_values);
        int right_product = product_range(mid+1, b, initial_values);
        return left_product * right_product;
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

    /*
        Input
        Each test case is described using several lines.
        The first line contains two integers N and K, indicating respectively
        the number of elements in the sequence and the number of rounds of
        the game (1 ≤ N, K ≤ 10**5).
        The second line contains N inteiros Xi  that represent
        the initial values of the sequence (-100 ≤ Xi ≤ 100 for i = 1, 2, ..., N).
    */

   //while(!cin.eof()) {

    int n_elements, k_rounds;

    while(cin >> n_elements >> k_rounds) {
    //cin >> n_elements >> k_rounds;
    
        int initial_values[n_elements];
        string output = "";

        for (int i = 0; i < n_elements; i++)
        {
            cin >> initial_values[i];
        }
        /*
            Each of the next K lines describes a command and
            starts with an uppercase letter that is either 'C' or 'P'.

            If the letter is 'C', the line describes a change command, and
            the letter is followed by two integers I and V indicating that XI
            must receive the value V (1 ≤ I ≤ N e -100 ≤ V ≤ 100).

            If the letter is `P', the line describes a product command, and
            the letter is followed by two integers I and J indicating that
            the product from XI to XJ, inclusive must be calculated (1 ≤ I ≤ J ≤ N).
            Within each test case there is at least one product command.
        */

        for(int i=0; i<k_rounds;i++){

            char command;
            int a, b;
            cin >> command >> a >> b;

            if(command == 'C'){
                initial_values[a-1] = b;
            } else if(command == 'P'){
                int product = product_range(a, b, initial_values);
                // int product = 1;
                // for(int j=a-1; j<b; j++){
                //     product *= initial_values[j];
                // }
                
                /*
                    Output
                    For each test case output a line with a string representing
                        the result of all the product commands in the test case.

                    The i-th character of the string represents the result of
                        the i-th productcommand.

                    If the result of the command is positive
                        the character must be '+' (plus);

                    if the result is negative the character must be '-' (minus);
                    if the result is zero the character must be '0'.
                */

                if(product > 0){
                    output += "+";
                } else if(product < 0){
                    output += "-";
                } else {
                    output += "0";
                }
            }
        }
        cout << output << '\n';
    }
}
