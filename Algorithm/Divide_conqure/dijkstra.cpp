#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli node=10000;
vector<pair<lli,lli>>hotehobe[node+1];

void nahoilemair(lli mul,lli ses)
{
    lli dekhbo[ses+1],nibo[ses+1];
    for(lli i=0;i<=ses;i++)
    {
        dekhbo[i]=0;
        nibo[i]=INT_MAX;
    }
    priority_queue<pair<lli,lli>>kahini;
    kahini.push({0*(-1),mul});
    nibo[mul]=0;
    lli khela=0;
    vector<lli>ekhnses;
    while(!kahini.empty())
    {
        lli aso=kahini.top().second;
        lli boso=(-1)*kahini.top().first;
        kahini.pop();
            cout<<aso<<" "<<boso<<endl;
            for(lli ok=0;ok<hotehobe[aso].size();ok++)
            {
                lli ghumao=hotehobe[aso][ok].first;
               
                    if(hotehobe[aso][ok].second+boso<nibo[ghumao])
                    {
                        nibo[ghumao]=hotehobe[aso][ok].second+boso;
                        kahini.push({((-1)*nibo[ghumao]),ghumao});
                    }
                
            }
        

    }
   // cout<<khela<<endl;
    for(lli i=1;i<=ses;i++)
    cout<<i<<" "<<nibo[i]<<endl;
}
int main()
{
    lli n,i,k,j,m,a,b,c;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
      cin>>a>>b>>c;
      hotehobe[a].push_back({b,c});
      hotehobe[b].push_back({a,c});  
    }
    nahoilemair(1,m);

}