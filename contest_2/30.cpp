#include<bits/stdc++.h>
using namespace std;

const int MAX = 200;
int arr[MAX]; 
vector<vector<int> > vt;
int dem = 0;

bool kTraSNT(int N){
    if (N<=1) return false;
    else{
        for (int i=2; i<=sqrt(N); i++)
            if (N%i == 0) return false;
    }
    return true;
}

void printResult(int N){
    vt.resize(dem+1);
    for (int i=0; i<N; i++)
        vt[dem].push_back(arr[i]);
    return;
}

int sumResult(int N){
    int sum = 0;
    for (int i=0; i<N; i++)
        sum = sum + arr[i];
    return sum;
}

void Try(int a, int N, int P, int S){
    for (int i=P; i<=S; i++)
        if (kTraSNT(i)){
                arr[a-1] = i;
                if (a==N){
                    if (sumResult(a) == S){
                        printResult(a);
                        dem++;
                    }
                } else Try(a+1,N,i,S);
        }
    return;
}

int main(){
    int t;
    int N, P, S;
    cin >> t;
    while(t--){
        dem = 0;
        cin >> N >> P >> S;
        Try(1,N,P,S);

        cout << vt.size() << endl;
        for (int i=0; i<vt.size(); i++){
            for (int j=0; j<vt[i].size(); j++)
                cout << vt[i][j] << " ";
            cout << endl;
        }

        vt.erase(vt.begin(), vt.end());
    }
    return 0;
}
