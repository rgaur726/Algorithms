#include <bits/stdc++.h>
using namespace std;
struct Node {
    int value, listnum, index;
};
struct comp {
    bool operator()(const Node l, const Node r){
        return l.value>r.value;
    }
};
vector<int> mergeSortedLists(vector<int>list[], int list_num){
    vector<int>answer;
    priority_queue<Node, vector<Node>, comp>pq;
    for(int i=0;i<list_num;i++)
        pq.push({list[i][0], i, 0});
    int k=list_num;
    while(k<pow(list_num,2)+list_num){
        int val = pq.top().value;
        int i = pq.top().listnum;
        int j = pq.top().index;
        pq.pop();
        if(val!=INT_MAX) answer.push_back(val);
        //for(auto it:answer)
        if(j==list[i].size()-1) pq.push({INT_MAX, i, j+1});
        else{
            pq.push({list[i][j+1],i,j+1});
        }
        k++;
    }
    return answer;
   /* while(!pq.top().value!=INT_MAX){
        answer.push_back(pq.top().value);
        pq.pop();
    }*/
}

int main()
{
	vector<int> list[] = 
	{
		{ 1, 5, 8, 10},
		{ 3, 6, 12, 15},
		{ 4, 8, 15, 16},
		{ 5, 9, 17, 18}
	};

	vector<int> p = mergeSortedLists(list, 4);
	for(auto it:p) cout<<it<<" ";
	return 0;
}