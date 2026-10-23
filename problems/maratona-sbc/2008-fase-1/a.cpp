#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
pair<int,int> tree[4*maxn];
int tam;
int n,d;
pair<int,int> query(int a,int b){
    a+=tam/2;
    b+=tam/2;
    pair<int,int> q=tree[a];
    while(a<=b){
        if(a%2==1){
            if(q.first<tree[a].first)
                q=tree[a];
            else if(q.first==tree[a].first&&q.second>tree[a].second)
                q=tree[a];
            a++;
        }
        if(b%2==0){
            if(q.first<tree[b].first)
                q=tree[b];
            else if(q.first==tree[b].first&&q.second>tree[b].second)
                q=tree[b];
            b--;
        }
        b/=2;
        a/=2;
    }
    return q;
}
void add(int a,pair<int,int> p){
    a+=tam/2;
    tree[a]=p;
    for(a/=2;a>=1;a/=2){
        if(tree[2*a].first==tree[2*a+1].first){
            if(tree[2*a].second<tree[2*a+1].second)
                tree[a]=tree[2*a];
            else
                tree[a]=tree[2*a+1];
        }else
            tree[a]=max(tree[2*a],tree[2*a+1]);
    }
}
int main(){
    while(cin>>n>>d&&n&&d){
        tam=1<<((int)log2(n)+2);
        for(int i=1;i<=tam;i++)
            tree[i]={0,0};
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
            add(i+1,{(int)(s[i]-'0'),i+1});
        int j=1;
        for(int i=n-(n-d)+1;i<=n;i++){
            pair<int, int> q=query(j,i);
            cout<<q.first;
            j=q.second+1;
        }
        cout<<endl;
    }
    return 0;
}