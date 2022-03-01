// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    const int mod=1e9+7;
    long long help(int n,long long k,int count,vector<vector<long long>> &dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n][count]!=-1)    return dp[n][count];
        long long ans=0;
        if(count==0){
            ans+=((k-1)*help(n-2,k,0,dp))%mod;
            ans+=((k-1)*help(n-1,k,1,dp))%mod;
        }else{
            ans+=((k-1)*help(n-1,k,0,dp))%mod;
            ans+=((k-1)*help(n-2,k,0,dp))%mod;
        }
        
        ans%=mod;
        
        return dp[n][count]=ans;
    }
    long long countWays(int n, int k){
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return (k*help(n-1,k,1,dp)+k*help(n-2,k,0,dp))%mod;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends