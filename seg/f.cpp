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

int r[100010];
int n;

bool simula(int k){
	for(int i = 1; i < n; i++){
		int dif = r[i] - r[i-1];
		if(dif > k) return false;
		if(dif == k) k--;
	}
	return true;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int caso = 1; caso <= T; caso++){
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d",&r[i]);
		}
		int low = 1, high = (int)(1e8), k;
		while(low <= high){
			int mid = (low + high)/2;
			if(simula(mid)){
				k = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		printf("Case %d: %d\n", caso, k);
	}
	return 0;
}
