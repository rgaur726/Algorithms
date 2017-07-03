#include <bits/stdc++.h>
using namespace std;
pair<int, int> findmax(unordered_map<int, pair<int, int>>hash, int j){
    if(j==0) return hash[0];
    else {
        pair<int,int> maxi = {INT_MIN, INT_MIN};
        for(int k = 0;k<=j;k++)
            if(maxi.first<hash[k].first) maxi = hash[k];
        return maxi;
    }
}
void findsum(int *ar, int n){
    unordered_map<int, pair<int, int>>hash;
    hash[0] = {ar[0],0};
    //int n = sizeof(ar)/sizeof(ar[0]);
    for(int i=1;i<n;i++){
        pair<int, int> a = findmax(hash,i-1);
        if(0>hash[i-1].first) hash[i] = {ar[i],i};
        else hash[i] = {hash[i-1].first+ar[i], a.second};
        }
    int max = INT_MIN;
    pair<int, pair<int, int>> pa;
    for(int i=0;i<n;i++){
        if(hash[i].first>max) {
            pa = {i, hash[i]};
            max = hash[i].first;
        }
    }
    for(int i = pa.second.second;i<=pa.first;i++) cout<<ar[i]<<" ";
    
}
int main(){
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
   int n = sizeof(a)/sizeof(a[0]);
    //int max_sum = maxSubArraySum(a, n);
    findsum(a,n);
}