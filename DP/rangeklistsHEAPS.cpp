#include <bits/stdc++.h>
using namespace std;
struct Node {
    int value, listnum, index;
};
struct comp{
    bool operator()(const Node l, const Node r){
        return l.value>r.value;
    }
};
pair<int, int> smallestpair(vector<int>list[], int n){
    pair<int, int> p= {0, INT_MAX};
    int high = INT_MIN;
    priority_queue<Node, vector<Node>, comp>pq;
    for(int i=0;i<n;i++) 
        pq.push({list[i][0],i,0});
    for(;;)
    {
        int low = pq.top().value;
        int i=pq.top().listnum;
        int j = pq.top().index;
        pq.pop();
        if(high-low<p.second-p.first) p = {low, high};
        if(j==list[i].size()-1) return p;
        pq.push({list[i][j+1], i, j+1});
        high = max(high, list[i][j+1]);
    }
}
int main()
{   
    int list_num;
    cin>>list_num;
	vector<int> list[] = 
	{
		{ 3, 6, 8, 10, 15 },
		{ 1, 5, 12 },
		{ 4, 8, 15, 16},
		{ 2, 6 }
	};

	pair<int, int> p = smallestpair(list, list_num);
	cout << "Minimum range is " << p.first <<  "-" << p.second << "\n";

	return 0;
}