#include<bits/stdc++.h>
using namespace std;
class Graph{
int V;
list<int>*l;
public:
Graph(int V){
    this->V=V;
    l=new list<int>(V);
}
bool iscycle(int src,vector<bool>&vis,vector<bool>&recpath,vector<vector<int>>&course,int n){
    vis[src]=true;
    recpath[src]=true;
    for(int i=0;i<n;i++){
        int u=course[i][0];
        int v=course[i][1];
        if(u==src){
            if(!vis[v]){
                if(iscycle(v,vis,recpath,course,n))return true;
            }
            else if(recpath[v]){
                return true;
            }
        }
    }
    recpath[src]=false;
    return false;
}
bool coursecheck(){
    vector<bool>vis(V,false);
    vector<bool>recpath(V,false);
    vector<vector<int>>course={{1,0},{1,2},{2,3},{4,3}};
    int n=4;
    for(int i=0;i<n;i++){
        if(iscycle(i,vis,recpath,course,n))return true;
    }
    return false;
}
};
int main(){
    Graph g(5);
    cout<<g.coursecheck()<<endl;
}