#include <iostream>

using namespace std;

int main()
{
    long long int C[65][65];
    for(int i=0;i<65;i++){
        C[0][i]=0;
        C[i][0]=1;
    }
    for(int i=1;i<65;i++){
        for(int j=1;j<65;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    int t;
    long long int n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<65;i++){
            if(C[i][i/2]>=n){
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}
