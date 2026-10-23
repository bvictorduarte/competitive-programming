#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string nome, notas;
    getchar();
    while(n--){
        getline(cin, nome);
        getline(cin, notas);
        int cont;
        double nota[5];
        cont = sscanf(notas.c_str(), "%lf %lf %lf %lf", &nota[1], &nota[2], &nota[3], &nota[4]);
        double media = 0;
        for(int i = 1; i <= cont; i++)
            media += nota[i];
        if(cont == 4)
            media -= min(min(nota[1], nota[2]), min(nota[3], nota[4]));
        if(cont <= 2)
            media /= 2.0;
        else
            media /= 3.0;
        printf("%s: %.1lf\n", nome.c_str(), media);
    }
    return 0;
}