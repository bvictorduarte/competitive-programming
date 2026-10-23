#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,l,b,p,cont,m=-1,tam;
    vector <int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        if(i==0){
            v.push_back(k);
            l=0;
            cont=1;
        }
        else{
            tam=cont;
            b=tam/2;
            p=l;
            for(b;b>=1;b/=2)
                while(p+b<=(int)v.size()-1&&v[p+b]<=k)p+=b;
            if(v[p]==k){
                cont=1;
                l=i;
                v.push_back(k);

            }else{
                cont++;
                v.push_back(k);
                sort(v.begin()+l,v.end());
            }
        }
        m=max(m,cont);
    }
    cout<<m<<endl;
    return 0;
}
