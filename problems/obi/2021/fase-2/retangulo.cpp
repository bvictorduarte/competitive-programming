#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0;
    vector<int> v,v1;
    cin>>n;
    v1.push_back(0);
    v.push_back(0);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum+=a;
        if(i!=n-1){
            v1.push_back(a);
            v.push_back(sum);
        }
    }
    if(sum%2!=0||n<4){
        cout<<"N\n";
        return 0;
    }
    sum/=2;
    int r=0,l=0;
    while(r>=l&&r<(int)v.size()&&l>=0){
        if(r==l){
            r++;
            continue;
        }
        if(v[r]-v[l]+v1[l]>sum)
            l++;
        else if(v[r]-v[l]+v1[l]<sum)
            r++;
        else
            break;
    }      
    if(v[r]-v[l]+v1[l]!=sum){
        cout<<"N\n";
        return 0;
    }
    vector<int> v2,v3;
    for(int i=0;i<=n;i++)
        if(i!=l&&i!=r){
            v2.push_back(v[i]);
            v3.push_back(v1[i]);
        }
    r=0,l=0;
    while(r>=l&&r<(int)v2.size()){
        if(r==l){
            r++;
            continue;
        }
        if(v2[r]-v2[l]+v3[l]>sum)
            l++;
        else if(v2[r]-v2[l]+v3[l]<sum)
            r++;
        else
            break;
    }    
    if(v2[r]-v2[l]+v3[l]!=sum){
        cout<<"N\n";
        return 0;
    }
    cout<<"S\n";    
    return 0;
}