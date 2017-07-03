#include <bits/stdc++.h>
using namespace std;
int recurse(string x, string y, int m, int n){
    if(m==0||n==0) return 0;
    if(x[m-1]==y[n-1]) return 1 + recurse(x,y,m-1,n-1);
    else return max(recurse(x,y,m-1,n), recurse(x,y,m,n-1));
}
unordered_map<string, int> lookup;
int dpsolution(string x, string y, int m, int n){
    if(m==0||n==0) return 0;
    string key = to_string(m)+"|"+to_string(n);
    if(lookup.find(key)==lookup.end()){
        if(x[m-1]==y[n-1]) lookup[key]=1 + dpsolution(x,y,m-1,n-1);
        else lookup[key] =  max(dpsolution(x,y,m-1,n), dpsolution(x,y,m,n-1));
    }
    return lookup[key];
}
int main(){
    string a = "Rishabhs";
    string b = "Rishakas";
    cout<<dpsolution(a,b,a.length(), b.length());
}