
#include<bits/stdc++.h>
using namespace std;
 
vector<int> a;
int n,k, sum = 0;

int main(){
 
 
    int t; cin >> t;
    while (t--) {
    	sum = 0;
        cin >> n >> k;
        a.resize(n);
        for(int i=0;i<n;i++) {
        	cin >> a[i];
			sum += a[i];
		} 	    
        if (sum % k != 0){
             cout << 0 << endl;
        }
        else cout << 1 << endl;
	}
    return 0;
}
