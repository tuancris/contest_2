#include<bits/stdc++.h>
using namespace std;
int n, tmp = 0;
int c[16][16], x[16], cmin;
int fopt = 999999;
bool check[16];

void timcMin() {
	cmin = c[1][2];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(c[i][j] < cmin && i != j) cmin = c[i][j];
		}
	}
}
void ql(int i) {
	for(int j=2; j<=n; j++) {
		if(!check[j]) {
			x[i] = j;
			check[j] = true;
			tmp += c[x[i-1]][x[i]];
			if(i==n) {
				if(tmp+c[x[n]][1] < fopt) {
				fopt = tmp + c[x[n]][1];
			 }
			}
			else if(tmp +cmin*(n-i+1) < fopt) ql(i+1);
			check[j] = false;
			tmp -= c[x[i-1]][x[i]];
		}
	}
}
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
			    cin >> c[i][j];
	}
	timcMin();
	x[1] = 1;
	ql(2);
	cout << fopt << endl;
	return 0;
}

