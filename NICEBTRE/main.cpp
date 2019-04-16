#include <iostream>

using namespace std;

int maxd;

int recur(string s, int pos, int c_dep)
{
    //cout<<pos<<" ke saath kya hota hai dekhen\n";
    if(pos==s.length()){
        //cout<<"ha, khatam ho gaya\n";
        return pos;
    }
    if(s[pos]=='l'){
        maxd = max(maxd,c_dep+1);
        //cout<<"ab to leaf se jana hoga "<<pos+1<<" pe, depth hua "<<c_dep+1<<"\n";
        return pos+1;
    }
    else{
        /// go to left subtree
        int np = recur(s,pos+1,c_dep+1);
        int nnp = recur(s,np,c_dep+1);
        //cout<<"abhi jump karayaga apun "<<nnp<<" pe\n";
        return nnp;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        maxd=0;
        string s;
        cin>>s;
        int l = recur(s,0,0);
        if(l!=s.length()){
            cout<<"check l("<<l<<")!=s.length("<<s.length()<<")";
        }
        cout<<maxd-1<<"\n";
    }
    return 0;
}
