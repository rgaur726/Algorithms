#include <iostream>
#include <vector>
using namespace std;
int findpt(vector<int>ar, int start, int end){
    while(start<end){
        int mid = (start+end)/2;
        if(ar[mid]>ar[mid-1]&&ar[mid]>ar[mid+1]) return ar[mid];
        else if(ar[mid]>ar[mid-1]&&ar[mid]<ar[mid+1]) start = mid;
        else end = mid;
    }
}
int main(){
    vector<int>v;
    int a;
    while(cin>>a) v.push_back(a);
    int start = 0;
    int end = v.size();
    cout<<findpt(v,start,end);
    return 0;
}