#include<bits/stdc++.h>
using namespace std;
map<int, queue<int>> q;
vector<int> subseq;
int main(){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            int a;
            cin >> a;
            q[a].push(i);
        }
        for(int i = 1; i <= m; i++){
            int a;
            cin >> a;
            subseq.push_back(a);
        }
        bool sim = false;
        if(!q[subseq[0]].empty()){
            int idx = q[subseq[0]].front();
            q[subseq[0]].pop();
            if((int)subseq.size() == 1)
                sim = true;
            for(int i = 1; i < m; i++){
                while(!q[subseq[i]].empty() && q[subseq[i]].front() < idx)
                    q[subseq[i]].pop();
                if(q[subseq[i]].empty())
                    break;
                idx = q[subseq[i]].front();
                q[subseq[i]].pop();
                if(i == m - 1)
                    sim = true;
            }
        }
        if(sim)
            cout << "S\n";
        else
            cout << "N\n";
    return 0;
}