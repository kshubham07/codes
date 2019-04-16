#include <iostream>
#define INF 1000000009
using namespace std;

int main()
{
    int dp[1001] = {0};
    dp[1]=1;
    for(int i=2;i<1001;i++){
        dp[i]=INF;
        for(int j=1;j*j<=i;j++){
            dp[i]=min(dp[i],dp[i-(j*j)]+1);
        }
    }
    int t,a;
    cin>>t;
    while(t--){
        cin>>a;
        cout<<dp[a]<<"\n";
    }
    return 0;
}
