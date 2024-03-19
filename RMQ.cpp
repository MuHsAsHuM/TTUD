#include <bits/stdc++.h> 
using namespace std;

int n, m;
int A[100000], M[100000][100];

void preprocessing(){
    for (int i = 0; i < n; ++i) {
            M[i][0] = A[i];
        }
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; (i + (1 << j) - 1) < n; ++i) {
                M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
            }
        }
}

int RMQ(int i, int j){
    int k = log2(j-i+1);
    return min(M[i][k], M[j - (1 << k) + 1][k]);
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }

    preprocessing();
    int sum=0;

    cin>>m;
    while(m!=0){
        int i,j;
        cin>>i>>j;
        sum += RMQ(i,j);
        m--;
    }
    cout<<sum;

}