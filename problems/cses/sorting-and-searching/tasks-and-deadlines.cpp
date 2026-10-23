#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define duracao first
#define limite second
int main(){
    int n;
    vector<pair<ll,ll>> tarefas;
    cin>>n;
    for(int i=0;i<n;i++){
        ll d,l;
        cin>>d>>l;
        tarefas.push_back(make_pair(d,l));
    }
    sort(tarefas.begin(),tarefas.end());
    ll time=0,ans=0;
    for(auto tarefa:tarefas){
        time+=tarefa.duracao;
        ans+=tarefa.limite-time;
    }
    cout<<ans<<endl;
    return 0;
}












