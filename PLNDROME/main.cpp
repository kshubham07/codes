#include <iostream>

using namespace std;

int main()
{
    int t,n,cs=0;
    cin>>t;
    while(t--){
        cs++;
        cout<<"Case "<<cs<<":\n";
        cin>>n;
        string s;
        cin>>s;
        int req = n;
        int cnt = n&1;
        for(int i=0;i<n/2;i++){
            if(s[i]==s[n-1-i]) cnt+=2;
        }
        int q;
        cin>>q;
        while(q--){
            int i;
            char x;
            cin>>i>>x;
            i--;
            if((n&1) && (i==(n>>1))){
                s[i]=x;
            }
            else{
                if((s[i]!=s[n-1-i])&&(x==s[n-1-i])) cnt+=2;
                if((s[i]==s[n-1-i])&&(x!=s[n-1-i])) cnt-=2;
                s[i]=x;
            }
            if(cnt==req){
                cout<<"YES\n\n";
            }
            else{
                cout<<"NO\n\n";
            }
        }
    }
    return 0;
}
