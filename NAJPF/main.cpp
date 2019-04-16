#include <bits/stdc++.h>

using namespace std;

int fail[1000006];

int main()
{
    int t;
    string s,p;
    cin>>t;
    while(t--){
        cin>>s>>p;
        fail[0]=0;
        int i=1,j=0;
        while(i<p.length()){
            //cout<<"fail "<<i<<"\n";
            if(p[i]==p[j]){
                fail[i]=j+1;
                i++,j++;
            }
            else{
                if(j!=0){
                    j=fail[j-1];
                }
                else{
                    fail[i]=0;
                    i++;
                }
            }
        }
        vector<int> ans;
        ans.clear();
        i=0,j=0;
        int cnt=0;
        while(i<s.length()){
            //cout<<"check "<<i<<" s[i] = "<<s[i]<<" and j="<<j<<" and p[j]="<<p[j]<<"\n";
            if(s[i]==p[j]){
                i++,j++;
                if(j==p.length()){
                    //cout<<"insha allah mil gaya\n";
                    cnt++;
                    ans.push_back(i-j+1);
                    j=fail[j-1];
                }
            }
            else if(i<s.length() && s[i]!=p[j]){
                if(j!=0){
                    j=fail[j-1];
                }
                else{
                    j=0;
                    i++;
                }
            }
        }
        if(cnt>0){
            cout<<cnt<<"\n";
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n\n";
        }
        else{
            cout<<"Not Found\n\n";
        }
    }
    return 0;
}
/**
1
abbasabbasabbazhihiabbasabbazazaad abbasabbaz
*/
