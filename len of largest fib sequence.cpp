#include<bits/stdc++.h>
#define ll long long
using namespace std; 
/*
leet code:873. Length of Longest Fibonacci Subsequence
dp[i][j]--->length of longest  fib seq ending with A[i] and A[j]
for all i and j  //O(n^2)
 dp[i][j]=2;

Recurrense reln:
for all i<-- 1 to n
s=0 e=i-1
if(A[s]+A[e]==A[i])
   A[e][i]=max(A[s][e]+1 , A[e][i])

*/
int lenLongestFibSubseq(vector<int>& A) {
        int n=A.size();
        int _m=0,s,e;
        int **dp=new int*[n];
        for(int i=0;i<n;i++)
            dp[i]=new int[n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++ )
                dp[i][j]=2;
        
        for(int i=1;i<n;i++)
        {
            s=0;
            e=i-1;
            while(s<e)
            {
                if(A[s]+A[e]==A[i])
                {
                    dp[e][i]=max(dp[s][e]+1,dp[e][i]);
                    _m=max(dp[e][i],_m);
                    s++;e--;
                }
                else if(A[s]+A[e]<A[i])
                    s++;
                else
                    e--;
            }
            
        }
       if(_m>2)
           return _m;
        else
            return 0;
    }
int main()  
{   int n,x;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
     {
     	cin>>x;v[i]=x;
	 }
	int res=lenLongestFibSubseq(v);
	cout<<"res="<<res<<endl;
    return 0;  
} 
