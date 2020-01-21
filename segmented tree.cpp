#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define forr(i,n) for(int i=0;i<n;i++)
using namespace std;
int construct_st(int a[],int lo,int hi,int *st,int k)
{
	if(lo==hi)
	{
		st[k]=a[lo];
		return a[lo];
	}
	int mid=(hi+lo)/2;
	int l_m=construct_st(a,lo,mid,st,2*k+1);
	int r_m=construct_st(a,mid+1,hi,st,2*k+2);
	st[k]=min(r_m,l_m);
return st[k];	
}
int* construct(int a[],int n)
{
	int x=(int)ceil(log2(n));//height of tree
	int mx_size=2*pow(2,x)-1;//size of tree
	int *st=new int[mx_size];
	
	construct_st(a,0,n-1,st,0);
	/*cout<<"seg tree is:\n";
	for(int i=0;i<mx_size;i++)
	  cout<<st[i]<<" ";*/
return st;	
}
int find_min_st(int *st,int lo,int hi,int l,int r,int k)
{   
	if(l <=lo && hi<=r) // l  lo k  hi r
	  return st[k];
	if(hi<l || lo>r) // l  r lo hi   or  lo hi l r
	  return INT_MAX;
	    
	int mid=(hi+lo)/2;
	int p=find_min_st(st,lo,mid,l,r,2*k+1);
	int q=find_min_st(st,mid+1,hi,l,r,2*k+2);
	if(p>=q)
	return q;
	else
	return p;
}
void find_min(int *st,int n,int l,int r)
{
	if(l<0 || r>=n){
	 cout<<"range out of bound\n";
	 return;}
	 
	int k=find_min_st(st,0,n-1,l,r,0) ;
	 
cout<<"min in range "<<l<<"to "<<r<<":"<<k<<endl;	 
}
void update_st(int *st,int lo,int hi,int index,int k,int val)
{
	if(index<lo || index>hi)
	 return ;
	 
	st[k]=min(st[k],val);
	if(lo!=hi)
	{
		int mid=(lo+hi)/2;
		update_st(st,lo,mid,index,2*k+1,val);
		update_st(st,mid+1,hi,index,2*k+2,val);
	 } 
}
void update(int *a,int *st,int n,int index,int val)
{
	if(index<0 || index>n)
	{
		cout<<"can't update as Index out of bound\n";
		return ;
	}
	a[index]=val;
	update_st(st,0,n-1,index,0,val);
}
void disp(int a,int n)
{   cout<<"updated array:";
	for(int i=0;i<n;i++)
	 cout<<a[i]<<" ";
	cout<<endl;
}
int main() {
int a[]={5,2,1,3,4,6,7,8,9};
int n=sizeof(a)/sizeof(a[0]);
int *st=construct(a,n); 
int t,index,val;

 int l,r;	
 cin>>l>>r;
 find_min(st,n,l,r);
 cout<<"index:";cin>>index;
 cout<<"value:";cin>>val;
 update(a,st,n,index,val);
 disp(a,n);
return 0;
}
/*
finding maximum in a range
#define ll long long int
ll construct_st(vector<ll>a,int lo,int hi,vector<ll>&st,int k)
{
	if(lo==hi)
	{
		st[k]=a[lo];
		return a[lo];
	}
	int mid=(hi+lo)/2;
	ll l_m=construct_st(a,lo,mid,st,2*k+1);
	ll r_m=construct_st(a,mid+1,hi,st,2*k+2);
	st[k]=max(r_m,l_m);
return st[k];	
}
vector<ll> construct(vector<ll>a,int n)
{
	int x=(int)ceil(log2(n));//height of tree
	int mx_size=2*pow(2,x)-1;//size of tree
	
	vector<ll>st(mx_size,0);
	construct_st(a,0,n-1,st,0);
	
return st;	
}
ll find_max_st(vector<ll>st,int lo,int hi,int l,int r,int k)
{   
	if(l <=lo && hi<=r) // l  lo k  hi r
	  return st[k];
	if(hi<l || lo>r) // l  r lo hi   or  lo hi l r
	  return INT_MIN;
	    
	int mid=(hi+lo)/2;
	ll p=find_max_st(st,lo,mid,l,r,2*k+1);
	ll q=find_max_st(st,mid+1,hi,l,r,2*k+2);
	return p>=q?p:q;
}
ll find_max(vector<ll>st,int n,int l,int r)
{	 
	return find_max_st(st,0,n-1,l,r,0) ;	 
}
*/
