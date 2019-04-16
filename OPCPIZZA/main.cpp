#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

int main()
{
    int t;
    ll n,m;
    ll arr[100005];
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int lo=0,hi=n-1;
        ll ans = 0;
        while(lo<hi){
            if(arr[lo]+arr[hi]>m) hi--;
            else if(arr[lo]+arr[hi]<m) lo++;
            else{
                if(arr[lo]==arr[hi]){
                    int clo=0;
                    int tlo=arr[lo];
                    while(arr[lo]==tlo){
                        lo++;
                        clo++;
                    }
                    ans+=(((ll)clo)*((ll)clo-1))/2;
                }
                else{
                    int clo=0;
                    int tlo=arr[lo];
                    while(arr[lo]==tlo){
                        lo++;
                        clo++;
                    }
                    int chi=0;
                    int thi=arr[hi];
                    while(arr[hi]==thi){
                        hi--;
                        chi++;
                    }
                    ans+=((ll)clo)*((ll)chi);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
