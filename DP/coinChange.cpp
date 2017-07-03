#include <bits/stdc++.h>
using namespace std;
int coinchange (int denom[], int n, int val){
    int ar[val+1];
    ar[0]=0;
    for(int i=1;i<val+1;i++)  ar[i]=INT_MAX;
    for(int i=0;i<n;i++){
        int k = denom[i];
        for(int j=0;j<val+1;j++)
            if(j>=k) 
                ar[j] = min(ar[j],1+ar[j-k]);
        //for(int i=0;i<val+1;i++) cout<<ar[i]<<" ";cout<<endl;
    }
    return ar[val];
}
int main()
{
	// n coins of given denominations
	int S[] = {1,2,5,1000,500, 100, 50, 20, 10 };
	int n = sizeof(S) / sizeof(S[0]);
	 //int n= sizeof(denom)/sizeof(denom[0]);
	// Total Change required
	int N = 1712;

	cout << "Minimum number of coins required to get desired change is "
			<< coinchange(S, n, N);

	return 0;
}