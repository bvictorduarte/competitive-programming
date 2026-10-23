#include <bits/stdc++.h>
using namespace std;
int main(){
    string as,p;
    cin>>as;
    int cont=1;
    string o;
    o.push_back('0');
    do{
        cin>>p;
        if(cont!=1)
            cout<<"\nInstancia "<<cont<<endl;
        else
            cout<<"Instancia "<<cont<<endl;
        vector<int> posi;
        int tam=(int)p.size();
        for(int i=0;i<tam;i++){
            if(p[i]==as[0])
                posi.push_back(i);
        }
        int ans=0;
        for(int i=0;i<(int)posi.size();i++){
            int k=0;
            while(p[posi[i]+k]==as[k]){
                k++;
                if(k==(int)as.size()||posi[i]+k==tam)
                    break;
                ans=k;
            }
            if(k==(int)as.size())
                break;
        }
        if(ans==(int)as.size()-1)
            cout<<"verdadeira\n";
        else
            cout<<"falsa\n";
        cin>>as;
        cont++;
    }while(as!=o);
    return 0;
}