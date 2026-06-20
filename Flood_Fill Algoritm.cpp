#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&fill,int i,int j,int oldcolour,int newcolour){
    if(i<0||j<0||i>=fill.size()||j>=fill[0].size()||fill[i][j]!=oldcolour||fill[i][j]==newcolour){
        return ;
    }
    fill[i][j]=newcolour;
    dfs(fill,i-1,j,oldcolour,newcolour);
    dfs(fill,i+1,j,oldcolour,newcolour);
    dfs(fill,i,j-1,oldcolour,newcolour);
    dfs(fill,i,j+1,oldcolour,newcolour);
}
vector<vector<int>>flood_fill(){
    vector<vector<int>>fill={{1,1,0,0},{1,1,1,0},{1,1,0,0},{1,1,1,1}};
    dfs(fill,3,3,1,2);
    return fill; 
}
int main(){
    vector<vector<int>>ans=flood_fill();
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            if(j<ans.size()){
            cout<<ans[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}