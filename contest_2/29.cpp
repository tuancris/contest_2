#include <bits/stdc++.h> 
using namespace std; 
int a[20][20];
int dem(int m, int n){ 
    if (m == 1 || n == 1)  return 1; 
    return dem(m - 1, n) + dem(m, n - 1); 
} 
  
int main(){ 
    int t; cin >> t;
    while(t--) {
    	int m, n;
    	cin >> m >> n;
    	for(int i=1; i<=m; i++) {
    		for(int j=1; j<=n; j++)
    		    cin >> a[i][j];
		}
		cout << dem(m,n) << endl;
	}
    return 0; 
} 
