/*
             ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम्।
              उर्वारुकमिव बन्धनान मृत्योर्मुक्षी
-----------------------BONHY-------------------------
*/
#include "bits/stdc++.h"
using namespace std;
#define lli long long int

lli sq[1000003];
lli MOD = 4294967291;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli t = 1, cases = 0;
   // cin >> t;
    while (t--)
    {
        cases++;
        lli n = 0,m,k;
        string s,s1;
        cin>>n>>m>>k;
        vector<lli>node[n+1];
        lli path[n+1][n+1];
        for(lli i=0;i<n+1;i++)
        {
            for(lli j=0;j<n+1;j++)
            path[i][j]=LLONG_MAX;
        }
        for(lli i=0;i<m;i++)
        {
            lli a,b;
            cin>>a>>b;
            node[a].push_back(b);
            node[b].push_back(a);
           
        }
        set<tuple<lli,lli,lli>>st;
        while(k--)
        {
            lli a,b,c;
            cin>>a>>b>>c;
            st.insert({a,b,c});
        }
        path[1][0]=0;
        queue<pair<lli,lli>>q;
        q.push({0,1});
        lli check=0;
       
        while (!q.empty())
        {
            lli par=q.front().first;
            lli child=q.front().second;
            q.pop();
            if(child==n)
            break;
            for(lli i=0;i<node[child].size();i++)
            {
                lli v=node[child][i];
                tuple<lli,lli,lli>tu(par,child,v);

                if(st.find(tu)==st.end()&&path[child][v]==LLONG_MAX)
                {
                    path[child][v]=par;
                   // cout<<child<<" "<<v<<" "<<par<<endl;
                    if(v==n)
                    {
                        check=child;
                        break;
                    }
                    q.push({child,v});
                }

            }
            if(check)
            break;

        }
        if(check==0)
        cout<<"-1"<<endl;
        else{
        vector<lli>ans;
        for(lli i=n;i>=1;)
        {
            ans.push_back(i);
            lli x=i;
            lli y=check;
            i=check;
            check=path[y][x];
            

        }
        cout<<ans.size()-1<<endl;
        for(lli i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
        cout<<endl;
        }
      

    }
}