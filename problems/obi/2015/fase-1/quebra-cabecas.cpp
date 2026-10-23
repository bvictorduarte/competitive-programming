#include <bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> tras;
    map<int,string> letra;
    int n,f,t;
    string leitura;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        cin>>f>>leitura>>t;
        tras.insert(make_pair(f,t));
        letra.insert(make_pair(f,leitura));
    }
    f=0;
    for(int i=0;i<n;i++){
        cout<<letra[f];
        f=tras[f];
    }
    cout<<endl;
    return 0;
}
