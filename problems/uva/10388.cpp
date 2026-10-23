#include<bits/stdc++.h>
#include<random>
using namespace std;
int main(){
    int t,game_time=1000,tamu1,tamu2,tamd1,tamd2;
    bool have_winner=false;
    scanf("%d", &t);
    while(t--){
        int iu1=0,iu2=0,id1=1,id2=0;
        char up1[30],up2[30],down1[30],donw2[30];
        have_winner=false;
        scanf("%s %s", up1, up2);
        tamd1=tamd2=strlen(up1);
        tamu1=tamu2=0;
        cout<<up1<<endl<<up2<<endl;
        while((game_time--)&&!have_winner){
            if(id1==tamd1-1||iu2==tamd2-1)


        }
    }
    return 0;
    set<int> s;
    s.insert(2);
}