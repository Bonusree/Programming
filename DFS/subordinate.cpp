#include "bits/stdc++.h"
using namespace std;
#define lli long long int
lli numberOfChild[200000], child[200000], ans = LONG_LONG_MAX, cost = 0;
vector<lli> vc[200000];

void dfs(lli n, lli par)
{
  
  for (auto it : vc[n])
  {
    if (it != par)
    {
     
      dfs(it, n);
     child[n]=1+child[it];
     
    }
  }
 
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
     numberOfChild[i] = 0;
    }
    for (lli i = 1; i < n - 1; i++)
    {
      lli a, b;
      cin >> a ;
      vc[a].push_back(i);
      vc[i].push_back(a);
    }

    dfs(1, 0);
    for(lli i=1;i<=n;i++)
    cout<<child[i]<<endl;
   
   
  }
}

