#include <bits/stdc++.h>
using namespace std;
const int maxn = 150;
int tamg[maxn], ramg[maxn];
set<int> amigos;
int main(){
    int n, tatual = 0, T;
    string opant;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        string op;
        int amg;
        cin >> op >> amg;
        if(op != "T")
            amigos.insert(amg);
        if(i != 0){
            if(opant == "T")
                tatual += T;
            else if(op != "T")
                tatual++;
        }
        if(op == "R")
            ramg[amg] = tatual;
        if(op == "E"){
            tamg[amg] += (tatual - ramg[amg]);
            ramg[amg] = -1;
        }
        opant = op;
        T = amg;
    }
    for(auto amg : amigos){
        if(ramg[amg] == -1)
            cout << amg << ' ' << tamg[amg] << endl;
        else
            cout << amg << ' ' << -1 << endl;
    }
    return 0;
}
