#include<bits/stdc++.h>
using namespace std;
set<string> s;
string v;
bool chosen[10];
int m[30];
string p;
int fatorial(int n){
    if(n==1||n==0)
        return 1;
    else{
        int i=1,r=1;
        for(i=1;i<=n;i++)
            r=r*i;
        return r;
    }
}
void search(int n){
    if((int)v.size()==n){
        if(s.find(v)==s.end()){
            for(int i=0;i<n;i++)
                cout<<v[i];
            cout<<endl;
            s.insert(v);
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(chosen[i])
                continue;
            chosen[i]=true;
            v.push_back(p[i]);
            search(n);
            chosen[i]=false;
            v.pop_back();
        }
    }
}
int main(){
    cin>>p;
    int n=(int)p.size();
    for(int i=0;i<n;i++)
        m[p[i]-'a']++;
    int r=fatorial(n);
    for(int i=0;i<30;i++)
        r=r/fatorial(m[i]);
    cout<<r<<endl;
    sort(p.begin(),p.end());
    search(n);
    return 0;
}