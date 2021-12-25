#include<bits/stdc++.h>
using namespace std;
#define lli long long int
void heapify(lli ar[],lli suru,lli ses)
{
    lli root=suru;
    lli l=suru*2;
    lli r=suru*2+1;
    if(l<ses&&ar[l]>ar[root])
    root=l;
    if(r<ses&& ar[r]>ar[root])
    root=r;
    if(root!=suru)
    {
        swap(ar[root],ar[suru]);
        heapify(ar,root,ses);
    }
}
void heap(lli ar[],lli n)
{
    for(lli i=n/2-1;i>=0;i--)
    heapify(ar,i,n);
    for(lli i=n-1;i>=0;i--)
    {
        swap(ar[i],ar[0]);
        heapify(ar,0,i);
    }
}
int main()
{
    lli n,i,j,k;
    cin>>n;
    lli ar[n];
    for(i=0;i<n;i++)
    cin>>ar[i];
    heap(ar,n);
    for(i=0;i<n;i++)
    cout<<ar[i]<<" ";
    cout<<endl;
}