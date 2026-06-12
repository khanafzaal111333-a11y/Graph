#include<bits/stdc++.h>
using namespace std;
int Time_to_Rott(int n,int m,vector<vector<int>>&grid){
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    queue<pair<pair<int,int>,int>>q;
    int ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=true;
                ans=0;
                while(q.size()>0){
                    int t=q.front().second;
                 ans=max(ans,t);
                 q.pop();
                if(i-1>0||!vis[i][j]||grid[i][j]==1){
                    q.push({{i,j},t+1});
                    vis[i][j]=true;
                }
                  if(i+1>=n||!vis[i][j]||grid[i][j]==1){
                    q.push({{i,j},t+1});
                    vis[i][j]=true;
                }
                  if(j-1>0||!vis[i][j]||grid[i][j]==1){
                    q.push({{i,j},t+1});
                    vis[i][j]=true;
                }
                  if(j+1>=m||!vis[i][j]||grid[i][j]==1){
                    q.push({{i,j},t+1});
                    vis[i][j]=true;
                }
            }
            }
        }
    }
    return (ans>0?ans:-1);
}
int main(){
    vector<vector<int>>grid={{2,1,1,0,0},{1,1,0,0,0},{2,1,1,0,0}};
    int n=grid.size();
    int m=grid[0].size();
    cout<<Time_to_Rott(n,m,grid);
}