#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int>lookup;
int knapsack(int v[], int w[], int n, int W){
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0||j==0) dp[i][j]=0;
            else if(w[i]<=j)
            	dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]] , dp[i-1][j]);
        	else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int topdownknapsack(int v[], int wt[], int n, int totalWeight){
	if(n==0||totalWeight==0) return 0;
	if(totalWeight<0) return INT_MIN;
	string key = to_string(n)+"|"+to_string(totalWeight);
	if(lookup.find(key)==lookup.end()){
		int include = v[n-1]+topdownknapsack(v,wt,n-1,totalWeight-wt[n-1]);
		int exclude = knapsack(v,wt,n-1,totalWeight);
		lookup[key] = max(include, exclude);
	}
	return lookup[key];
}
int main()
{
	// Input: set of items each with a weight and a value
	int v[] = { 20, 5, 10, 40, 15, 25 };
	int w[] = {  1, 2,  3,  8,  7, 4 };
	
	// Knapsack capacity
	int W = 10;

	// number of items
	int n = sizeof(v) / sizeof(v[0]);

	cout << "Knapsack value is " << topdownknapsack(v, w, n - 1, W);

	return 0;
}