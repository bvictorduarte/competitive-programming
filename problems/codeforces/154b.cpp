#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
int crivo[maxn],ligados[maxn];
set<int> multiplos_ligados[maxn];
void crivo_de_eratostenes(int n){
    for(int i=2;i<=n;i++){
        if(crivo[i])continue;
        for(int j=i;j<=maxn;j+=i)
            crivo[j]=i;
    }
}
int imprime_conflito(int n){
    while(n!=1){
        if(!multiplos_ligados[crivo[n]].empty()){
            auto it=multiplos_ligados[crivo[n]].begin();
            return (*it);
        }
        n/=crivo[n];
    }
    return 0;
}
void liga(int n){
    int aux=n;
    ligados[n]=1;
    while(aux!=1){
        multiplos_ligados[crivo[aux]].insert(n);
        aux/=crivo[aux];
    }
}
void desliga(int n){
    int aux=n;
    ligados[n]=0;
    while(aux!=1){
        if(multiplos_ligados[crivo[aux]].find(n)!=multiplos_ligados[crivo[aux]].end())
            multiplos_ligados[crivo[aux]].erase(multiplos_ligados[crivo[aux]].find(n));
        aux/=crivo[aux];
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    crivo_de_eratostenes(n);
    for(int j=1;j<=m;j++){
        string opcao;
        int i,aux;
        cin>>opcao>>i;
        if(opcao=="+"){
            if(ligados[i])
                cout<<"Already on\n";
            else{
                aux=imprime_conflito(i);
                if(aux!=0)
                    cout<<"Conflict with "<<aux<<endl;
                else{
                    liga(i);
                    cout<<"Success\n";
                }
            }
        }else{
            if(!ligados[i])
                cout<<"Already off\n";
            else{
                desliga(i);
                cout<<"Success\n";
            }
        }
    }
    return 0;
}