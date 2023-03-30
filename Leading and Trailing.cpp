#include <bits/stdc++.h>
using namespace std;
#define lli unsigned long long int
lli u=1000, r, l , d;
map<string , lli>mpp;
lli rc[1009];
lli aPowerb(lli a, lli b)
{
  if(b==0)return 1;
  lli x=aPowerb(a, b/2);
  x=(x*x)%u;
  if(b&1)x=(x*a)%u;
  return x;
}

void solve(lli ca)
{
  lli  n=0,m=0,r = 0, b = 0, cc = LLONG_MIN, k, d, w, a = 0, c = 0;
  
  vector<lli>  arr, brr, crr(m + 1), trr(5);
  map<char, lli> mp, mr;
  vector<pair<lli, string>> vp;
  string str , s, t;
  cin>>n>>m;
  r=aPowerb(n,m);
  
  double p = m * log10(n);
  double ex = p - int(p);
  double lead = pow(10,ex)*100.00;
  cout<<int(lead)<<"...";
  printf("%03d\n",r );


}
int main()
{
  int t = 1, i = 1;
  scanf("%d", &t);

  while (t--)
  {

    solve(i);
    i++;
  }
}