#include <bits/stdc++.h>
using namespace std;
int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    vector<int> v1, v2, v3;
        int n, m , k;
        cin>>n>>m>>k;
        int n1 = n,m1=m;
        while(n--){
            int i;
            cin>>i;
            v1.push_back(i);
        }
        while(m--){
            int i;
            cin>>i;
            v2.push_back(i);
        }
        int i=0,j=0;
        while(i<n1&&j<m1){
            if(v1[i]<v2[j]){
                v3.push_back(v1[i]);
                i++;
            }
            else {
                v3.push_back(v2[j]);
                j++;
            }
        }
        while(i<n1){
            v3.push_back(v1[i]);
            i++;
        }
        while(j<m1){
            v3.push_back(v2[j]);
            j++;
        }
        cout<<v3[k-1];
	}
	return 0;
}