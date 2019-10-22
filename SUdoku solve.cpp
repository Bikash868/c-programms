#include<iostream>
#include<stack>
#include<utility>
#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
using namespace std;
#define N 9
bool in_row(int a[N][N],int row,int num)
{
	for(int i=0;i<9;i++)
	{
		if(a[row][i]==num)
		 return true;
	}
return false;	
}
bool in_col(int a[N][N],int col,int num)
{
	for(int i=0;i<9;i++)
	{
		if(a[i][col]==num)
		 return true;
	}
return false;	
}
bool in_grid(int a[N][N],int row,int col,int num)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i+row][j+col]==num)
			 return true;
		}
	}
return false;	
}
bool is_safe(int a[N][N],int row,int col,int num)
{
	return !in_row(a,row,num) && !in_col(a,col,num) && !in_grid(a,row-row%3,col-col%3,num) &&a[row][col]==0 ;
}
bool solved(int a[N][N])
{
	int row=-1,col=-1;
      for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		 if(a[i][j]==0)
		  {row=i; col=j;
		    break;
		  }
	if(row==-1 && col==-1)
	 return true;
	 
	for(int k=1;k<=9;k++)
	{ if(is_safe(a,row,col,k)){
	   a[row][col]=k;
	   if(solved(a))
	    return true;
	   a[row][col]=0;
       }
	}	  
return false;		
}
void print(int a[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		 cout<<a[i][j]<<" ";
		 
		cout<<endl;
	}
}
int main()
{
int a[N][N]={{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
if(solved(a))
 print(a);
else
cout<<"cant solved";
return 0;  
}
