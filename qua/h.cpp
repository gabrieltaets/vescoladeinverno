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
	scanf("%d",&n);
	while(n--){
		pair<long long, long long> left, right, mid;
		left = make_pair(0, 1);
		right = make_pair(1, 0);
		mid = make_pair(1, 1);
		string str;
		cin >> str;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == 'L'){
				right = mid;
				mid.F += left.F;
				mid.S += left.S;
			}
			else {
				left = mid;
				mid.F += right.F;
				mid.S += right.S;
			}
		}
		printf("%lld/%lld\n",mid.F,mid.S);
	}
	return 0;
}
