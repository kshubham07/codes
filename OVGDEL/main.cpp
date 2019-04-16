#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000006
using namespace std;

int main()
{
    int cs=0,t,n,a;
    vector<int> arr;
    cin>>t;
    while(t--){
        arr.clear();
        cs++;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        int good=0;
        for(int i=0;i<n;i++){
            //checking index i for good
            ll e = 1;
            for(int j=0;j<=20;j++){
                //see if arr[i]^j exists in array
                int idx = lower_bound(arr.begin(),arr.end(),e) - arr.begin();
                if(arr[idx]==e){
                    if(idx!=i){
                        good++;
                        break;
                    }
                    else{
                        if(idx<n-1 && arr[idx+1]==e){
                            good++;
                            break;
                        }
                        else{
                            // else go on, you met the same element you started from
                        }
                    }
                }
                e*=arr[i];
                if(e>=MAX) break;
            }
        }
        cout<<"Case "<<cs<<": "<<good<<"\n";
    }
    return 0;
}
