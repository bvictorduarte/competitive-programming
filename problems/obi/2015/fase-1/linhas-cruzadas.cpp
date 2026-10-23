#include<bits/stdc++.h>
using namespace std;
int v[60050],aux[60050];
int merge_sort(int ini, int fim){
    int i,k,t,cont=0;
    if(ini!=fim){
        cont+=merge_sort(ini,(ini+fim)/2);
        cont+=merge_sort(((ini+fim)/2)+1,fim);
        i=ini;
        k=(ini+fim)/2+1;
        t=ini;
        while(i!=((ini+fim)/2)+1&&k!=fim+1){
            if(v[i]<=v[k]){
                aux[t]=v[i];
                i++;
            }
            else{
                aux[t]=v[k];
                cont+=(fim+ini)/2-i+1;
                k++;
            }
            t++;
        }
        if(i==((ini+fim)/2)+1)
            while(k!=fim+1){
                aux[t]=v[k];
                k++;
                t++;
            }
        else
            while(i!=((ini+fim)/2)+1){
                aux[t]=v[i];
                i++;
                t++;
            }
        for(i=ini;i<=fim;i++)
            v[i]=aux[i];
    }
    return cont;
}
int main(){
    int a,i;
    cin>>a;
    for(i=0;i<a;i++)
        cin>>v[i];
    cout<<merge_sort(0,a-1);
}

