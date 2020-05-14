#include<bits/stdc++.h> 
using namespace std;

int n,s,a[105],b[105],kt;
void init(int k){
    cout << "[";
    for(int i=1;i<k;i++) cout << b[i] << " ";
    cout << b[k] << "] ";
}
void Try(int i,int sum,int k){
    if(sum==s){
        kt = 1;
        init(k-1);
		return;
    }
    else{
        for(int j=i;j<=n;j++){
            b[k]=a[j];
            if(sum+a[j]<=s) {
                Try(j,sum+a[j],k+1);
            }
        }
    }
}

void solve(){
    kt = 0;
    cin >> n >> s;
    for(int i=1; i<=n; i++) 
	    cin >> a[i];
    sort(a+1,a+1+n);
    Try(1,0,1);
    if(kt==0) cout << -1;
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
