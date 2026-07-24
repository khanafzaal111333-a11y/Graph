#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Edge{
public:
int u,v,wt;
Edge(int u,int v,int wt){
    this->u=u;
    this->v=v;
    this->wt=wt;
}
bool operator<(Edge other){
	return(this->wt < other.wt);
}
};
class graph{
public:
int V;
vector<int>par,rank;
graph(int size){
    V=size;
    for(int i=0;i<V;i++){
        par.push_back(i);
        rank.push_back(0);
    }
}
int find(int x){
    if(par[x]==x){
        return par[x];

    }
    return par[x]=find(par[x]);
}
void unite(int a,int b){
    int parA=find(a);
    int parB=find(b);
    if(parA==parB){
        return;
    }
    if(rank[parA]==par[parB]){
        par[parB]=parA;
        rank[parA]++;
    }
    else if(rank[parA]>rank[parB]){
         par[parB]=parA;
    }
    else{
        par[parA]=parB;
    }
}
int karaskal(vector<Edge>edges){
    sort(edges.begin(),edges.end());
    int MSTcount=0;
    int count=0;
    for(int i=0;i<edges.size()&& count<V;i++){
        Edge e=edges[i];
        int parU=find(e.u);
        int parV=find(e.v);
        if(parU!=parV){
        	unite(e.u,e.v);
        MSTcount+=e.wt;
        count++;
		}
        
    }
    return MSTcount;
}
};
int main(){
    graph g(5);
    vector<Edge>edges={Edge(1,3,10),Edge(3,5,5),Edge(5,2,3),Edge(2,1,4)};
    cout<<g.karaskal(edges);
}