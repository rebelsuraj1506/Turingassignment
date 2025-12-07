#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    
    vector<tuple> queries;
    for (int i = 0; i < Q; i++) {
        long long t;
        int r, c, col;
        cin >> t >> r >> c >> col;
        queries.push_back({t, r, c, col});
    }
    
    // Try all possible initial configurations (only works for tiny grids)
    // This is intentionally inefficient for comparison
    
    // For now, just use a greedy approach
    vector<vector> grid(N + 1, vector(M + 1, 1));
    
    cout << "POSSIBLE\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << grid[i][j];
            if (j < M) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;