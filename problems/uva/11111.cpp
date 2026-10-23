#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		stringstream ss(s);
		bool is_matrioshka=true;
		int k;
		stack<int> check_nest,check_size;
		while(ss>>k){
			if(is_matrioshka){
				if(k<0){
					k=-k;
					check_nest.push(k);
					check_size.push(0);
				}else{
					if(!check_nest.empty()&&check_nest.top()==k){
						check_nest.pop();
						int t=k;
						while(check_size.top()!=0&&t>0){
							t-=check_size.top();
							check_size.pop();
						}
						if(t<=0)
							is_matrioshka=false;
						else{
							check_size.pop();
							check_size.push(k);
						}
					}else
						is_matrioshka=false;
				}
			}
		}
		if(!check_nest.empty())
			is_matrioshka=false;
		if(is_matrioshka)
			cout<<":-) Matrioshka!\n";
		else
			cout<<":-( Try again.\n";
	}
	return 0;
}