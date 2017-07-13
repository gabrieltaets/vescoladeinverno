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

bitset<10000010> primo;
vector<int> primos;

void crivo(){
	primos.pb(2);
	primo[1] = 1;
	for(long long i = 3; i <= 10000000; i += 2){
		if(primo[i]) continue;
		for(long long j = i * i; j <= 10000000; j += i){
			primo[j] = 1;
		}
		primos.pb(i);
	}
}

bool isPrime(long long num){
	if(num == 2) return true;
	if(num%2==0) return false;
	if(num <= 10000000) return !primo[num];
	for(int i = 0; i < primos.size(); i++){
		if(num % primos[i] == 0) return false;
		if(primos[i] > sqrt(num)) break;
	}
	return true;
}

int main(){
	crivo();
	long long n;
	while(scanf("%lld",&n) && n){
		printf("%s\n",isPrime(n)?"yes":"no");
	}
	return 0;
}
