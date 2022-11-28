#include "bits/stdc++.h"
using namespace std;
#define lli long long int
lli numberOfChild[200000], diametre[200000], ans = LONG_LONG_MAX, cost = 0;
vector<lli> vc[200000];

void dfs(lli n, lli par)
{
  
  for (auto it : vc[n])
  {
    if (it != par)
    {
     
      dfs(it, n);
     numberOfChild[n]=max(numberOfChild[n],1+numberOfChild[it]);
     
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
    for (lli i = 0; i < n - 1; i++)
    {
      lli a, b;
      cin >> a >> b;
      vc[a].push_back(b);
      vc[b].push_back(a);
    }

    dfs(1, 0);
    for(lli i=1;i<=n;i++)
    cout<<numberOfChild[i]<<endl;
   
   
  }
}
/*
7
1 2 3
1 3 3
2 4 3
3 6 3
3 7 3
2 5 3

*/
