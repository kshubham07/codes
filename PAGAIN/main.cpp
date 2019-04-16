#include <bits/stdc++.h>

using namespace std;

bool primes[100005];

int main()
{
    vector<int> p;
    for(int i=2;i<100005;i++){
        if(!primes[i]){
            p.push_back(i);
            for(long long int j=((long long int)i)*i;j<100005;j+=i){
                primes[j]=true;
            }
        }
    }
    unsigned int a;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%u",&a);
        for(unsigned int i=a-1,j=0;j<500;j++,i--){
            /// check if i is prime
            unsigned int ub = sqrt(i)+1;
            bool isprime = true;
            for(int k=0;k<p.size() && p[k]<ub;k++){
                if(i%p[k]==0){
                    isprime = false;
                    break;
                }
            }
            if(isprime){
                printf("%u\n",i);
                break;
            }
        }
    }
    return 0;
}
