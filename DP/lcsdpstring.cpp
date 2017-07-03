#include <bits/stdc++.h>
using namespace std;
string s;
string lcs(string x, string y, int m, int n){
   int dp[m+1][n+1];
   for(int i=0;i<m+1;i++){
       for(int j=0;j<n+1;j++){
           if(i==0||j==0)
                dp[i][j]=0;
           else if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
           else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
       }
    }
    int i=m, j=n;
    while (i>0&&j>0){
        if(x[i-1]==y[j-1]) {
            s+=x[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    string s = "Rishabhkdsfdjkslkfdjsl;fm";
    string p = "Rishabhnkfnlksdhflkdasl";
    cout<<lcs(s,p,s.length(), p.size());
}