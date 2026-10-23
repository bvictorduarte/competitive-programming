/*
Base Problem:
Suppose that we are given a set of coin values coins = {c1, c2,..., ck } and a
target sum of money n, and we are asked to construct the sum n using as few coins as
possible.

Ideia incial: solve(x)=min(solve(x),solve(x-c)+1).
Algorithm:

int solve(int x){
    if(x<0)
        return INF;
    if(x==0)
        return 0;
    int best=INF;
    for(auto c:coins)
        best=min(best,solve(x-c)+1);
    return best;
}

Agora usando a ideia memoization vamos não recalcular valores na recorrência:
bool ready[n_max];
int value[n_max];
int solve(int x){
    if(x<0)
        return INF;
    if(x==0)
        return 0;
    if(ready[x])
        return value[x];
    int best=INF;
    for(auto c:coins)
        best=min(best,solve(x-c)+1);
    ready[x]=true;
    value[x]=best;
    return best;
}

Podemos escrever tal algoritmo sem usar função recursiva(Iterative Implementation, menores constantes):

int value[n_max];
value[0]=0;
for(int x=1;x<=n;x++){
    value[x]=INF;
    for(auto c:coins)
        if(x-c>=0)
            value[x]=min(value[x],value[x-c]+1);
}

Também podemos apresentar uma solução. A ideia é pegar a moeda retirada numa solução ótima e armazenar.
Depois percorremos as soluções e imprimimos:

int value[n_max];
int first[n_max];
value[0]=0;
for(int x=1;x<=n;x++){
    value[x]=INF;
    for(auto c:coins)
        if(x-c>=0&&value[x-c]+1<value[x]){
            value[x]=value[x-c]+1;
            first[x]=c;
        }
}
while(n>0){
    cout<<first[n]<<" ";
    n-=first[n];
}

Para contar as soluções(não necessariamente ótimas), também pensamos em recursividade.

Ideia incial: solve(x)=solve(x-c1)+solve(x-c2)+...+solve(x-ck). Toda vez que chega em 0 significa que deu certo, afinal
existe uma sequencia de moedas que a soma da exatamente x, então contamos uma solução;

Algorithm:
*/

/*
Para contar as soluções(não necessariamente ótimas) do problema acima, também pensamos em recursividade.

Ideia incial: solve(x)=solve(x-c1)+solve(x-c2)+...+solve(x-ck). Toda vez que chega em 0 significa que deu certo, afinal
existe uma sequencia de moedas que a soma da exatamente x, então contamos uma solução;

Algorithm:

int solve(int x){
    if(x==0)
        return 1;
    if(x<0)
        return 0;
    int ans=0;
    for(auto c:coins)
        ans+=solve(x-c);
    return ans;
}

Usando memoization:

int value[n_max];
bool ready[n_max];
int solve(int x){
    if(x==0)
        return 1;
    if(x<0)
        return 0;
    if(ready[x])
        return value[x];
    int ans=0;
    for(auto c:coins)
        ans+=solve(x-c);
    ready[x]=true;
    value[x]=ans;
    return ans;
}

Com iterative implementation:

int value[n_max];
value[0]=1;
for(int x=1;x<=n;x++){
    value[x]=0;
    for(auto c:coins)
        if(x-c>=0)
            value[x]+=value[x-c];
}

É comum pedir as soluções modulo m. Neste caso o algoritmo fica:

int value[n_max];
value[0]=1;
for(int x=1;x<=n;x++){
    value[x]=0;
    for(auto c:coins)
        if(x-c>=0){
            value[x]+=value[x-c];
            value[x]%=m;
        }
}
*/

/*
Outro problema importante que pode ser resolvido é o Longest Increasing Subsequence.

Ideia: verificamos a solução até a posição k do vetor. quando formos para a próxima posição, precisamos verificar
se adicionando o v[k+1] em alguma sequência é possível que ela seja maior que alguma das sequências anteriores.
Daí basta testar para cada posição anterior a k+1 se é possível fazer uma sequência com v[k+1] e, se for, somamos 1
à solve(i), pois agora foi acrescentado v[k+1] na sequência que antes era até i.

Algorithm

int v[n_max], tam[n_max];
for(int x=0;x<n;x++){
    tam[x]=1;
    for(int i=0;i<x;i++)
        if(v[i]<v[x])
            tam[x]=max(tam[x],tam[i]+1);
}

Também é possível resolver o problema em O(n log n).
*/

/*
Outro clássico problema em Dynamic Programming é o Path in a Grid:
To find a path from the upper-left corner to the lower-right corner
of an n × n grid, with the restriction that we may only move down and right.
Each square contains an integer, and the path should be constructed so that the sum of the
values along the path is as large as possible.

Supondo que para chegar numa posição (y,x) do grid de modo que a soma até ela seja máxima seja
solve(y,x). Veja que solve(y,x)=max(solve(y-1,x),solve(y,x-1))+v[y][x]. Preenchendo o vetor de 1
a n pra não dar problema em memória podemos setar solve(y,x)=0 se x=0 ou y=0 para funcionar quando
x ou y são 1.

Algorithm:

int v[n_max][n_max],solve[n_max][n_max],n;
for(int y=1;y<=n;y++){
    for(int x=1;x<=n;x++){
        solve[y][x]=max(solve[y-1][x],solve[y][x-1])+v[y][x];
    }
}
*/