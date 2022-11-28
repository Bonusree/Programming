#include<bits/stdc++.h>
using namespace std;
#define lli  int
const lli ma= 30005;
lli ar[ma];
vector<lli> tre[ma*3];

void merge(vector<lli>&v1,vector<lli>&v2,vector<lli>&v)
{
    lli i=0,j=0,n=v1.size(),m=v2.size();
    while(i<n&&j<m)
    {
        if(v1[i]<=v2[j])
        {
            v.push_back(v1[i]);
            i++;
        }
        else
        {
            v.push_back(v2[j]);
            j++;
        }
    }
    while(j<m)
    {
        v.push_back(v2[j]);
        j++;
    }
    while(i<n)
    {
        v.push_back(v1[i]);
        i++;
    }


}
void mt(lli b,lli e,lli n)
{
    if(b>e)
    return;
    if(b==e)
    {
      tre[n].push_back(ar[b]);
      return ;

    }
    lli mid=(b+e)/2;
    mt(b,mid,2*n);
    mt(mid+1,e,2*n+1);
    merge(tre[n*2],tre[n*2+1],tre[n]);
    
}
lli query(lli n,lli b,lli e,lli l,lli r,lli k)
{
    if(r<b||e<l||b>e)
    return 0;
    if(r>=e&&l<=b)
    {
        lli m=upper_bound(tre[n].begin(),tre[n].end(),k)-tre[n].begin();
        return tre[n].size()-m;
    }
    lli mid=(b+e)/2;
    lli q1=query(n*2,b,mid,l,r,k);
    lli q2=query(n*2+1,mid+1,e,l,r,k);
    return q1+q2;
}
int main()
{
    lli i,n,j,k;
   
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    lli l,r,m;
    mt(1,n,1);
    cin>>k;
    while (k--)
    {
       cin>>l>>r>>m;
       lli ans=query(1,1,n,l,r,m);
        cout<<ans<<endl;
       
    }
    
}