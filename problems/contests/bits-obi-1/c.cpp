#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    getchar();
    getchar();
    while(t--){
        vector<string> str;
        char c;
        map<string,double> mp;
        set<string> st;
        while(scanf("%c", &c)&&c!='\n'){
            string s;
            s.push_back(c);
            while(scanf("%c", &c)&&c!='\n')
                s.push_back(c);
            str.push_back(s);
            st.insert(s);
        }
        for(auto s:str)
            mp[s]+=1.0;
        for(auto u:st){
            cout<<u<<" ";
            printf("%.4lf\n", ((mp[u]*100)/(double)str.size()));
        }
        if(t!=0)
            cout<<endl;
    }
    return 0;
}