#include<bits/stdc++.h>
using namespace std;
class Graph{
int size;
list<int>*l;
public:
Graph(int V){
    size=V;
    l=new list<int>[size];
}
void addEdge(int u,int v){
    l[u].push_back(v);
}
void dfs(int curr,vector<bool>&vis,stack<int>&s){
    vis[curr]=true;
    for(int it:l[curr]){
        if(!vis[it]){
            dfs(it,vis,s);
        }
    }
    s.push(curr);
}
void topological(){
    vector<bool>vis(size,false);
    stack<int>s;
    for(int i=0;i<size;i++){
    	if(!vis[i])
        dfs(i,vis,s);
    }
    while(s.size()>0){
        cout<<s.top();
        s.pop();

    }

}
};
int main(){
    Graph g(6);
    g.addEdge(3,1);
    g.addEdge(0,1);
    g.addEdge(3,2);
    g.addEdge(4,2);
    g.addEdge(4,5);
    g.addEdge(0,5);   
    g.topological();

}