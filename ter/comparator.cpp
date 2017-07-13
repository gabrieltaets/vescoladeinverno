#include <bits/stdc++.h>
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


struct stNasc {
	int dia;
	int mes;
	int ano;
	bool operator< (const struct stNasc b) const {
		if(ano != b.ano) return ano < b.ano;
		if(mes != b.mes) return mes < b.mes;
		return dia < b.dia;
	}
}; // sort(v.begin(), v.end());

bool comp (const struct stNasc a,
	const struct stNasc b) const {
		if(a.ano != b.ano) return a.ano < b.ano;
		if(a.mes != b.mes) return a.mes < b.mes;
		return a.dia < b.dia;
} // sort(v.begin(), v.end(), comp);

int main(){

	return 0;
}
