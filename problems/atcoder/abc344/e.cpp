#include<bits/stdc++.h>
using namespace std;
struct p{
    int v;
    p *next,*prev;
};
map<int,struct p*> mp;
void insert_before(struct p *el, int v){
    struct p *node = new struct p;
    node->v=v;
    node->next=el;
    node->prev=el->prev;
    el->prev->next=node;
    el->prev=node;
}
void insert_after(struct p *el, int v){
    struct p *node = new struct p;
    node->v=v;
    node->prev=el;
    node->next=el->next;
    el->next->prev=node;
    el->next=node;
}
void erase(struct p *el){
    el->next->prev=el->prev;
    el->prev->next=el->next;
    delete el;
}
int main(){
    struct p *head,*tail;
    head=new struct p;
    tail=new struct p;
    head->next=tail;
    head->prev=nullptr;
    tail->next=nullptr;
    tail->prev=head;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        insert_before(tail,a);
        mp[a]=tail->prev;
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            insert_after(mp[x],y);
            mp[y]=mp[x]->next;
        }else{
            int x;
            cin>>x;
            erase(mp[x]);
        }
    }
    struct p *it=head;
    it=it->next;
    cout<<it->v;
    while(it->next!=tail){
        it=it->next;
        cout<<" "<<it->v;
    }
    cout<<endl;
    return 0;
}