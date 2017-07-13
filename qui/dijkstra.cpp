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

ll dist[100010];
// vector<pair<int, int> > grafo[100010];
vii grafo[100010];
int p[100010];

void dijkstra(int s){
	// > 1 bilhão
	memset(dist, LINF, sizeof(dist)); 
	memset(p, -1, sizeof p);
	dist[s] = 0LL;
	priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll, int> > > pq;
	pq.push(mp(0LL, s));
	while(!pq.empty()){
		pair<ll,int> topo = pq.top();
		pq.pop();
		ll distancia = topo.F;
		int vertice   = topo.S;
		if(distancia > dist[vertice]) continue;
		for(int i = 0; i < 
			grafo[vertice].size(); i++){
			int destino = grafo[vertice][i].F;
			int custo = grafo[vertice][i].S;
			if(dist[destino] > 
				dist[vertice] + custo){
				dist[destino] =
					dist[vertice] + custo;
				p[destino] = vertice;
				pq.push(mp(dist[destino], destino));
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		grafo[a].pb(mp(b,c));
		grafo[b].pb(mp(a,c));
	}
	dijkstra(1);
	if(p[n] == -1){
		printf("-1\n");
		return 0;
	}
	stack<int> s;
	for(int i = n; i != -1; i = p[i]) s.push(i);
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}
	printf("\n");
	return 0;
}
