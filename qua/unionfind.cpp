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

class UnionFind {
  public:
  	vector<int> p, rank, size;
  	UnionFind(int n){
  		p.resize(n);
  		rank.assign(n, 0);
      size.assign(n, 1);
  		for(int i = 0; i < n; i++)	p[i] = i;
  	}
  	int findSet(int i){
  		return p[i] == i ? i : (p[i] = findSet(p[i]));
  	}
  	bool isSameSet(int i, int j){
  		return findSet(i) == findSet(j);
  	}
  	int unionSet(int i, int j){
  		if(isSameSet(i, j)) return;
  		int x = findSet(i), y = findSet(j);
  		if(rank[x] > rank[y]){
  			p[y] = x; 
        size[x] += size[y];
        return size[x];
  		}
  		p[x] = y;
      size[y] += size[x];
  		if(rank[x] == rank[y]) rank[y]++;
      return size[y];
  	}
};

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n;
    scanf("%d",&n);
    UnionFind uf(100000);
    map<>
    while(n--){
      
    }
	  printf("%d\n",uf.unionSet(a, b));
  }
	return 0;
}
