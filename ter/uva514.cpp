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
		int x;
		while(scanf("%d",&x) && x){
			queue<int> q;
			stack<int> s;
			q.push(x);
			for(int i = 1; i < n; i++){
				scanf("%d",&x);
				q.push(x);
			}
			x = 1;
			while(!q.empty()){
				if(x == n+2) break;
				while(!s.empty() && 
					q.front() == s.top()){
					q.pop();
					s.pop();
				}
				if(q.empty()) break;
				if(s.empty() || 
					q.front() != s.top()){
					s.push(x);
					x++;
				}
			}
			printf("%s\n",q.empty()?"Yes":"No");
		}
		printf("\n");
	}
	return 0;
}
