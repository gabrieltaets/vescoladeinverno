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

vector<int> grafo[110];
int vis[110];

int bfs(int s){
	queue<int> q;
	vis[s] = 1;
	int cont = 1;
	q.push(s);
	while(!q.empty()){
		int a = q.front();
		q.pop();
		for(int i = 0; i < grafo[a].size(); i++){
			int b = grafo[a][i];
			if(!vis[b]) {
				cont++;
				vis[b] = 1;
				q.push(b);
			}
		}
	}
	return cont;
}

int main(){
	int v, e, caso = 1;
	while(scanf("%d %d",&v,&e) && (v | e)){
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i <= 100; i++){
			grafo[i].clear();
		}
		for(int i = 0; i < e; i++){
			int a, b;
			scanf("%d %d",&a, &b);
			grafo[a].pb(b);
			grafo[b].pb(a);
		}
		printf("Teste %d\n",caso++);
		if(bfs(1) == v){
			printf("normal\n");
		}
		else {
			printf("falha\n");
		}
		printf("\n");
	}
	return 0;
}
