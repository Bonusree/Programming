#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const int no=1000;
lli r[no+1][no+1];
void shikhchikintu(lli mone[],lli nai)
{
    for(lli ki=1;ki<nai;ki++)
    {
        for(lli j=1;j<nai-ki;j++)
        {
            lli kori=j+ki;
            r[j][kori]=INT_MAX;
            for(lli na=j;na<kori;na++)
            {
                r[j][kori]=min(r[j][kori],r[j][na]+r[na+1][kori]+mone[j-1]*mone[kori]*mone[na]);

            }
        }
    }
    
}
int main()
{
    lli n,i,k,j;
    cin>>n;
    lli ar[n];
    for(i=0;i<n;i++)
    cin>>ar[i];
    shikhchikintu(ar,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<r[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}