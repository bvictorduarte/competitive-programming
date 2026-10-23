#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+50;
int tam, tree[10000000];
void update(int a){
    a+=tam/2;
    tree[a]=(1^tree[a]);
    for(a=a/2;a>=1;a/=2)
        if(tree[2*a]==1&&tree[2*a+1]==1)
            tree[a]=1;
        else
            tree[a]=0;
}
bool query(int a,int b){
    a+=tam/2;b+=tam/2;
    while(a<=b){
        if(a%2==1){
            if(tree[a]==0)return false;
            else a++;
        }
        if(b%2==0){
            if(tree[b]==0)return false;
            else b--;
        }
        a/=2;b/=2;
    }
    return true;
}
int main(){
    int n,q;
    cin>>n>>q;
    tam=1<<((int)log2(n-1)+1);
    tam*=2;
    string s;
    cin>>s;
    for(int i=1;i<(int)s.size();i++)
        if(s[i]!=s[i-1]){
            tree[i-1+tam/2]=0;
            update(i-1);
        }
        else{
            tree[i-1+tam/2]=1;
            update(i-1);
        }
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        int a,b;
        cin>>a>>b;
        if(op==1){
            if(a==b){
                if(a!=n)
                    update(a-1);
                if(a!=1)
                    update(a-2);
            }
            else{
                if(a!=1)
                update(a-2);
                if(b!=n)
                update(b-1);
            }
        }else{
            if(a==b)
                cout<<"Yes\n";
            else if(query(a-1,b-2))
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}