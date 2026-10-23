#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n && n){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string s;
        cin>>s;
        int cont=0;
        for(auto u:s)
            if(u=='E')
                cont--;
            else
                cont++;
        cont=((cont%4)+4)%4;
        if(cont==0)cout<<'N';
        if(cont==1)cout<<'L';
        if(cont==2)cout<<'S';
        if(cont==3)cout<<'O';
        cout<<'\n';
    }
    return 0;
}