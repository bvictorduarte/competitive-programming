#include<bits/stdc++.h>
using namespace std;
vector<int> sol;
bool used[10];
int a, b, cont = 0;
bool ver(){
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            if(i != j && abs(i - j) == abs(sol[i] - sol[j]))
                return false;
    return true;
}
void backtrack(int col){
    if(col == 9){
        if(ver()){
            printf("%2d      %d", ++cont, sol[1]);
            for(int j = 2; j <= 8; ++j)
                printf(" %d", sol[j]);
            printf("\n");
        }
    }else{
        for(int i = 1; i <= 8; i++){
            if(used[i] || (i != a && (int)sol.size() == b))
                continue;
            sol.push_back(i);
            used[i] = true;
            backtrack(col + 1);
            sol.pop_back();
            used[i] = false;
        }
    }
}
int main(){
    int q;
    cin >> q;
    while(q--){
        sol.clear();
        sol.push_back(0);
        cont = 0;
        cin >> a >> b;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(1);
        if(q)
            printf("\n");
    }
    return 0;
}