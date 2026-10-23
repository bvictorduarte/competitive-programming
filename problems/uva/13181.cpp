#include<bits/stdc++.h>
using namespace std;
int main(){
    string row;
    while(cin>>row){
        vector<int> positions;
        positions.push_back(-1);
        int ans=0;
        for(int i=0;i<(int)row.size();i++)
            if(row[i]=='X')
                positions.push_back(i);
        positions.push_back((int)row.size());
        for(int i=1;i<(int)positions.size();i++){
            if(i!=1&&i!=(int)positions.size()-1){
                int dif=positions[i]-positions[i-1]-1;
                if(dif%2==0)
                    dif-=2;
                ans=max(ans,dif/2);
            }else if(i==1){
                int dif=positions[1];
                ans=max(ans,dif-1);
            }else{
                int dif=positions[(int)positions.size()-1]-positions[(int)positions.size()-2];
                ans=max(ans,dif-2);
            }
        }
        cout<<ans<<endl;
    }
}