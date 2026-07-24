#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<vector<int>>&g,vector<int>&vis,int n){
	vis[i]=true;
	for(int j=0;j<n;j++){
		if(g[i][j]==1&&!vis[j]){
			dfs(j,g,vis,n);
		}
	}
}
int No_of_provinces(vector<vector<int>>&g,int n){
	
	vector<int>vis(n,false);
	int num=0;
	for(int i=0;i<n;i++){
	if(!vis[i]){
		dfs(i,g,vis,n);
			num++;
		}
	}
	return num;
}
int main(){
	vector<vector<int>>g={{1,1,0,0},{1,1,0,0},{1,1,0,0},{0,0,1,1}};
	cout<<No_of_provinces(g,4);
}