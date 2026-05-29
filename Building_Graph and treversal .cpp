#include<bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list<int> *l;
    public:
    graph(int V){
        this->V=V;
        l=new list<int>[V];
    }
    void addEdge(int u,int v){
         l[v].push_back(u);
         l[u].push_back(v);
    }
    void print(){

        for(int i=0;i<l->size();i++){
            cout<<"index"<<i<<":";
            for(int index:l[i]){
                cout<<index<<endl;
            }
        }
    }
void BFS(){
    queue<int>q;
    vector<bool>v(V,false);
    q.push(0);
    v[0]=true;
    while(q.size()>0){
        int u=q.front();
        q.pop();
     
        cout<<u<<" ";
        for(int i:l[u]){
            if(!v[i]){
                   v[i]=true;
                q.push(i);
            }
        }
    }
}

void DFShelper(int u,vector<bool>v){
    cout<<u<<" ";
    v[u]=true;
    for(int it:l[u]){
        if(!v[it])
        DFShelper(it,v);
    }
}
void DFS(){
    int u=0;
     vector<bool>v(V,false);
     DFShelper(u,v);
}
};
int main(){
    graph g(5);
    
     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(1,3);
     g.addEdge(2,4);
     cout<<"BFS treversal :";
        g.BFS();
        cout<<endl;
        cout<<"DFS treversal :";
        g.DFS();
}