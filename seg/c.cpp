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
	while(scanf("%d",&n)!=EOF && n){
		map<set<int>, int> m;
		map<set<int>, int>::iterator it;
		int maior = 0, cont = 0;
		for(int i = 0; i < n; i++){
			set<int> s;
			for(int j = 0; j < 5; j++){
				int x;
				scanf("%d",&x);
				s.insert(x);
			}
			m[s]++;
			if(m[s] > maior) maior = m[s];
		}
		for(it = m.begin(); it != m.end(); it++){
			if(it->second == maior){
				cont++;
			}
		}
		printf("%d\n",maior * cont);
	}
	return 0;
}
