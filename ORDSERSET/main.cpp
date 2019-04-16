#include <iostream>

using namespace std;

#define MAX 1000000009

class seg{
    int ss,se;
    int cnt;
    seg * lt;
    seg * rt;

public:
    seg(int _ss, int _se){
        ss = _ss;
        se = _se;
        lt = NULL;
        rt = NULL;
        cnt = 0;
    }

    int query_tree(int qs, int qe){
        if(qs>this->se || qe<this->ss) return 0;
        if(qs<=this->ss && qe>=this->se) return this->cnt;
        int mid = this->ss + (this->se - this->ss)/2;
        int ans = 0;
        if(this->lt!=NULL)
            ans+=this->lt->query_tree(qs,qe);
        if(this->rt!=NULL)
            ans+=this->rt->query_tree(qs,qe);
        return ans;
    }

    int kth_in_tree(int k){
        if(this->ss == this->se) return this->ss;
        if(getcount(this->lt)>=k) return this->lt->kth_in_tree(k);
        else return this->rt->kth_in_tree(k-getcount(this->lt));
    }

    int insert_tree(int ui){
        if(this->ss == this->se){
            this->cnt=1;
        }
        else{
            int mid = this->ss + (this->se - this->ss)/2;
            if(ui<=mid){
                if(this->lt==NULL){
                    this->lt = new seg(this->ss,mid);
                }
                this->lt->insert_tree(ui);
            }
            else{
                if(this->rt==NULL){
                    this->rt = new seg(mid+1,this->se);
                }
                this->rt->insert_tree(ui);
            }
            this->cnt = this->getcount(this->lt) + this->getcount(this->rt);
        }
    }

    int delete_tree(int ui){
        if(this->ss == this->se){
            this->cnt=0;
        }
        else{
            int mid = this->ss + (this->se - this->ss)/2;
            if(ui<=mid){
                if(this->lt!=NULL){
                    this->lt->delete_tree(ui);
                    ///remove lt if not needed
                    if(getcount(this->lt)==0){
                        delete this->lt;
                        this->lt = NULL;
                    }
                }
            }
            else{
                if(this->rt!=NULL){
                    this->rt->delete_tree(ui);
                    ///remove rt if not needed
                    if(getcount(this->rt)==0){
                        delete this->rt;
                        this->rt = NULL;
                    }
                }
            }
            this->cnt = this->getcount(this->lt) + this->getcount(this->rt);
        }
    }

    int getcount(seg * child){
        if(child==NULL) return 0;
        else return child->getcount();
    }

    int getcount(){
        return this->cnt;
    }
};

int main()
{
    seg * st = new seg(-MAX,MAX);
    int q,num,ans;
    char op;
    cin>>q;
    while(q--){
        cin>>op>>num;
        switch(op){
        case 'I' :
            st->insert_tree(num);
            break;
        case 'D':
            st->delete_tree(num);
            break;
        case 'C':
            ans = st->query_tree(-MAX,num-1);
            cout<<ans<<"\n";
            break;
        case 'K':
            if(num>st->getcount()) cout<<"invalid\n";
            else{
                ans = st->kth_in_tree(num);
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
