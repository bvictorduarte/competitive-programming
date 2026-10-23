#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<int> s;
    set<int> q;
    int h,t,k;
    cin>>h>>t;
    for(int i=0;i<h;i++){
        cin>>k;
        s.insert(k);
        q.insert(k);
    }
    for(int i=0;i<t;i++){
        cin>>k;
        if(!s.empty()){
            auto x=s.lower_bound(k);
            if(x==s.begin()&&(*x)!=k)
                printf("-1\n");
            else{
                if(!(*x==k))
                    x--;
                printf("%d\n", *x);
                s.erase(x);
            }
        }else
            printf("-1\n");

    }
    return 0;
}