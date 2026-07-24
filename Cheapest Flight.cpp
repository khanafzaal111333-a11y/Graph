#include<bits/stdc++.h>
using namespace std;
class Edge{
	public:
		int weight;
		int neighbour;
		Edge(int u,int v){
		   weight=u;	
			neighbour=v;
		}
};
int Min_stops(vector<vector<Edge>>&g,int k,int src,int dest){
	queue<pair<int,pair<int,int>>>q;
	vector<int>dis(g.size(),INT_MAX);
	q.push({src,{-1,0}});
	while(q.size()>0){
		int val=q.front().first;
		int stops=q.front().second.first;
		int distance=q.front().second.second;
		q.pop();
		for(Edge e:g[val]){
			if(dis[e.neighbour]>distance+e.weight&&stops<k){
				dis[e.neighbour]=distance+e.weight;       
				q.push({e.neighbour,{stops+1,dis[e.neighbour]}});
			}
		}
	}
			return (dis[dest]<INT_MAX?dis[dest]:-1);
	
	
}
int main(){
	vector<vector<Edge>>g(4);
	g[0].push_back(Edge(100,1));
	g[1].push_back(Edge(200,2));
	g[1].push_back(Edge(600,3));
	g[2].push_back(Edge(100,0));
	g[2].push_back(Edge(100,3));
	cout<<Min_stops(g,2,0,3);
	
}