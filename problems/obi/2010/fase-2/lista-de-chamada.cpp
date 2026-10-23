#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> t;
    string p;
    int n,m,i;
    scanf("%d", &n);
    scanf("%d", &m);
    while(n--){
        cin>>p;
        t.insert(p);
    }
    set<string>::iterator k;
    i=0;
    for(k=t.begin();k!=t.end();k++){
        if(i==m-1)
            cout<<*k<<"\n";
        i++;
    }
}
