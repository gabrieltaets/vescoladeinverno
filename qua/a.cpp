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

string a, b;

bool simula(int k){
	string aux;
	for(int i = 0; i < b.size(); i++){
		for(int j = 0; j < k; j++)
			aux.pb(b[i]);
	}
	int cont = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == aux[cont]){
			cont++;
		}
	}
	return cont == aux.size();
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		cin >> a >> b;
		int lo = 0, hi = a.size() / b.size();
		int res = 0;
		while(lo <= hi){
			int mid = (lo+hi)/2;
			if(simula(mid)){
				lo = mid + 1;
				res = mid;
			}
			else hi = mid - 1;
		}
		printf("%d\n",res);
	}

	return 0;
}
