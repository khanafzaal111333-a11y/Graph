#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
public:
int size;
vector<int>par,rank;
DisjointSet(int s){
    size=s;
    for(int i=0;i<size;i++){
        par.push_back(i);
         par.push_back(0);
    }
}
int find(int x){
    if(par[x]==x){
        return par[x];
    }
  return par[x]=find(par[x]);
}
void union_of_set(int a,int b){
     int parA=find(a);
     int parB=find(b);
    if(parA==parB){
      return;
    }
    if(rank[parA]==rank[parB]){
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

};
int main(){
   DisjointSet s(4);
   s.union_of_set(0,1);
   s.union_of_set(2,3);
   s.union_of_set(0,3);
   cout<<s.find(3);
 return 0;
}