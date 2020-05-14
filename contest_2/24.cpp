#include<bits/stdc++.h>
using namespace std;

int t, n, k, a[10], x[10];
vector<int> v;
vector< vector<int> > res;
void Init(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
}
void Check(){
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i]*x[i];
	}
	if(sum == k){
		for(int i = 0; i < n; i++){
			if(x[i] == 1)
			v.push_back(a[i]);
		}
		res.push_back(v);
		v.clear();
	}
}
void Try(int i){
	for(int j = 1; j >= 0; j--){
		x[i] = j;
		if(i == n - 1)	Check();
		else Try(i + 1);
	}
}
void Display(){
	for(int i = 0; i < res.size(); i++){
		cout<<"[";
		for(int j = 0; j < res[i].size() - 1; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<res[i][res[i].size() - 1]<<"] ";
	}
}
int main(){
	cin >> t;
	while(t--){
		Init();
		int count = 0;
		Try(0);
		if(res.size() == 0)	cout<<"-1";
		else Display();
		res.clear();
		cout << endl;
	}
	return 0;
}
