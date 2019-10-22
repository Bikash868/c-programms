#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1e9+7;
#define ll long long 
void disp(vector<vector<int> >res)
{   cout<<"cut edges are:\n";
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i][0]<<" "<<res[i][1]<<endl;
	}
}
void dfs(vector<int>adj[],int s,vector<bool>& vis,int a,int b,int& cnt)
{
	vis[s]=true;
	cout<<" "<<s<<" visited\n";
	 cnt++;
	for(int i=0;i<adj[s].size();i++)
	{
		int v=adj[s][i];
		if(s==a && v==b || s==b && v==a)
		  continue;
		if(!vis[v])
		 dfs(adj,v,vis,a,b,cnt);  
	}
}
int main()
{ 
int n,e,x,y;
cin>>n>>e;
vector<int>adj[n];
vector<vector<int> >edges;
for(int i=0;i<e;i++)
{
	cin>>x>>y;
	vector<int>vec;vec.push_back(x);vec.push_back(y);
	edges.push_back(vec);
	adj[x].push_back(y);
	adj[y].push_back(x);
}
vector<vector<int> >res;

for(int j=0;j<e;j++)
{    int cnt=0;
    int a=edges[j][0],b=edges[j][1];
    cout<<"OFF:"<<a<<"-"<<b<<endl;
     vector<bool>vis(n);
	for(int i=0;i<n;i++)
	{  
	    
		if(!vis[i]){
		 cout<<"i="<<i<<":\n";
		 dfs(adj,i,vis,a,b,cnt);
		  if(cnt!=n)
		   break;
		 }	
	}
	if(cnt!=n)
		res.push_back(edges[j]);
	
}
    disp(res);
    return 0;
}
