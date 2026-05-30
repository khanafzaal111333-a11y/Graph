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
    bool Cycle_Detection_DFShelper(int src,vector<bool>&vis,int par){
        vis[src]=true;
        for(auto it:l[src]){
            if(!vis[it]){
            if (Cycle_Detection_DFShelper( it,vis,src)){
            	return true;
			} 
            }
            else if(it!=par){
               return true;
            }
        }
        return false;
    }
    void Cycle(){
        int src=0;
        vector<bool>vis(V,false);
        int par=0;
     cout<<Cycle_Detection_DFShelper(src,vis,par)<<endl;
    }
};
int main(){
    graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.Cycle();
    
   
}

