#include <bits/stdc++.h>
using namespace std;
const int inf =1000000000;
void marge (int arr[],int l,int mid,int r )
{
    int n1= mid -l+1;
    int n2= r-mid ;
    int a[n1+1],b[n2+1];
    int i,j,k;
     
    for(i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
      
    }
    for(j =0;j<n2;j++)
    {
        b[j]=arr[mid+j+1] ;
    }
    i=0;
    j=0;
    a[n1]=INT_MAX;
    b[n2]=INT_MAX;
    for (k=l;k<=r;k++)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            i=i+1;
        }
        else
        {
            arr[k]=b[j];
            j=j+1;
        }
    }
   


}
void margeSort (int arr[],int l,int r )
{
    if(l<r){
        int mid =(l+r)/2;
        margeSort(arr,l,mid);
        margeSort(arr,mid+1,r);
        marge(arr,l,mid,r);
    }
    else
    return ;
    
}
int main ()
{
    int arr[]={0,4,3,2,1};
    margeSort(arr,0,4);
    for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
    return 0;
}