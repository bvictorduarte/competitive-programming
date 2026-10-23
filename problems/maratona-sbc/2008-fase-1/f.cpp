#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n&&n){
        vector<int> v;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        int cont=0;
        for(int i=1;i<(int)v.size()-1;i++){
            if(v[i-1]>v[i]&&v[i+1]>v[i])
                cont++;
            else if(v[i-1]<v[i]&&v[i+1]<v[i])
                cont++;
        }
        if((v[0]>v[(int)v.size()-1]&&v[0]>v[1])||(v[0]<v[(int)v.size()-1]&&v[0]<v[1]))
            cont++;
        if((v[(int)v.size()-1]>v[0]&&v[(int)v.size()-1]>v[(int)v.size()-2])||(v[(int)v.size()-1]<v[0]&&v[(int)v.size()-1]<v[(int)v.size()-2]))
            cont++;
        cout<<cont<<endl;
    }
}