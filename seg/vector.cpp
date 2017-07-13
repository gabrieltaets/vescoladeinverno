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

vector<int> v;

int main(){
	int x;
	while(scanf("%d",&x)!=EOF){
		vector<int>::iterator it;
		for(it = v.begin(); it != v.end(); it++){
			if(*it >= x){
				break;
			}
		}
		v.insert(it, x);
		int mid = v.size()/2;
		int ans;
		if(v.size() % 2 == 0){
			ans = (v[mid] + v[mid-1])/2;
		}
		else {
			ans = v[mid];
		}
		printf("%d\n",ans);
	}
	return 0;
}
