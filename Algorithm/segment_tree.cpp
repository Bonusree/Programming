#include <bits/stdc++.h>
using namespace std;
#define lli int
const long long int lim=10e5+3;
lli arr[lim],tree[lim*3];
void init(lli node, lli start, lli end)
{
  if(start==end)
  {
    tree[node]=arr[start];
    return;
  }
  lli mid=(start+end)/2;
  lli left=node*2;
  lli right=node*2+1;
  init(left,start,mid);
  init(right,mid+1,end);
  tree[node]=tree[left]+tree[right];
}
void update(lli node,lli start,lli end,lli i,lli val)
{
  if(i<start||i>end)
  return;
  else if(i==start&&i==end)
  {
   // cout<<tree[start]<<endl;
    tree[node]=val;
    return;
  }
  lli mid=(start+end)/2;
  lli left=node*2;
  lli right=node*2+1;
  update(left,start,mid,i,val);
  update(right,mid+1,end,i,val);
  tree[node]=tree[right]+tree[left];

}

lli query(lli node,lli start,lli end,lli l,lli r)
{
  lli m=0;
  if(r<start||l>end)
  return m;
  else if(l<=start&&r>=end)
  return tree[node];
  lli mid=(start+end)/2;
  lli left=node*2;
  lli right=node*2+1;
  lli q1=query(left,start,mid,l,r);
  lli q2=query(right,mid+1,end,l,r);
  return q1+q2;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
    lli t=1, cases = 0;
   cin>>t;
    while (t--)
    {
      cases++;
      lli n,m;
      cin>>n>>m;
      memset(tree,0,n+2);
      for(lli i=1;i<=n;i++)
      cin>>arr[i];
      init(1,1,n);
      cout<<"Case "<<cases<<":"<<endl;
      while(m--)
      {
        lli a;
        cin>>a;
        if(a==1)
        {
          lli b,c;
          cin>>b>>c;
          update(1,1,n,b+1,c);
        }
        
        else
        {
          lli b,c;
          cin>>b>>c;
          cout<<query(1,1,n,b+1,c+1)<<endl;
        }
      }

    }
}