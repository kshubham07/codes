#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll C[62][62];

int main()
{
    for(int i=0;i<62;i++) C[i][0]=1;
    for(int i=1;i<62;i++){
        for(int j=1;j<62;j++){
            ///iCj
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }

    /**
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<C[i][j]<<"\t";
        }
        cout<<"\n";
    }
    **/

    ll first[62];
    first[0]=first[1]=0;
    for(int i=2;i<62;i++){
        if(i%2==0){
            first[i]=C[i-1][i/2];
        }
        else first[i]=0;
    }
    ll sec[62];
    sec[0]=0;
    for(int i=1;i<62;i++){
        sec[i]=sec[i-1]+first[i];
    }

    /**
    for(int i=0;i<62;i++){
        cout<<i<<" : "<<first[i]<<"\t"<<sec[i]<<"\n";
    }
    **/

    int t;
    ll n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==2){cout<<1<<"\n";continue;}
        ll ans = 0;
        int dig = log2(n);
        cout<<sec[dig]<<"\n";
    }
    return 0;
}
