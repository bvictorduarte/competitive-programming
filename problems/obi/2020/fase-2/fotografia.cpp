#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,l,n,area,area_min,index;
    bool found=false;
    cin>>a>>l>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(!((a<=x&&l<=y)||(a<=y&&l<=x)))continue;
        area=x*y-a*l;
        if(!found){
            found=true;
            area_min=area;
            index=i+1;
        }
        if(area_min>area){
            area_min=area;
            index=i+1;
        }
    }
    if(found)
        cout<<index<<endl;
    else
        cout<<-1<<endl;
    return 0;
}