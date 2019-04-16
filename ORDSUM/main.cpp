#include <iostream>
#define MOD 1000000007
using namespace std;

long long int dp[1000006];

int main()
{
    dp[0]=1;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<1000006;i++){
        dp[i]=(dp[i-2]+dp[i-3])%MOD;
    }
    int t,a;
    cin>>t;
    while(t--){
        cin>>a;
        cout<<dp[a]<<"\n";
    }
    return 0;
}
