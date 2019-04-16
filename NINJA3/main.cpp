#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll N,a,b;
        cin>>N>>a>>b;
        ll gcd = __gcd(a,b);
        for(int i=0;i<gcd;i++) cout<<N;
        cout<<"\n";
    }
    return 0;
}
