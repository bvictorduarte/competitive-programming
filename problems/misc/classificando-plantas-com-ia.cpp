#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+50;
int planta[maxn][10];
string nome_planta[maxn];
int main(){
    int n;
    scanf("%d",&n);
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        getchar();
        getline(cin,nome_planta[i]);
        for(int j=1;j<=4;j++)
            cin>>planta[i][j];
    }
    int q;
    cin>>q;
    int planta_compara[10];
    for(int i=1;i<=q;i++){
        int ans=10000,index_ans;
        for(int j=1;j<=4;j++)
            cin>>planta_compara[j];
        for(int j=1;j<=n;j++){
            int sum=0;
            for(int k=1;k<=4;k++)
                sum+=(planta_compara[k]-planta[j][k])*(planta_compara[k]-planta[j][k]);
            if(ans>sum){
                ans=sum;
                index_ans=j;
            }
        }
        cout<<nome_planta[index_ans]<<endl;
    }
    return 0;
}