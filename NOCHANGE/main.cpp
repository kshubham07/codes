#include <iostream>

using namespace std;

int n;
int ps[7];
bool ans;

int dp[100005][7];

void recur(int csum, int pos){
    if(csum>n) return;
    if(pos<0){
        if(csum==n) ans=true;
        return;
    }
    if(dp[csum][pos]!=0) return;

    ///write base case also
    if(csum==n){
        ans = true;
        return;
    }

    /// use next ones now
    recur(csum,pos-1);
    /// use one more of all
    recur(csum+ps[pos],pos);
    dp[csum][pos]=1;
}

void prepare(){
    for(int i=0;i<100005;i++){
        for(int j=0;j<7;j++){
            dp[i][j]=-1;
        }
    }
}

int main()
{
    int x,a;
    cin>>n>>x;
    //prepare();
    for(int i=0;i<x;i++){
        cin>>a;
        if(i==0) ps[i]=a;
        else ps[i]=ps[i-1]+a;
    }
    recur(0,x-1);
    if(ans) cout<<"YES";
    else cout<<"NO";
    return 0;
}
