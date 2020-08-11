#include <bits/stdc++.h>

using namespace std;



int N;

vector <int> panini;

int mangia()
{
    vector <int> panM(N, 0);
    int i,mag,magtot=0;
    panM[N-1]=1;
    for(i=N-2; i>=0; i--)       //dal penultimo al primo
    {
        mag=0;
        for(int k=i+1; k<N; k++)
        {
            if(panini[i]>panini[k])
                mag=max(mag,panM[k]);
        }
        panM[i]=mag+1;
        magtot=max(magtot, panM[i]);
    }
    return magtot;
}


int main()
{
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //Lettura dati
    cin >> N;

    int parz;
    panini.push_back(-1);
    for(int i=0; i<N; i++)
    {
        cin >> parz;
        panini.push_back(parz);
    }
    //Elaborazione
    int result= mangia();

    //Stampa
    cout << result;
    return 0;
}
