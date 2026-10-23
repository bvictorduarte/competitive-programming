#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a, int b){
    int aa,bb;
    int n=a,p=b;
    aa=a%2;
    bb=b%2;
    if(aa<0)aa+=2;
    if(bb<0)bb+=2;
    a%=m;
    b%=m;
    if(a!=b)
        return a<b;
    if(aa==0&&bb==1)
        return false;
    else if(aa==1&&bb==0)
        return true;
    else if(aa==1&&bb==1)
        return n>p;
    else if(aa==0&&bb==0)
        return n<p;
}
int main(){
    while(cin>>n>>m&&n&&m){
        int k=n;
        vector<int> v;
        while(k--){
            int a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end(),cmp);
        cout<<n<<" "<<m<<endl;
        for(auto u:v)
            cout<<u<<endl;
    }
    cout<<"0 0\n";
    return 0;
}