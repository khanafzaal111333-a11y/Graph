#include<bits/stdc++.h>
using namespace std;
class Graph{
int size;
list<int>*l;
public:
Graph(int size){
    this->size=size;
    l=new list<int>[size];
}
void addEdge(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u); 
}
bool Cycle_DetectUndi_BFS(){
    queue<pair<int,int>>q;
    vector<bool>vis(size,false);
    vis[0]=true;
    q.push({0,-1});
    while(q.size()>0){
        int u=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto it:l[u]){
            if(!vis[it]){
                q.push({it,u});
                vis[it]=true;
            }
            else if(it!=par){
                return true;
            }
        }
    }
    return false;
}
};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    cout<<g.Cycle_DetectUndi_BFS()<<endl;
}