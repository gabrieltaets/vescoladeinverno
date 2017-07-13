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
	int n, m;
	while(scanf("%d %d",&n,&m)!=EOF && (n | m)){
		set<int> jack, jill;
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d",&x);
			jack.insert(x);
		}
		for(int i = 0; i < m; i++){
			int x;
			scanf("%d",&x);
			jill.insert(x);
		}
		set<int>::iterator it;
		int cont = 0;
		for(it = jack.begin(); it != jack.end(); it++){
			int x = *it;
			if(jill.find(x) != jill.end()){
				cont++;
			}
		}
		printf("%d\n",cont);
		jack.clear();
		jill.clear();
	}
	return 0;
}
