#include <iostream>

using namespace std;
typedef long long int ll;

bool check(ll r, ll n){
    return ((r*(r+2))<=n);
}

int main()
{
    int t,cs=0;
    ll n;
    cin>>t;
    while(t--){
        cs++;
        cin>>n;
        if(n<3){
            cout<<"Case "<<cs<<": 0\n";
            continue;
        }
        ll lo=1,hi=10000007,mid;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(check(mid,n)){
                if(!check(mid+1,n)){
                    break;
                }
                else{
                    lo=mid+1;
                }
            }
            else{
                hi = mid;
            }
        }
        cout<<"Case "<<cs<<": "<<mid<<"\n";
    }
    return 0;
}
