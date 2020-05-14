#include<bits/stdc++.h>
using namespace std;
int n, a[20][20];
bool ok[20][20];
vector<string> res;
void ql(int i, int j, string s) {
	if(a[1][1]==0 || a[n][n]==0) return;
	if(i==n && j==n) res.push_back(s);
	if(a[i+1][j]==1 && i!=n && !ok[i+1][j]) {
		ok[i][j] = true;
		ql(i+1,j,s+"D");
		ok[i][j] = false;
	}
	if(a[i][j+1]==1 && j!=n && !ok[i][j+1]) {
		ok[i][j] = true;
		ql(i,j+1,s+"R");
		ok[i][j] = false;
	}
	if(a[i][j-1]==1 && j!=1 && !ok[i][j-1]) {
		ok[i][j] = true;
		ql(i,j-1,s+"L");
		ok[i][j] = false;
	}
	if(a[i-1][j]==1 && i!=1 && !ok[i-1][j]) {
		ok[i][j] = true;
		ql(i-1,j,s+"U");
		ok[i][j] = false;
	}	
}
void solve() {
	res.clear();
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++){
			 cin >> a[i][j];
			 ok[i][j] = false;
		}  
	}
	ql(1,1,"");
	if(res.size()==0) cout << "-1";
	else {
		sort(res.begin(), res.end());
		for(int i=0; i<res.size(); i++)
			cout << res[i] << " ";
		}
		cout << endl;
	
}
int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
