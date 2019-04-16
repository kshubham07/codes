#include <iostream>

using namespace std;

int arr[2][64];

int main()
{
    int n;
    long long int a;
    cin>>n;
    while(n--){
        cin>>a;
        int pos=0;
        while(a>0){
            arr[a&1][pos]+=1;
            pos++;
            a=a>>1;
        }
        while(pos<64){
            arr[0][pos]++;
            pos++;
        }
    }
    long long int ans = 0;
    for(int i=0;i<64;i++){
        if(arr[0][i]>0 && arr[1][i]>0) ans+=((long long int)1)<<i;
    }
    cout<<ans;
    return 0;
}
