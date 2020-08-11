/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>
using namespace std;
int N;
vector <int> panini;

int ricky(int i, int j)
{
    //ritorna il massimo numero che posso magna di fronte alla seguenza p[i]
    //non posso mangiare panini di valore inferiore a p[j]
    int a=-1;
    int b=-1;
    if(panini[i]>panini[j])
        a=ricky(i+1,i);
    b=ricky(i+1,j);
    if(a>b)
        return(a);
    else
        return(b);
}

int main()
{
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N;

    int parz;
    panini.push_back(-1);
    for(int i=0; i<N;i++){
        cin >> parz;
        panini.push_back(parz);
    }
    cout << ricky(0,0);
    return 0;
}
