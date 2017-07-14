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

ii mod[8] = { ii(-1, -2), ii(-2, -1), ii(-1, 2), ii(-2, 1), 
			 ii(1, -2),  ii(2, -1),  ii(1, 2),  ii(2, 1) };

bool valida(ii coord){
	return !(coord.F < 1 || coord.F > 8 || 
		coord.S < 1 || coord.S > 8) ;
}

int dist[10][10];
void bfs(int i, int j){
	memset(dist, INF, sizeof dist);
	queue<ii> q;
	dist[i][j] = 0;
	q.push(ii(i,j));
	while(!q.empty()){
		ii a = q.front();
		q.pop();
		for(int i = 0; i < 8; i++){
			ii destino(a.F + mod[i].F, a.S + mod[i].S);
			if(valida(destino)){
				if(dist[destino.F][destino.S] == INF){
					q.push(destino);
					dist[destino.F][destino.S] = 
						dist[a.F][a.S] + 1;
				}
			}
		}
	}

}

int main(){
	int iinicial, ifinal, jinicial, jfinal;
	char a, b;
	while(scanf(" %c%d %c%d",&a,&iinicial,&b,&ifinal)!=EOF){
		jinicial = a - 'a' + 1;
		jfinal = b - 'a' + 1;
		bfs(iinicial, jinicial);
		printf("%d\n",dist[ifinal][jfinal]);
	}

	return 0;
}
