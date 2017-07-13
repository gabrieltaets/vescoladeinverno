#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n;
	while(scanf("%d",&n) && n){
		priority_queue<int, vector<int>, greater<int> > pq;
		int x;
		for(int i = 0; i < n; i++){
			scanf("%d",&x);
			pq.push(x);
		}
		int total = 0;
		while(pq.size() > 1){
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			pq.push(a + b);
			total += a + b;
		}
		printf("%d\n",total);
	}
	return 0;
}
