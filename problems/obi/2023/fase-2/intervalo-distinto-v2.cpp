#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+50;
bool na_seq[MAXN];
vector<int> v;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    int l=0,r=0,cont=1;
    na_seq[v[0]]=true;
    while(r<=n-1){
        cont=max(cont,r-l+1);
        if(r==n-1)break;
        r++;
        if(na_seq[v[r]]){
            int k=l;
            while(v[k]!=v[r]){
                na_seq[v[k]]=false;
                k++;
            }
            l=k+1;
        }
        na_seq[v[r]]=true;
    }
    cout<<cont<<endl;
}