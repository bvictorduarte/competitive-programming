#include<bits/stdc++.h>
using namespace std;
const int maxN=1<<19;
int tam;
int tree[maxN];
void update(int k, int x){
    k+=tam/2;
    tree[k]=x;
    for(k/=2;k>=1;k/=2)
        tree[k]=max(tree[2*k],tree[2*k+1]);
}
int query(int a, int b){
    a+=tam/2;b+=tam/2;
    int maxi=-1;
    while(a<=b){
        if(a%2==1)maxi=max(maxi,tree[a++]);
        if(b%2==0)maxi=max(maxi,tree[b--]);
        a/=2;b/=2;
    }
    return maxi;
}
vector<int> ans;
int main(){
    int n,m;
    cin>>n>>m;
    tam=1<<((int)log2(n)+2);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        update(i,a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(query(0,n-1)<a)
            ans.push_back(0);
        else{
            int l=0,r=n-1;
            while(1){
                int middle=(l+r)/2;
                if(l==r)break;
                else if(query(l,middle)>=a)
                    r=middle;
                else
                    l=middle+1;
            }
            ans.push_back(l+1);
            update(l,tree[l+tam/2]-a);
        }
    }
    cout<<ans[0];
    for(int i=1;i<m;i++)
        cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}