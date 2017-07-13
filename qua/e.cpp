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

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
pair<int, int> mod[5];
char nomeDir[] = {'N', 'E', 'S', 'W'};

bool morreu[60][60];
pair<int, int> pos;
int n, m, dir;

bool anda(){
	pair<int, int> npos;
	npos.F = pos.F + mod[dir].F;
	npos.S = pos.S + mod[dir].S;
	if(npos.F < 0 || npos.F > n 
		|| npos.S < 0 || npos.S > m){
		if(morreu[pos.F][pos.S]) return true;
		morreu[pos.F][pos.S] = true;
		return false;
	}
	pos = npos;
	return true;
}

int main(){
	map<char, int> mapa;
	mapa['N']  = NORTH;
	mapa['S']  = SOUTH;
	mapa['W']  = WEST;
	mapa['E']  = EAST;
	mod[NORTH] = make_pair(0, 1);
	mod[SOUTH] = make_pair(0, -1);
	mod[EAST]  = make_pair(1, 0);
	mod[WEST]  = make_pair(-1, 0);
	scanf("%d %d",&n,&m);
	char d;
	while(scanf("%d %d %c",&pos.F,&pos.S,&d)!=EOF){
		dir = mapa[d];
		string s;
		cin >> s;
		bool ok = true;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'R'){
				dir++;
				dir %= 4;
			}
			else if(s[i] == 'L'){
				dir--;
				if(dir < 0) dir += 4;
			}
			else {
				ok = anda();
				if(!ok) break;
			}
		}
		printf("%d %d %c",pos.F,pos.S,nomeDir[dir]);
		printf("%s",ok?"\n":" LOST\n");
	}

	return 0;
}
