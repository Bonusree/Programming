#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli node=10000;
lli profit[node+1],pa[node+1];
lli vc[node+1];
void rod(lli n)
{
    lli i,j,k,val=INT_MIN;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            val=max(val,vc[i-1]+vc[j-i-1]);
        }
        profit[i]=val;
        pa[i]=j-i-1;
    }
    for(i=n;i>=0;i--)
    cout<<pa[i]<<" ";
    cout<<endl<<profit[n]<<endl;
}
int main()
{
    lli n,i,k,j,m,a,b,c;
    string s,s1;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>vc[i];
    rod(n);

}