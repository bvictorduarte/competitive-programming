#include<bits/stdc++.h>
using namespace std;
bool participated[150],problems_solved[150][15];
int time_solved[150][15],participant,t,p,quantps[150],totts[150];
bool cmp(int a, int b){
    if(quantps[a]!=quantps[b])
        return quantps[a]>quantps[b];
    if(totts[a]!=totts[b])
        return totts[a]<totts[b];
    return a<b;
}
int main(){
    int k;
    cin>>k;
    string trash;
    getline(cin,trash);
    getline(cin,trash);
    while(k--){
        for(int i=0;i<150;i++){
            for(int k=0;k<15;k++){
                time_solved[i][k]=0;
                problems_solved[i][k]=false;
            }
            participated[i]=false;
            quantps[i]=0;
            totts[i]=0;
        }
        string data;
        vector<int> v;
        while(getline(cin,data)&&data!=""){
            char op;
            istringstream in(data);
            in>>participant>>p>>t>>op;
            if(!participated[participant]){
                v.push_back(participant);
                participated[participant]=true;
            }
            if(problems_solved[participant][p])
                continue;
            if(op=='C'||op=='I'){
                if(op=='C'){
                    problems_solved[participant][p]=true;
                    quantps[participant]++;
                    totts[participant]+=(time_solved[participant][p]+t);
                }else
                    time_solved[participant][p]+=20;
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(auto u:v)
            cout<<u<<" "<<quantps[u]<<" "<<totts[u]<<endl;
        if(k>0)
            cout<<endl;
    }
    return 0;
}