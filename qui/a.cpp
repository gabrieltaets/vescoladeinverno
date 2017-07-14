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

ll mod = (1LL << 31) - 1LL;

ll fast_exp(ll e){
	if(!e) return 1;
	ll a = fast_exp(e/2);
	a = (a * a) % mod;
	if(e&1){ // e % 2 == 1
		a = (a * 3) % mod;
	}
	return a;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%lld\n",fast_exp(n));
	return 0;
}
