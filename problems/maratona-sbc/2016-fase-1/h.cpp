#include<bits/stdc++.h>
using namespace std;
int main(){
    string pc,aux;
    cin>>pc;
    for(auto u:pc){
        if(u=='a'||u=='e'||u=='i'||u=='o'||u=='u')
            aux.push_back(u);
    }
    string aux2;
    for(int i=(int)aux.size()-1;i>=0;i--)
        aux2.push_back(aux[i]);
    if(aux==aux2)
        cout<<"S\n";
    else
        cout<<"N\n";
    return 0;
}