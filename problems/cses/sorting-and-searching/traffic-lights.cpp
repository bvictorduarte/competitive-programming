#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> p;
    multiset<int> d;
    int x,n,k;
    scanf("%d%d", &x, &n);
    p.insert(0);
    p.insert(x);
    d.insert(0);
    d.insert(x);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        auto sup=p.lower_bound(k);
        auto inf=sup;
        inf--;
        p.insert(k);
        d.erase(d.find(*sup-*inf));
        d.insert(*sup-k);
        d.insert(k-*inf);
        auto pbest=d.end();
        pbest--;
        printf("%d", *pbest);
    }
    return 0;
}