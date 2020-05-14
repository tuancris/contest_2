#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std; 
ll prime[] = {2,3,5,7,11,13,17,19,29,31,37,41};
ll n;
ll solve(ll x,ll y,ll z){
    if(x == n)  return y;
    ll res = INF;
    for(int t = 1;;t++) {
        y *= prime[z];
		if((x)*(t+1) > n || y > res)  break;
		res = min(res,solve((x)*(t+1),y, z+1));
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
    	cin >> n;
        cout << solve(1,1,0) << endl;
	}
    return 0;
}
