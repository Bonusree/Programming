#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli node=10000;
struct uff
{
    lli u, v,c;
};
lli pa[node];
vector<uff>vc;
bool operator<(uff a,uff b)
{
    return a.c<b.c;
}
lli find(lli n)
{
    if(pa[n]==n)
    return pa[n];
    else
    return pa[n]=find(pa[n]);
}
void kruskal(lli su)
{
    sort(vc.begin(),vc.end());
    for(lli i=0;i<=su;i++)
    pa[i]=i;
    lli ans=0;
    cout<<endl;
    for(lli i=0;i<su;i++)
    {
        if(find(vc[i].u)!=find(vc[i].v))
        {
            pa[pa[vc[i].u]]=pa[vc[i].v];
            cout<<vc[i].u<<" "<<vc[i].v<<" "<<vc[i].c<<endl;
            ans+=vc[i].c;
        }
    }
    cout<<ans<<endl;

}
int main()
{
    lli n,i,k,j,m,a,b,c;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
      cin>>a>>b>>c;
      vc.push_back({a,b,c});
    }
    kruskal(n);

}