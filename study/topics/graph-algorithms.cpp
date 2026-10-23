#include <bits/stdc++.h>
using namespace std;
/*
                    DFS
                Complexity: O(n+m)

Depht-first search primeiro visita um caminho inteiro, depois retorna
para o primeiro nó que ainda possui caminho para avançar, vai ate o fim
e repete o processo até visitar todos os nós da componente APENAS UMA VEZ.
É conveniente utilizar lista de adjacência.
------------------------------------------------------------------------------------------
*/
const int N=1000;
vector<int> adj[N];
bool visited[N];
void dfs(int s){
    //caso o nó ja tenha sido visitado não faça nada
    if(visited[s]) return;
    //caso não tenha sido visitado agora ele foi visitado.
    visited[s]=true;
    //faça o programa visitar todos os caminhos possiveis alcançar pelo nó s
    for(auto u:adj[s])
        dfs(u);
}

/*
                    BSF
                Complexity: O(n+m)

Breadth-firts search visita os nós em ordem crescente de distância ao nó inicial,
percorredo um nível após o outro.
Útil quando queremos encontrar distâncias de um nó ao nó inicial.
------------------------------------------------------------------------------------------
*/
const int x=3;
queue<int> q;
bool visited[N+1];
int distance[N+1];
/*a partir de um determinado nó x vamos visitar todos os nós que fazem parte da
sua componente. Além disso, também pode-se encontrar a distância entre todos os nós
e x
*/
visited[x]=true;
distance[x]=0;
q.push(x);
while(!q.empty()){
    int s=q.front();q.pop();
    //aqui o nó é processado.
    for(auto u:adj[s]){
        //se ja foi visitado não é incluido na fila
        if(visited[u])continue;
        //aqui ele é incluido na fila pra ser visitado posteriormente.
        q.push(u);
        //encontra a distancia de u para o nó x
        distance[u]=distance[s]+1;
        //marca como visitado para nãos er reincluso na fila.
        visited[u]=true;
    }
}

/*
                Bellman-Ford Algorithm
                    Complexity: O(nm)

O algoritmo de Bellman-Ford encontra as distâncias de todos os nós a um nó inicial x.
A ideia é setar distance[x]=0 e todas as outras distâncias no infinito. Depois percorre-se uma
edge list varias vezes(n-1) pra diminuir o máximo possível as distâncias.
Para encontrar o menor caminho é parecido com uma BFS.
------------------------------------------------------------------------------------------
*/
const int m;
vector<tuple<int,int,int> > edges;
int distance[N];
distance[x]=0;
for(int i=1;i<=N;i++)
    distance[i]=INF;
for(int i=1;i<=n-1;i++)
    for(auto e:edges){
        int a,b,w;
        tie(a,b,w)=e;
        distance[b]=min(distance[b],distance[a]+w);
    }

/*
                    Dikjstra's Algorithm
O algoritmo de Dikjstra encontra as distâncias de todos os pontos a um nó inicial x.
Análogamente ao algoritmo de Bellman-Ford, ele seta a distância de x como 0 e os outros
como infinito. No decorrer da execução ele procura diminuir as distâncias a um nó.
Para diminuir a complexidade(visitando um nó somente uma vez) é necessário visitar sempre
o nó com menor distância para o nó x e encurtar as distâncias dos nós ligados a este nó do
nó inicial. Depois repete-se o processo. A implementação do algoritmo utiliza uma adjacency list.
------------------------------------------------------------------------------------------
*/
priority_queue<pair<int,int>> q;
vector<pair<int,int>> adj[N];
int distance[N];
bool visited[N];
const int INF=1e9+9;
distance[x]=0;
visited[x]=true;
for(int i=1;i<=N;i++)
    distance[x]=INF;
q.push(make_pair(0,x));
while(!q.empty()){
    int s=q.top().second();q.pop();
    if(visited[s])continue;
    visited[s];
    for(auto u:adj[s]){
        int a=u.first,b=u.second;
        if(distance[a]>distance[s]+w){
            distance[a]=distance[s]+w;
            q.push(make_pair(-distance[a],a));
        }
    }
}

/*
                    Floyd-Warshall Algorithm
A ideia do algoritmo é transformar o nó visitado em um nó intermediário e verificar se há
um caminho entre ele e dois nós que diminua a distância desses nós, e então vai tentando
diminuir estas distâncias até não dar mais. O algoritmo opera em O(n^3), mas sua vantagem
é que já determina a distância entre quaisquer dois nós do grafo, sendo possível consultar
em O(1). O algoritmo utiliza a matriz de adjacência. Nós não diretamente iniciados recebem
INF no inicio do programa.
------------------------------------------------------------------------------------------
*/
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=550;
int adj[MAXN][MAXN];
for(int i=1;i<=n;i++)
    for(int k=1;k<=n;k++)
        if(adj[i][k]==0&&i!=k)
            adj[i][k]=INF;
