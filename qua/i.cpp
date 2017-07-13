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

char grid[110][110];
int vis[110][110];
int n, m;

void dfs(int x, int y){
	if(x < 0 || x >= n 
		|| y < 0 || y >= m 
		|| grid[x][y] != '@'
		|| vis[x][y]) return;
	vis[x][y] = 1;
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			dfs(x+i,y+j);
		}
	}
}

int main(){
	while(scanf("%d %d",&n,&m) && (n|m)){
		int cont = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++)
			scanf("%s",grid[i]);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(grid[i][j] != '@') continue;
				if(vis[i][j]) continue;
				dfs(i,j);
				cont++;
			}
		}
		printf("%d\n",cont);
	}
	return 0;
}
