#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[1003];
    int cs=0;
    while(scanf("%s",s)!=EOF){
        int len = strlen(s);
        int cnt = 0;
        for(int i=len-1;i>0;i--){
            if(s[i]=='0' && s[i-1]=='1'){
                cnt+=2;
            }
        }
        if(s[len-1]=='1') cnt++;
        cs++;
        cout<<"Game #"<<cs<<": "<<cnt<<"\n";
    }
    return 0;
}
