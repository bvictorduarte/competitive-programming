#include<bits/stdc++.h>
using namespace std;
int main(){
    int day=0,disp_day=1,m_dia=0,m_tot=0;
    int a,b;
    set<pair<int,int>> s;
    while(cin>>a>>b){
        m_tot+=m_dia;
        day++;
        m_dia+=b;
        s.insert(make_pair(b,a));
        if(disp_day==day){
            auto it=s.end();
            it--;
            auto posi=s.lower_bound(make_pair((*it).first,0));
            m_dia-=(*posi).first;
            disp_day=day+(*posi).second;
            s.erase(posi);
        }
    }
    while(!s.empty()){
        day++;
        m_tot+=m_dia;
        if(disp_day==day){
            auto it=s.end();
            it--;
            auto posi=s.lower_bound(make_pair((*it).first,0));
            m_dia-=(*posi).first;
            disp_day=day+(*posi).second;
            s.erase(posi);
        }
    }
    cout<<m_tot<<endl;
    return 0;
}