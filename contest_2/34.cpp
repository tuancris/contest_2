#include<bits/stdc++.h>
#define M 100
using namespace std;
int n = 8, x[M], c[M][M], fopt = 0;
bool cot[M], cheo1[M], cheo2[M];
int tong() {
	int s = 0;
	for(int i=1; i<=n; i++)
	    s += c[i][x[i]];
	return s;
}
void ql(int i) {
	for(int j=1; j<=n; j++) {
		if(!cot[j] && !cheo1[i-j+n] && !cheo2[i+j-1]) {
			x[i] = j;
			cot[j] = true;
			cheo1[i-j+n] = true;
			cheo2[i+j-1] = true;
			if(i==n) {
				int t = tong();
				if(t>fopt) fopt = t;
			}
			else ql(i+1);
			cot[j] = false;
			cheo1[i-j+n] = false;
			cheo2[i+j-1] = false;
		}
	}
}
int main() {
	int t; cin >> t;
	while(t--) {
		fopt = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
			    cin >> c[i][j];
		}
		ql(1);
		cout << fopt << endl;
	}
	return 0;
}
