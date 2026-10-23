#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string n;
        bool v=false;
        cin>>n;
        int i=(int)n.size()-1;
        if(n[0]>='5')
            v=true;
        if(v){
            cout<<'1';
            n[0]='0';
            while(i>=0){
                if(n[i]>='5'&&n[i]<'9'){
                    n[i]='0';
                    if(n[i-1]<'9')
                        n[i-1]++;
                }
                i--;
            }
            cout<<n<<endl;
        }else{
            
        }
    }
    return 0;
}