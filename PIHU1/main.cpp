#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t,n;
    bool found = false;
    ll arr[1003];
    cin>>t;
    while(t--){
        found = false;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll sum;
        cin>>sum;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                /// look for k
                int req = sum - arr[i] - arr[j];
                int lo = j+1,hi=n-1,mid;
                while(lo<=hi){
                    mid = lo + (hi-lo)/2;
                    if(arr[mid]==req){
                        found = true;
                        break;
                    }
                    else if(req>arr[mid]){
                        lo = mid+1;
                    }
                    else{
                        hi = mid-1;
                    }
                    if(found) break;
                }
                if(found) break;
            }
            if(found) break;
        }
        if(found) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
