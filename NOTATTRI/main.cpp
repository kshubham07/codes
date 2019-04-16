#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,arr[2002];
    while(1){
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int ans = 0;
        for(int i=n-1;i>1;i--){
            for(int j=i-1;j>0;j--){
                ///now binary search 3rd side
                int req = arr[i]-arr[j];
                ///side must be < req
                if(arr[0]>=req) continue;
                int lo = 0, hi = j-1;
                int mid = lo + (hi-lo)/2;
                while(lo<=hi){
                    if(hi==lo){
                        mid=lo;
                        break;
                    }
                    if(hi-lo==1){
                        if(arr[hi]>=req) mid=lo;
                        else mid=hi;
                        break;
                    }
                    if(arr[mid]>=req) hi = mid;
                    else lo = mid;
                }
                ans+=(mid+1);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
