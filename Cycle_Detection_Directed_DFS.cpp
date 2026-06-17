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
    }
    void print(){

        for(int i=0;i<l->size();i++){
            cout<<"index"<<i<<":";
            for(int index:l[i]){
                cout<<index<<endl;
            }
        }
    }
    bool DFS(vector<bool>&vis,vector<bool>&dir,int u){
        vis[u]=true;
        for(auto it:l[u]){
            if(!vis[it]){
                if(DFS(vis,dir,u))return true;
            }
            else if(dir[u]){
                return true;
            }
        }
        dir[u]=false;
        return false;
    }
    bool IsCycle(){
        vector<bool>vis(4,false);
        vector<bool>dir(4,false);
        for(int i=0;i<V;i++){
        if(DFS(vis,dir,i))return true;
    }
     return false;
     }
    
    };
int main(){
    graph g(4);
        g.addEdge(1,0);
        g.addEdge(0,2);
        g.addEdge(2,3);
        g.addEdge(3,0);
    cout<<g.IsCycle()<<endl;

}