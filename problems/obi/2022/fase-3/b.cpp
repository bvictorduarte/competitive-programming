#include<bits/stdc++.h>
using namespace std;
string s="";
string sum_1(string s){
    int nine=1;
    for(auto u:s)
        if(u!='9')
            nine=0;
    if(nine){
        string y="1";
        for(int i=0;i<(int)s.size();i++)
            y.push_back('0');
        return y;
    }
    for(int i=(int)s.size()-1;i>=0;i--)
        if(s[i]!='9'){
            s[i]=(char)(s[i]+1);
            break;
        }
        else
            s[i]='0';
    return s;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string aux;
        cin>>aux;
        s.push_back(aux[0]);
    }
    int tamt=(int)s.size();
    string ans;
    for(int tam=1;tam<=tamt;tam++){    
        int i=0;
        int tem=1;
        string s1="",s2="";
        for(int j=0;j<tam;j++)
            s1+=s[j];
        i=tam;
        s2=sum_1(s1);
        while(i+(int)s2.size()-1<tamt){
            for(int j=0;j<(int)s2.size();j++)
                if(s[i+j]!=s2[j]){
                    tem=0;
                    break;
                }
            i+=(int)s2.size();
            s2=sum_1(s2);
        }
        if(i!=tamt||!tem){
            continue;
        }
        else{
            ans=s1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}