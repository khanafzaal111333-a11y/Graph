#include<bits/stdc++.h>
using namespace std;
class Edge{
   public:
   int neighbor;
   int weight;
   Edge(int u,int v){
      weight=u;
      neighbor=v;
   }
   
};
void Ballman(int src,vector<vector<Edge>>g,int v){
   vector<int>dis(v,INT_MAX);
   dis[src]=0;
   for(int i=0;i<v-1;i++){
      for(int u=0;u<v;u++){
         for(Edge e:g[u]){
           if(dis[e.neighbor]>dis[u]+e.weight){
            dis[e.neighbor]=dis[u]+e.weight;
           }
         }
      }

   }
   for(int i=0;i<v;i++){
      cout<<dis[i]<<" ";
   }
}
int main(){
   vector<vector<Edge>>g(3);
   //Balman fails here
   g[0].push_back({-1,1});
   g[1].push_back({-2,2});
   g[2].push_back({-2,0});
   Ballman(0,g,3);
}

