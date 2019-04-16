#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll MAX = 100000008;
int arr[MAX];
map<int,bool> mp;

void recur(string a, int numsofar, int mask, int maxdigs, int curdigs){
    if(curdigs==maxdigs){
        // end here
        // cout<<numsofar<<" is found\n";
        if(!arr[numsofar])
            mp[numsofar]=true;
        return;
    }
    numsofar=(numsofar<<3)+(numsofar<<1); // x10
    int len = a.length();
    for(int j=0;j<len;j++){
        if(!(mask&(1<<j))){
            // you can use this as next character
            recur(a,numsofar+a[j]-'0',(mask|(1<<j)),maxdigs,curdigs+1);
        }
    }
}

int main()
{
    arr[0]=arr[1]=true;
    for(int i=2;i<MAX;i++){
        if(!arr[i]){
            for(ll j=((ll)i)*i;j<MAX;j+=i) arr[j]=true;
        }
    }

    int n;
    string a;
    cin>>n;
    while(n--){
        mp.clear();
        cin>>a;
        int len = a.length();
        for(int dig=1;dig<=len;dig++){
            for(int j=0;j<len;j++){
                int num = a[j]-'0';
                recur(a,num,(1<<j),dig,1);
            }
        }
        cout<<mp.size()<<"\n";
    }

    return 0;
}
