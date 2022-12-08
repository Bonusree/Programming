#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const long long int lim = 10e5 + 3;
lli arr[lim], tree[lim * 3];
vector<lli> createTempArray(string ptr)
{
  lli l=ptr.size(),index=0;
  vector<lli>lps(l+1);
  for(lli i=1;i<l;)
  {
    if(ptr[i]==ptr[index])
    {
      lps[i]=index+1;
      index++;
      i++;
    }
    else{
      if(index!=0)
      index=lps[index-1];
      else
      lps[i]=index,i++;
    }
   // cout<<i<<endl;
  }

  return lps;

}
void kmp(string str,string ptr)
{
  vector<lli>lps=createTempArray(ptr);
  lli i=0,j=0,cnt=0;
 while(i<str.size())
  {
    if(str[i]==ptr[j])
    {
      i++;
      j++;
    }
    else
    {
      if(j!=0) j=lps[j-1];
      else
      i++;
    }

    if(j==ptr.size())
    {
        cnt++;
    }
   // cout<<cnt<<endl;
  }
  cout<<cnt<<endl;

}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lli t = 1, cases = 0;
  cin >> t;
  while (t--)
  {
    cases++;
    lli n, a, b, cnt = 1, mx = 0;
    string str,pat;
    cin>>str>>pat;
    cout<<"Case "<<cases<<": ";
    kmp(str,pat);
   
  }
}