#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli node=10000;
lli arr[node][node],br[node][node];
void lcs(string s,string s1)
{
    lli l1=s.length();
    lli l2=s1.length();
    lli i,j,k;
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            if(i==0||j==0)
            arr[i][j]=0;
            else
            {
                if(s[i-1]==s1[j-1])
                {
                    arr[i][j]=arr[i-1][j-1]+1;
                    br[i][j]=1;
                }
                else if(arr[i-1][j]>arr[i][j-1])
                {
                    arr[i][j]=arr[i-1][j];
                    br[i][j]=2;
                }
                else
                {
                    arr[i][j]=arr[i][j-1];
                    br[i][j]=3;
                }
            }
        }
    }
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        cout<<br[i][j]<<" ";
        cout<<endl;
    }
    string ans;
    i=l1;
    j=l2;

    while(i>0&&j>0)
    {
        if(br[i][j]==1)
        {
            ans+=s[i-1];
            i--;j--;
        }
        else if(br[i][j]==2)
        i--;
        else
        j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}


int main()
{
    lli n,i,k,j,m,a,b,c;
    string s,s1;
    cin>>s>>s1;
    lcs(s,s1);

}