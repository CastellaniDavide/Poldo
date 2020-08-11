#include <bits/stdc++.h>

using namespace std;



int N;

vector <int> panini;
vector < vector <int> > memoria;

int ricky(int i, int j)
{
    //ritorna il massimo numero che posso magna di fronte alla seguenza p[i]
    //non posso mangiare panini di valore inferiore a p[j]
    if(i!=N)
    {
        if(memoria[i][j]==-1)
        {
            int a=-1;
            int b=-1;
            if(panini[i]>panini[j])
                a=1+ricky(i+1,i);
            b=ricky(i+1,j);
            if(a>b)
            {
                memoria[i][j]=a;
                return(a);
            }
            else
            {
                memoria[i][j]=b;
                return(b);
            }
        }
        else
        {
            return(memoria[i][j]);
        }
    }

    else
    {
        return 0;
    }
}

int main()
{
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    memoria.resize(N);          //inizializzo la memoria
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            memoria[i].push_back(-1);
        }
    }
    int parz;
    panini.push_back(-1);
    for(int i=0; i<N; i++)
    {
        cin >> parz;
        panini.push_back(parz);
    }
    N+=2;
    panini.push_back(-1);
    cout << ricky(1,0);
    return 0;
}
