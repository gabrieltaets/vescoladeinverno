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

int tree[4*100000+10];
int a[100010];

void build(int no, int left, int right){
	int filhoesq = no * 2, filhodir = no * 2 + 1;
	int mid = (left + right)/2;
	if(left == right){
		tree[no] = a[right];
		return;
	}
	build(filhoesq, left, mid);
	build(filhodir, mid+1, right);
	tree[no] = tree[filhoesq] * tree[filhodir];
}

int query(int no, int left, int right, int i, int j){
	if(right < i || left > j) return 1;
	if(left >= i && right <= j) return tree[no];
	int filhoesq = no * 2, filhodir = no * 2 + 1;
	int mid = (left + right)/2;
	int prodEsq = query(filhoesq, left, mid, i, j);
	int prodDir = query(filhodir, mid+1, right, i, j);
	return prodEsq * prodDir;
}

void update(int no, int left, int right, int pos, int val){
	if(pos > right || pos < left) return;
	if(left == right){
		tree[no] = val;
		return;
	}
	int filhoesq = no * 2, filhodir = no * 2 + 1;
	int mid = (left + right)/2;
	update(filhoesq, left, mid, pos, val);
	update(filhodir, mid+1, right, pos, val);
	tree[no] = tree[filhoesq] * tree[filhodir];
}

int main(){
	int N, K;
	while(scanf("%d %d",&N,&K) != EOF && N){
		for(int i = 1; i <= N; i++){
			scanf("%d",&a[i]);
		}
		build(1, 1, N);
		for(int i = 0; i < K; i++){
			char c;
			int x, y;
			scanf(" %c %d %d",&c,&x,&y);
			if(c == 'C') {
				// no inicial, limite esquerda, limite direita, 
				// posição, valor
				update(1, 1, N, x, y);
			}
			else {
				// no inicial, limite esquerda, limite direita, 
				// esquerda do intervalo, direita do intervalo
				int v = query(1, 1, N, x, y);
				c = '0';
				if(v > 0) c = '+';
				else if(v < 0) c = '-';
				printf("%c",c);
			}
		}
		printf("\n");
	}
	return 0;
}
