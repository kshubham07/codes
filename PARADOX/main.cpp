#include <bits/stdc++.h>
#define pii pair<int,int>
#define m_p make_pair
using namespace std;

bool error = false;
vector<pii> edg[102];
int col[102];

void dfs(int i){
    if(error) return;
    for(int j=0;j<edg[i].size();j++){
        if(error) return;
        pii nxt = edg[i][j];
        if(col[nxt.first]!=0){
            /// then this better match!
            if(col[nxt.first]!=col[i]*nxt.second){
                error = true;
                return;
            }
        }
        else{
            col[nxt.first]=col[i]*nxt.second;
            dfs(nxt.first);
        }
    }
}

int main()
{
    int t,n;
    while(1){
        cin>>n;
        int a;
        string b;
        if(n==0) break;
        for(int i=0;i<102;i++){
            edg[i].clear();
            col[i]=0;
        }
        error = false;
        for(int i=1;i<=n;i++){
            cin>>a>>b;
            int s = ((b[0]=='f')?-1:1);
            edg[i].push_back(m_p(a,s));
            edg[a].push_back(m_p(i,s));
        }
        for(int i=1;i<=n;i++){
            if(col[i]==0){
                col[i]=1;
                dfs(i);
                if(error){
                    cout<<"PARADOX\n";
                    break;
                }
            }
        }
        if(!error){
            cout<<"NOT PARADOX\n";
        }
    }
    return 0;
}
