#include "bits/stdc++.h"
using namespace std;
#define lli long long int
lli downPath[200000], diametre[200000], ans = LONG_LONG_MAX, cost = 0;
vector<lli> vc[200000];

void dfs_downpath(lli n, lli par)
{
  for (auto it : vc[n])
  { if (it != par)
    {dfs_downpath(it, n);
     downPath[n]=max(downPath[n],1+downPath[it]);
    }
  }
}
void diametre_dfs(lli n,lli par)
{
  vector<lli>children;
  lli ans=0;
  for(auto it:vc[n])
  {if(it!=par)
    {
      diametre_dfs(it,n);
      children.push_back(downPath[it]);
      ans=max(ans,diametre[it]);
    }
  }
  lli numOFchild=children.size();
  if(numOFchild==0)
  diametre[n]=0;
  else if(numOFchild==1)
  diametre[n]=children[0]+1;
  else
  {
    sort(children.rbegin(),children.rend());
    diametre[n]=2+children[0]+children[1];
  }
  diametre[n]=max(ans,diametre[n]);
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
    diametre_dfs(1,0);
    cout<<diametre[1]<<endl;
   
   
  }
}
