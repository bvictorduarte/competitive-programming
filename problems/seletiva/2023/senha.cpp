#include <bits/stdc++.h>
using namespace std;
bool v1,v2,v3,invalida;
int main(){
    string s;
    while(getline(cin,s)){
        invalida=false;
        v1=false;
        v2=false;
        v3=false;
        for(int i=0;i<(int)s.size();i++){
            if(invalida)
                break;
            if(!((s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')))
                invalida=true;
            if((int)s.size()<6||(int)s.size()>32)
                invalida=true;
            if((s[i]>='0'&&s[i]<='9'))
                v1=true;
            if(s[i]>='A'&&s[i]<='Z')
                v2=true;
            if(s[i]>='a'&&s[i]<='z')
                v3=true;
        }
        if(invalida)
            cout<<"Senha invalida.\n";
        else if(v3&&v2&&v1)
            cout<<"Senha valida.\n";
        else
            cout<<"Senha invalida.\n";
        
    }
}