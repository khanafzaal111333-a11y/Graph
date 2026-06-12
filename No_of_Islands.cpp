#include<bits/stdc++.h>
using namespace std;
void checking(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&grid,int n,int m){
    if(i<0||j<0||i>=n||j>=m||grid[i][j]!=1||vis[i][j]){
        return;
    }
    vis[i][j]=true;
    checking(i-1,j,vis,grid,n,m);
    checking(i+1,j,vis,grid,n,m);
    checking(i,j-1,vis,grid,n,m);
    checking(i,j+1,vis,grid,n,m);
}
int DFS(){
    int n=4;
    int m=5;
    vector<vector<int>>grid={{0,0,0,1,1},{0,0,0,1,1},{0,0,1,0,0},{0,0,0,1,1,1}};
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int island=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1&&!vis[i][j]){
                 checking(i,j,vis,grid,n,m);
                island++;
            }
        }
    }
    return island;
}
int main(){
    cout<<"No of island are :"<<DFS()<<endl;
}