#include <bits/stdc++.h>
using namespace std;
int v[100050],aux[100050];
int merge_and_count(int l, int r){
    int cont=0;
    if(l==r)
        return 0;
    int m=(l+r)/2;
    cont+=merge_and_count(l,m);
    cont+=merge_and_count(m+1,r);
    int a=l,b=m+1,i=0;
    while(a<=m&&b<=r){
        if(v[a]<v[b]){
            aux[i]=v[a];
            a++;
        }else{
            cont+=(m-a)+1;
            aux[i]=v[b];
            b++;
        }
        i++;
    }
    if(a==m+1)
        while(b<=r){
            aux[i]=v[b];
            b++;
            i++;
        }
    else
        while(a<=m){
            aux[i]=v[a];
            a++;
            i++;
        }
    i=0;
    for(int j=l;j<=r;j++){
        v[j]=aux[i];
        i++;
    }
    return cont;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<merge_and_count(0,n-1)<<endl;
}