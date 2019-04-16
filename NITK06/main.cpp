#include <iostream>

using namespace std;

int main()
{
    int arr[10004];
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1){
            cout<<"NO\n";
            continue;
        }
        bool ans = true;
        for(int i=n-2;i>=0;i--){
            arr[i]-=arr[i+1];
            if(arr[i]<0){
                ans = false;
                break;
            }
        }
        if(arr[0]!=0) ans = false;
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
