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

int main(){
	int n;
	bool flag = false;
	scanf("%d",&n);
	getchar();
	getchar();	
	while(n--){
		if(flag) printf("\n");
		flag = true;
		map<string, int> mapa;
		string arv;
		int cont = 0;
		while(getline(cin, arv) && !arv.empty()){
			mapa[arv]++;
			cont++;
		}
		map<string,int>::iterator it;
		for(it = mapa.begin(); it != mapa.end(); it++){
			printf("%s %.4lf\n", it->first.c_str(), 
				100.0*(*it).second/cont);
		}

	}
	return 0;
}