for(int i=1;i<=n;i++)
    for(int k=1;k<=n;k++)
        for(int j=1;j<=n;j++)
            dist[k][j]=min(dist[k][j],dist[i][j]+dist[k][i]);
//aqui adj[a][b] retorna a menor distância entre os nós a e b.
//caso adj[a][b]==INF, então não há caminho possível entre os nós a e b.

/*
                DAG(Directed Acyclic Graph)
Modelar um problema neste tipo de grafo, quando possível, é muito interessante
pois há muitos problemas base que podem ser resolvidos utilizando esse tipo de grafo.
------------------------------------------------------------------------------------------
*/
/*
                    Topological Sorting
Um grafo possui uma Topological Sort se, e somente se, for um DAG. A ideia é ordenar os nós
do grafo de modo que sempre que um há um caminho entre os nós a e b saindo de a e chegando em b,
o nó a vem antes que o nó b na sequência de nós, para todos os nós do grafo.
Para ordenar a ideia é simples. Basta chamar uma DFS em cada um dos nós. Se esse nó já foi visitado
o valor dele é 2, se está sendo visitado(processando seus outros nós vizinhos), recebe o valor 1
se ainda não foi visitado recebe o valor 0. Toda vez que um nó assume o valor 2 significa que todos
os nós antes dele devem o preceder na sequeência, então ele é colocado no fim da sequência. Se em algum
momento for revisitado um nó e o valor ele for 1, significa que há um ciclo e o grafo não é um DAG, logo
não possui Topological Sort. 
*/
void dfs(int x){
    if(visited[x]==1){
        have_cycle=true;
        return;
    }else if(visited[x]==2)return;
    visited[x]=1;
    for(auto u:adj[x])
        dfs(u);
    visited[x]=2;
    top_sort.push(x);
}
/*Um outro modo de fazer a topological sort é usando o Kahn's Algorithm, deste modo a topological sort
que o programa entrega é ordenada também pelo valor do nó. A priority queue é de mínimo.
*/
priority_queue<int,vector<int>,greater<int>>pq;
while(!pq.empty()){
    int x=pq.top();pq.pop();
    top_sort.push_back(x);
    for(auto u:adj[x]){
    in_degree[u]--;
        if(in_degree[u]>0)continue;
        pq.push(u);
    }
}
/*
                Dynamic Programming in Graphs
Algo interessando dos DAG é que há muitos problemas que podem ser resolvidos usando programação dinamica.
Por exemplo: maior ou menor caminho entre dois nós a e b; quantos caminhos distintos existem entre nós a e b;
qual o número máximo ou mínimo de edges em um caminho; Que nós aparece em todo possível caminho. Tais problemas
normalmente não tem solução simples em grafos não DAG. Por isso os DAG são bem interessantes.
                Problema do número de caminhos entre a e b.
A ideia é simplesmente setar dp[a]=1 e usar programação dinâmica pra encontrar dp[b] por meio da seguinte recorrência:
dp[b]=dp[u1]+dp[u2]+..+dp[un], sendo ui os nós que possuem caminhos que chegam no nó b.
                Problema da soma de moedas dando x
A ideia é partir do 0 e avançar pros vértices que distam o valor de uma moeda e indo até chegar na soma S.
*/
/*
                    Successor Graphs
Um Successor Graph possui todos os outdegree iguais a 1. Deste modo pode também ser definido por meio de uma função.
Essa função tem como entrada o ponto do grafo e retorna o filho(unico) desse nó. Definindo como succ(x) tal função temos
que succ(x)=adj[x][0]. Definindo como succ(x,k) o nó que paramos após sair do nó x e andar k vezes no grafo, podemos encontrar
succ(x,k) em O(logk) precalculando succ(x,k) para k potencia de 2, ao invés de só andar normalmente, que seria O(k). Para fazer
o pré-cálculo, podemos utilizar a seguinte recorrência succ(x,k)=succ(x), se k=1; =succ(succ(x,k/2),k/2), que é feito
em O(nlogu), sendo u=MAXK, pois são calculados logu valores para cada nó. Depois basta escrever um k genérico como soma 
de potências de 2 em O(logk).
*/
