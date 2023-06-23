
#include <bits/stdc++.h>
using namespace std;

void show(list<string> l)
{
    list<string>::iterator i;
    i = l.begin();
    cout << *i;

    for (i++; i != l.end(); i++) // do inicio ao fim de l
        cout << " " << *i;       // imprime elemento apontado
    cout << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    list<string> l1;
    list<string>::iterator i1 = l1.begin();
    list<string> l2;
    list<string>::iterator i2 = l2.begin();

    string input;
    string word;

    getline(cin, input);
    stringstream s1(input);

    while (s1 >> word)
    {
        l1.push_back(word);
    }

    getline(cin, input);
    stringstream s2(input);

    while (s2 >> word)
    {
        l2.push_back(word);
    }

    getline(cin, input);
    stringstream s3(input);

    int append = 0;
    for (i1 = l1.begin(); i1 != l1.end(); i1++)
    {
        if (*i1 == input)
        {
            append = 1;
            l1.insert(i1, l2.begin(), l2.end());
            break;
        }
    }

    if (append == 0)
    {
        l1.insert(i1, l2.begin(), l2.end());
    }

    show(l1);

    return 0;
}
