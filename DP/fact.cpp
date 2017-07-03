#include <bits/stdc++.h>
using namespace std;
int fact(int ele, unordered_map<int, int>hash){
    if(hash.find(ele)==hash.end()){
        int answer = ele*fact(ele-1,hash);
        hash[ele] = answer;
    }
    return hash[ele];
}
int main(){
    unordered_map<int, int> hash;
    hash[0]=1;
    hash[1]=1;
    int n;
    cin>>n;
    cout<<fact(n,hash);
}
