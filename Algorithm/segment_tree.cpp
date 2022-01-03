#include<bits/stdc++.h>
using namespace std;
#define mx 200000
#define  lli long long int
lli tr[mx],trr[mx*3];
void init(lli pos,lli suru,lli ses)
{
    if(suru==ses)
    {
        trr[pos]=tr[ses];
        return;
    }
    lli mid=(suru+ses)/2,bam=pos*2,dan=pos*2+1;
    init(bam,suru,mid);
    init(dan,mid+1,ses);
    trr[pos]=(trr[bam]+trr[dan]);
}
void update(lli pos,lli suru,lli ses,lli up,lli val)
{
    lli i;
    if(up<suru||up>ses)
    {
        return;
    }
    if(up<=suru&&up>=ses)
    {
        trr[pos]+=val;
        return;
    }
    lli mid=(suru+ses)/2,bam=pos*2,dan=pos*2+1;
    update(bam,suru,mid,up,val);
    update(dan,mid+1,ses,up,val);
    trr[pos]=trr[bam]+trr[dan];
}
void update1(lli pos,lli suru,lli ses,lli up)
{
    lli i;
    if(up<suru||up>ses)
    {
        return;
    }
    else if(up<=suru&&up>=ses)
    {
        cout<<trr[pos]<<endl;
        trr[pos]=0;
        return;
    }
    lli mid=(suru+ses)/2,bam=pos*2,dan=pos*2+1;
    update1(bam,suru,mid,up);
    update1(dan,mid+1,ses,up);
    trr[pos]=trr[bam]+trr[dan];
}
lli query(lli pos,lli suru,lli ses,lli up,lli low)
{
    if(up>ses||low<suru)
    {
        return 0;
    }
    else if(suru>=up&&ses<=low)
    {
        
       return trr[pos];
    }
    lli mid=(suru+ses)/2,bam=pos*2,dan=pos*2+1;
    lli q1=query(bam,suru,mid,up,low);
    lli q2=query(dan,mid+1,ses,up,low);
    return (q1+q2);
}
int main()
{
    lli t,cas=0;
    cin>>t;
    while(t--)
    {
        cas++;
    long long int n,q,x,v,i,j,e=0,o=0,m,y,p,a,b;
    char c1,c2;
    string str;
    memset(trr,0,sizeof trr);
    cin>>n>>m;
    for(i=1;i<n+1;i++)
    cin>>tr[i];
    init(1,1,n);
    cout<<"Case "<<cas<<":"<<endl;
    for(i=0;i<m;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>x;
            (update1(1,1,n,x+1));
        }
        else if(a==2)
        {
            cin>>x>>y;
            update(1,1,n,x+1,y);
        }
        else
        {
            cin>>x>>y;
            cout<<query(1,1,n,x+1,y+1)<<endl;
        }
    }
    }
   
}