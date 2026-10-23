#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,b,p,cont=0;
    vector <int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        if(i==0||v[(int)v.size()-1]<=k){
            v.push_back(k);
            cont++;
        }
        else{
            p=-1;
            b=(int)v.size()/2;
            for(b;b>=1;b/=2)
                while(p+b<(int)v.size()&&k>=v[p+b])p+=b;
            v[p+1]=k;
        }
    }
    printf("%d\n", cont);
    return 0;
}
