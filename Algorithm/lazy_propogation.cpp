#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mx 10000
lli ar[mx];
struct info 
{
    lli prop,sum;
}tree[mx*3];
void init(lli pos,lli suru,lli ses)
{
    if(suru==ses)
    {
        tree[pos].sum=ar[ses];
        tree[pos].prop=0;
    }
    lli bam=pos*2;
    lli dan=pos*2+1;
    lli mid=(suru+ses)/2;
    init(bam,suru,mid);
    init(dan,mid+1,ses);
    tree[pos].sum=tree[bam].sum+tree[dan].sum;
    tree[pos].prop=0;
}
lli query(lli pos,lli suru,lli ses,lli f,lli l,lli carry=0 )
{
    if(suru>l||ses<f)
    return 0;
    else if(suru>=f&&ses<=l)
    {
        return tree[pos].sum+(l-f+1)*carry;
    }
    lli bam=pos*2;
    lli dan=pos*2+1;
    lli mid=(suru+ses)/2;
   lli q1= query(bam,suru,mid,f,l,tree[pos].prop);
    lli q2=query(dan,mid+1,ses,f,l,tree[pos].prop);
    return q1+q2;
}
void update(lli pos,lli suru,lli ses,lli f,lli l,lli val)
{
    if(suru>l||ses<f)
    return ;
    else if(suru>=f&&ses<=l)
    {
        tree[pos].sum+=(val*(l-f+1));
        tree[pos].prop=val;
        return;
    }
    lli bam=pos*2;
    lli dan=pos*2+1;
    lli mid=(suru+ses)/2;
    update(bam,suru,mid,f,l,val);
    update(dan,mid+1,ses,f,l,val);
    tree[pos].sum=tree[bam].sum+tree[dan].sum+tree[pos].prop;
}
int main()
{
    lli n,ar[mx],i,j,val;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>ar[i+1];
    init(1,1,n);
    cin>>i>>j>>val;
    update(1,1,n,i,j,val);
    cin>>i>>j;
    query(1,1,n,i,j);
}