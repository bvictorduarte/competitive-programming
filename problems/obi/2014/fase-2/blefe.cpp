#include <bits/stdc++.h>
using namespace std;
int main(){
    multiset<int>::iterator l,r;
    multiset<int> a,b;
    bool ok=true;
    int n,m,err=0;
    cin>>n>>m;
    int k;
    for(int i=0;i<n;i++){
        scanf("%d", &k);
        a.insert(k);
    }
    for(int i=0;i<m;i++){
        scanf("%d", &k);
        if(b.empty()){
            b.insert(k);
            continue;
        }
        l=b.begin();
        r=b.end();
        r--;
        while(!(l==r)){
            if((*l)+(*r)==k)
                break;
            if((*l)+(*r)>k)
                r--;
            else
                l++;
        }
        if((*l)+(*r)!=k&&a.find(k)==a.end()&&ok){
            ok=false;
            err=k;
        }
        b.insert(k);
    }
    if(ok)
        printf("sim\n");
    else
        cout<<err<<endl;
    return 0;
}
