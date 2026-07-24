#include<bits/stdc++.h>
using namespace std;
int Distance(int p1,int p2,vector<vector<int>>&l){
	return(abs(l[p1][0]-l[p2][0])+abs(l[p1][1]-l[p2][1]));
}
int Mini_dis_b_nodes(vector<vector<int>>l,int n,int src){
	priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq; //min Heap
	vector<bool>set(n,false);
	pq.push({0,src});
	int MSTcount=0;
	while(pq.size()>0){
		int u=pq.top().first;
		int v=pq.top().second;
		pq.pop();
		if(!set[v]){
			set[v]=true;
			MSTcount+=u;
			for(int i=0;i<n;i++){
				int weight=Distance(v,i,l);
				if(!set[i])
				pq.push({weight,i});
			}
		}
	}
	return MSTcount;
}
int main(){
	vector<vector<int>>l={{0,0},{2,1},{3,2},{4,3}};
	cout<< Mini_dis_b_nodes(l,4,0);
}