#include <bits/stdc++.h>
using namespace std;

void genPrefix(string s, int M, int p[])
{
    int i,k;
    p[0]=0;
    k=0;
    i=1;
    while(i<M)
    {
        if(s[i]==s[k])
        {
            k++;
            p[i] = k;
            i++;
        }
        else
        {
            if(k!=0)
                k = p[k-1];
            else
            {
                p[i] = 0;
                i++;
            }
        }
    }

}
void KMPSearch(string s, string t)
{
    int N,M,i,k,p[505];
    N = s.size();
    M = t.size();

    genPrefix(t,M,p);

    for(i=0; i<M; i++)
        cout << p[i] << " ";
    cout << endl;

    i = k = 0;
    while(i < N)
    {
        if(s[i]==t[k])
        {
            i++;
            k++;
        }
        if(k==M)
        {
            cout << "Pattern found at: " << i-k << "\n";
            k = p[k-1];
        }
        else if(i<N && s[i]!=t[k])
        {
            if(k!=0)
                k = p[k-1];
            else
                i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int cases,N,M,i;
    string s,t;

    cin >> cases;

    while(cases--)
    {
        cin >> s >> t;

        KMPSearch(s,t);
        cout << "\n";
    }

    return 0;
}
