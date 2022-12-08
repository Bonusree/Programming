#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli node=10000;
vector<pair<lli,lli>>vc[node+1];

void prims(lli mul,lli ses)
{
    lli visited[ses+1],cost[ses+1];
    for(lli i=0;i<=ses;i++)
    {
        visited[i]=0;
        cost[i]=INT_MAX;
    }
    priority_queue<pair<lli,lli>>q;
    q.push({0,mul});
    lli khela=0;
    cost[mul]=0;
    vector<lli>ans;
    while(!q.empty())
    {
        lli u=q.top().second;
        lli c=(-1)*q.top().first;
        q.pop();
        if(visited[u]==0)
        {
           visited[u]=1;
           // cout<<aso<<" "<<boso<<endl;
            ans.push_back(u);
            khela+=c;
            for(lli ok=0;ok<vc[u].size();ok++)
            {
                lli v=vc[u][ok].first;
               
                    if(vc[u][ok].second<cost[v])
                    {
                        cost[v]=vc[u][ok].second;
                        q.push({((-1)*cost[v]),v});
                    }
                
            }
        }

    }
    cout<<khela<<endl;
    for(lli i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}
int main()
{
    lli n,i,k,j,m,a,b,c;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
      cin>>a>>b>>c;
     vc[a].push_back({b,c});
      vc[b].push_back({a,c});  
    }
    prims(1,m);

}