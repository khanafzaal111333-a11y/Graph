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
 int Prims(int src,vector<vector<Edge>>&g,int V){
   int MSTcount=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   vector<bool>inMST(V,false);
   pq.push({0,src});
   while(pq.size()>0){
      int weight=pq.top().first;
      int neighbor=pq.top().second;
      pq.pop();
      if(!inMST[neighbor]){
         inMST[neighbor]=true;
          MSTcount+=weight;
          for(Edge e:g[neighbor]){
            if(!inMST[e.neighbor]){
             pq.push({e.weight,e.neighbor});
            }
          }
      }
   }
   return MSTcount;
 }
 int main(){
    vector<vector<Edge>>g(5);
    g[0].push_back(Edge(1,3));
    g[0].push_back(Edge(2,1));
    g[0].push_back(Edge(3,2));
    g[1].push_back(Edge(2,0));
    g[1].push_back(Edge(4,3));
    g[2].push_back(Edge(0,3));
    g[2].push_back(Edge(5,3));
    g[2].push_back(Edge(6,4));
    g[3].push_back(Edge(5,2));
    g[3].push_back(Edge(4,1));
    g[3].push_back(Edge(7,4));
    g[4].push_back(Edge(6,2));
  
   
    cout<<"MST IS :"<<Prims(0,g,5);

 }