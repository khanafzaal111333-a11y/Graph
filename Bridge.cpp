#include<bits/stdc++.h>
using namespace std;
class Edge{
	public:
	int V;
	list<int>*l;
	Edge(int size){
		V=size;
		l=new list<int>[V];
	}
	void addEdge(int u,int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
  void Find_bridge(int src,int par,int&time,vector<int>&low,vector<int>&dt){
  	 low[src]=dt[src]=++time;
  	  for(auto it:l[src]){
  	  	    if(dt[it]==-1){
  	  	 	  Find_bridge(it,src,time,low,dt);
  	  	 	  low[src]=min(low[it],low[src]);
  	  	 	  if(low[it]>dt[src])
  	  	 	   cout<<it<<" "<<src<<endl;
  	  	 	
		   }
		   else if(it!=par){
		   	low[src]=min(low[it],dt[src]);
		   }
		}  
  }
};
int main(){
	Edge e(7);
	e.addEdge(1,2);
	e.addEdge(1,4);
	e.addEdge(1,3);
	e.addEdge(2,3);
	e.addEdge(5,3);
	int n=7;
	vector<int>low(n,0);
	vector<int>dt(n,-1);
	int time=0;
	e.Find_bridge(1,0,time,low,dt);
}
