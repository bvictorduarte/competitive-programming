#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
int main(){
    vector<pair<int, int> > r1,r2;
    int x,y,i=0,v1=0,v2=0;
    while(i<=1){
        scanf("%d%d", &x,&y);
        r1.PB(MP(x,y));
        i++;
    }
    i=0;
    while(i<=1){
        scanf("%d%d", &x,&y);
        r2.PB(MP(x,y));
        i++;
    }
    if((r2[0].S<r1[0].S)&&(r2[1].S>=r1[0].S))v1=1;
    else if((r2[0].S>=r1[0].S)&&(r2[0].S<=r1[1].S))v1=1;
    if((r2[0].F<r1[0].F)&&(r2[1].F>=r1[0].F))v2=1;
    else if((r2[0].F>=r1[0].F)&&(r2[0].F<=r1[1].F))v2=1;
    if(v1==1&&v2==1)printf("1\n");
    else printf("0\n");
    return 0;
}
