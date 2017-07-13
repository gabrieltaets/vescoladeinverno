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
	while(scanf("%d",&n) && n){
		queue<char> in, out;
		stack<char> pilha;
		char c;
		for(int i = 0; i < n; i++){
			scanf(" %c", &c);
			in.push(c);
		}
		for(int i = 0; i < n; i++){
			scanf(" %c", &c);
			out.push(c);
		}
		while(!in.empty()){
			pilha.push(in.front());
			printf("I");
			in.pop();
			while(!pilha.empty()){
				if(pilha.top() == out.front()){
					printf("R");
					pilha.pop();
					out.pop();
				}
				else break;
			}
		}

		printf("%s",out.empty()?"\n":" Impossible\n");
	}
	return 0;
}
