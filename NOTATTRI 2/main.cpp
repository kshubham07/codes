#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*vector<int> arr;
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(20);
    arr.push_back(20);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(30);
    arr.push_back(30);
    int pos = lower_bound(arr.begin(),arr.end(),9) - arr.begin();
    cout<<pos;*/
    int n,a;
    vector<int> arr;
    while(1){
        arr.clear();
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin>>a;
            arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        vector<int>::iterator iter1, iter2;
        iter1 = arr.end();
        int ans = 0;
        for(int i=n-1;i>1;i--){
            iter1--;
            iter2 = iter1;
            for(int j=i-1;j>0;j--){
                iter2--;
                ///now binary search 3rd side
                int req = arr[i]-arr[j];
                ///side must be < req
                int mid = lower_bound(arr.begin(),iter2,req) - arr.begin();
                //cout<<"first "<<mid<<" values are < "<<arr[i]<<" - "<<arr[j]<<"\n";
                ans+=(mid);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
