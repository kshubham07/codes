#include <iostream>

using namespace std;
int fac[1000006];

int st[4*1000006][11];

void _merge(int si, int si2, int si3){
    for(int i=0;i<11;i++){
        st[si][i]=st[si2][i]+st[si3][i];
    }
}

void build_tree(int ss, int se, int si){
    if(ss==se){
        st[si][fac[ss]]++;
        return;
    }
    int mid = ss + (se-ss)/2;
    build_tree(ss,mid,2*si+1);
    build_tree(mid+1,se,2*si+2);
    _merge(si,2*si+1,2*si+2);
}

int query_tree(int ss, int se, int si, int qs, int qe, int c){
    if(ss>qe || se<qs) return 0;
    if(ss>=qs && se<=qe) return st[si][c];
    int mid = ss + (se-ss)/2;
    int aa = query_tree(ss,mid,2*si+1,qs,qe,c) + query_tree(mid+1,se,2*si+2,qs,qe,c);
    return aa;
}

int main()
{
    fac[1]=0;
    for(int i=2;i<1000006;i++){
        if(fac[i]==0){
            fac[i]=1;
            for(int j=i*2;j<1000006;j+=i){
                fac[j]++;
            }
        }
    }
    build_tree(0,1000005,0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans = query_tree(0,1000005,0,a,b,c);
        cout<<ans<<"\n";
    }
    return 0;
}
