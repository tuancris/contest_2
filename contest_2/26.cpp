#include <bits/stdc++.h> 
using namespace std; 
  
void solve(string str, int k, string& max) { 
    if(k == 0)  return; 
    int n = str.length(); 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (str[i] < str[j]) { 
                swap(str[i], str[j]);  
                if (str.compare(max) > 0) max = str; 
                solve(str, k - 1, max); 
                swap(str[i], str[j]); 
            } 
        } 
    } 
} 
int main() 
{ 
    int t; cin >> t;
    while(t--) {
    	string str;
		int k;
		cin >> k >> str;
    	string max = str;
    	solve(str, k, max); 
        cout << max << endl; 
	}
    return 0; 
} 

