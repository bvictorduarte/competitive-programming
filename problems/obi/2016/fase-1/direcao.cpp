#include<bits/stdc++.h>
#include<string>
using namespace std;
int abs(int k){
    if(k>=0)return k;
    else return -k;
}
int main(){
    vector<int> a;
    string b;
    int i;
    for(i=0;i<2;i++){
        cin>>b;
        if(b.compare("norte")==0)a.push_back(1);
        if(b.compare("leste")==0)a.push_back(2);
        if(b.compare("sul")==0)a.push_back(3);
        if(b.compare("oeste")==0)a.push_back(4);
    }
    printf("%d\n", (abs(a[0]-a[1])>4-abs(a[0]-a[1])) ? (4-abs(a[0]-a[1]))*90 : abs(a[0]-a[1])*90);
    return 0;
}
