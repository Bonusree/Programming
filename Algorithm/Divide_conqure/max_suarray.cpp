#include<bits/stdc++.h>
using namespace std;
#define lli long long int
struct parina
{
    lli ki,j,kori=0;
};
parina notunmarge(lli ar[],lli suru,lli majhe,lli ses)
{
    lli danto=INT_MIN,dan=0,bamto=INT_MIN,bam,sobarto=0,i;
    parina kichu;
    for(i=majhe;i>=suru;i--)
    {
        sobarto+=ar[i];
        if(bamto<sobarto)
        {
            bamto=sobarto;
            bam=i;
        }
    }
    sobarto=0;
    for(i=majhe+1;i<=ses;i++)
    {
        sobarto+=ar[i];
        if(danto<sobarto)
        {
            danto=sobarto;
            dan=i;
        }
    }
    if(bamto>danto&&bamto>bamto+danto)
    {
        kichu.ki=bam;
        kichu.j=majhe;
        kichu.kori=bamto;
        return kichu;
    }
    else if(bamto<danto&&danto>bamto+danto)
    {
        kichu.ki=majhe+1;
        kichu.j=dan;
        kichu.kori=danto;
        return kichu;
    }
    else if(bamto+danto>bamto&&danto<bamto+danto)
    {
        kichu.ki=bam;
        kichu.j=dan;
        kichu.kori=bamto+danto;
        return kichu;
    }
}
parina notunsort(lli ar[],lli suru,lli ses)
{
    
    if(suru==ses)
    {
        parina kichu;
        kichu.ki=suru;
        kichu.j=ses;
        kichu.kori=ar[ses];
        return kichu;
    }
    lli mid=(suru+ses)/2;
    parina notun1=notunsort(ar,suru,mid);
    parina notun2=notunsort(ar,mid+1,ses);
    parina marge=notunmarge(ar,suru,mid,ses);
    if(marge.kori>notun1.kori&&marge.kori>notun2.kori)
    return marge;
    else if(notun1.kori>notun2.kori)
    return notun1;
    else
    notun2;
}
int main()
{
    lli n,i,k;
    cin>>n;
    lli ar[n];
    for(i=0;i<n;i++)
    cin>>ar[i];
    parina jokhon=notunsort(ar,0,n-1);
    cout<<jokhon.ki+1<<" "<<jokhon.j+1<<" "<<jokhon.kori<<endl;
    for(i=jokhon.ki;i<=jokhon.j;i++)
    cout<<ar[i]<<" ";
    cout<<endl;
}