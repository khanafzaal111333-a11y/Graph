#include<bits/stdc++.h>
using namespace std;
class Edge{
   public:
   int u;
   int v;
   Edge(int v,int u){
    this->u=u;
    this->v=v;
   }
   
};
void Dijkstra(int src,int n,vector<vector<Edge>>&g){
       vector<int>dis(n,INT_MAX);
       dis[src]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
       q.push({dis[src],src});
       while(q.size()>0){
         int u=q.top().second;
         q.pop();
         for(Edge e:g[u]){
            if(dis[e.v]>dis[u]+e.u){
                dis[e.v]=(dis[u]+e.u);
                q.push({dis[e.v],e.v});
            }
         }
       }
       for(int i=0;i<n;i++){
        cout<<"Shortest Path to every node "<<i<<"is  :"<<dis[i]<<" "<<endl;
       }

   }
int main(){
    vector<vector<Edge>>e(7);
    e[0].push_back(Edge(2,1));
    e[0].push_back(Edge(4,2));
    e[1].push_back(Edge(1,2));
    e[1].push_back(Edge(5,4));
    e[2].push_back(Edge(3,3));
    e[3].push_back(Edge(1,4));
    e[3].push_back(Edge(6,5));
    e[4].push_back(Edge(2,5));
    Dijkstra(0,7,e);
}

