#include <bits/stdc++.h> 
using namespace std; 
int a[100];
bool solve(int a[], int n){  
    int s = 0;    
    for (int i = 0; i < n; i++)  
         s += a[i];  
    if (s % 2 != 0)  return false;  
    bool dp[s + 1][n + 1];   
    for (int i = 0; i <= n; i++)  
         dp[0][i] = true;  
    for (int i = 1; i <= s ; i++)  
         dp[i][0] = false;   
    for (int i = 1; i <= s ; i++){  
        for (int j = 1; j <= n; j++){  
            dp[i][j] = dp[i][j - 1];  
            if (i >= a[j - 1])  dp[i][j] = dp[i][j] || dp[i - a[j - 1]][j - 1];              
        }      
    }  
    return dp[s][n];  
}  
int main(){  
   int t; cin >> t;
   while(t--) {
   	int n; cin >>n;
   	for(int i=0; i<n; i++)
   	    cin >> a[i];
   	if (solve(a,n) == true) cout << "YES" << endl;
   	else cout << "NO" << endl;
    }
    return 0;  
}
 
