#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+50;
int crivo[maxn];
void crivo_de_eratostenes(){
    for(int i=2;i<maxn;i++){
        if(crivo[i])continue;
        for(int j=2*i;j<maxn;j+=i)
            crivo[j]=1;
    }
}