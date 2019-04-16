#include <iostream>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    long long int ans = 0;
    int n,t,c[1003],x,k,cs=0;
    while(true){
        cs++;
        cin>>n;
        if(n==-1) break;
        cout<<"Case "<<cs<<":\n";
        for(int i=0;i<=n;i++) cin>>c[i];
        cin>>k;
        while(k--){
            cin>>x;
            ans = 0;
            for(int i=0;i<n;i++){
                ans+=c[i];
                ans*=x;
            }
            ans+=c[n];
            cout<<ans<<"\n";
        }
    }
    return 0;
}
