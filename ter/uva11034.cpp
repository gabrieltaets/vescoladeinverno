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
	int c;
	scanf("%d",&c);
	while(c--){
		int l, m, a, cont = 0;
		string side;
		queue<int> left, right;
		scanf("%d %d",&l, &m);
		l *= 100;
		for(int i = 0; i < m; i++){
			cin >> a >> side;
			if(side == "left") left.push(a);
			else right.push(a);
		}
		while(!left.empty() || !right.empty()){
			int load = 0;
			while(!left.empty() && 
				load + left.front() <= l){
				load += left.front();
				left.pop();
			}
			if(load == 0 && right.empty()) break;
			cont++;
			load = 0;
			while(!right.empty() &&
				load + right.front() <= l){
				load += right.front();
				right.pop();
			}
			if(load == 0 && left.empty()) break;
			cont++;
		}
		printf("%d\n",cont);
	}
	return 0;
}
