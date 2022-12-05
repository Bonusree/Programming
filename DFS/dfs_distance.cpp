#include "bits/stdc++.h"
using namespace std;
#define lli long long int
lli downPath[200000], dis[200000], ans = LONG_LONG_MAX, cost = 0;
vector<lli> vc[200000];
 
void dfs_downpath(lli n, lli par)
{
  
  for (auto it : vc[n])
  {
    if (it != par)
    {
     
      dfs_downpath(it, n);
     downPath[n]=max(downPath[n],1+downPath[it]);
     
    }
  }
 
}
 
 
void distance_dfs(lli n,lli par,lli par_dis)
{
  
  vector<pair<lli,lli>>children;
  lli ans=0;
 // cout<<"n= "<<n<<endl;
  for(auto it:vc[n])
  {
    if(it!=par)
    {
      
      children.push_back({downPath[it],it});
     
    }
  }
 
 sort(children.rbegin(),children.rend());
 //cout<<n<<endl;
 for(lli i=0;i<children.size();i++)
 {
 // cout<<children[i].first<<" "<<children[i].second<<" "<<n<<" "<<par_dis<<endl;
   if(i==0)
   {
    if(children.size()>1)
    distance_dfs(children[i].second,n,max(children[1].first+2,par_dis+1));
    else
    distance_dfs(children[i].second,n,par_dis+1);

   }
   else
   distance_dfs(children[i].second,n,max(children[0].first+2,par_dis+1));
 }
 dis[n]=max(par_dis,downPath[n]);
}
 
 
int main()
{
  int t=1, cases = 0;
  
  while (t--)
  {
    cases++;
    lli n, m;
    cin >> n ;
    for (lli i = 0; i < n+2; i++)
    {
      vc[i].clear();
      downPath[i] = 0;
    }
    for (lli i = 0; i < n - 1; i++)
    {
      lli a, b;
      cin >> a >> b;
      vc[a].push_back(b);
      vc[b].push_back(a);
    }
 
    dfs_downpath(1, 0);
    distance_dfs(1,0,0);

    for(lli i=1;i<n+1;i++)
    cout<<dis[i]<<" ";
    cout<<endl;
   
   
  }
}
