#include<bits/stdc++.h>
using namespace std;
void init(int a[], int n){
	cout << "[";
	for (int i = 0; i < n-1; i++){
		 cout << a[i] << " ";
	}
	cout << a[n-1] << "]" << endl;
}
void dq(int a[], int n){
	if (n < 1) return;
	else {
		int b[20];
		for (int i = 0; i < n ; i ++){
			 b[i] = a[i] + a[i + 1]; 
		}
		init(a,n);
		dq(b,n-1);
	}
}
int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[20];
		for (int i = 0; i < n; i++)
			 cin >> a[i];
		dq(a,n);
	}
	return 0;	
}

