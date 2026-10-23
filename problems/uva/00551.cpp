#include<bits/stdc++.h>
using namespace std;
int main(){
    string l;
    while(cin>>l){
        int tam=(int)l.size(),p=-1;
        stack<string> s;
        vector<string> ls;
        for(int i=0;i<tam;i++){
            if(i!=tam-1&&l[i]=='*'&&l[i+1]==')'){
                ls.push_back("*)");
                ++i;
            }
            else if(i!=tam-1&&l[i]=='('&&l[i+1]=='*'){
                ls.push_back("(*");
                ++i;
            }else{
                string aux;
                aux.push_back(l[i]);
                ls.push_back(aux);
            }
        }
        tam=(int)ls.size();
        for(int i=0;i<tam;i++){
            if(ls[i]=="("||ls[i]=="{"||ls[i]=="<"||ls[i]=="["||ls[i]=="(*")
                s.push(ls[i]);
            else if(ls[i]==")"){
                if(s.empty()||s.top()!="("){
                    p=i;
                    break;
                }else if(s.top()=="(")
                    s.pop();
            }
            else if(ls[i]=="*)"){
                if(s.empty()||s.top()!="(*"){
                    p=i;
                    break;
                }else if(s.top()=="(*")
                    s.pop();
            }
            else if(ls[i]=="]"){
                if(s.empty()||s.top()!="["){
                    p=i;
                    break;
                }else if(s.top()=="[")
                    s.pop();
            }
            else if(ls[i]=="}"){
                if(s.empty()||s.top()!="{"){
                    p=i;
                    break;
                }else if(s.top()=="{")
                    s.pop();
            }
            else if(ls[i]==">"){
                if(s.empty()||s.top()!="<"){
                    p=i;
                    break;
                }else if(s.top()=="<")
                    s.pop();
            }
        }
        if(p!=-1)
            cout<<"NO "<<p+1<<endl;
        else if(s.empty()&&p==-1)
            cout<<"YES"<<endl;
        else
            cout<<"NO "<<tam+1<<endl;
    }
    return 0;
}