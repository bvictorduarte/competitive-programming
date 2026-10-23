#include <bits/stdc++.h>
using namespace std;
int main(){
    int c,n,t,d;
    queue<pair<int, int> > q;
    cin>>c>>n;
    multiset<int> ms;
    for(int i=0;i<c;i++)
        ms.insert(0);
    for(int i=0;i<n;i++){
        scanf("%d%d", &t,&d);
        q.push(make_pair(t,d));
    }
    int ans=0,perm;
    for(int i=0;i<n;i++){
        auto it=ms.begin();
        if((*it)-q.front().first>20)
            ans++;
        if((*it)>q.front().first)
            perm=(*it)+q.front().second;
        else
            perm=q.front().first+q.front().second;
        ms.erase(it);
        ms.insert(perm);
        q.pop();
    }
    cout<<ans<<endl;
    return 0;
}