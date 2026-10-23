#include <bits/stdc++.h>
using namespace std;
vector<int> a,b;
int main(){
    int m,n,k,aux;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>aux;
        a.push_back(aux);
    }
    for(int i=0;i<m;i++){
        cin>>aux;
        b.push_back(aux);
    }
    int cont=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int j=0;
    for(int i=0;i<m&&j<n;i++){
        while(j<n&&a[j]<b[i]-k)
            j++;
        if(abs(a[j]-b[i])<=k){
            cont++;
            j++;
        }
    }
    cout<<cont<<endl;
    return 0;
}
