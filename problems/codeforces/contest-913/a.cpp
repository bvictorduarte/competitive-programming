#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string pos;
        cin>>pos;
        int c=(pos[0]-'a');
        c++;
        int l=(int)(pos[1]-'0');
        for(int i=1;i<=8;i++){
            if(l!=i)
                cout<<pos[0]<<i<<endl;
        }
        for(int i=0;i<8;i++)
            if('a'+i!=pos[0])
                cout<<(char)('a'+i)<<pos[1]<<endl;
    }
    return 0;
}