#include <bits/stdc++.h>
using namespace std;

int count_changes(int t, int r, int c, int N, int M) {
    // Wrong: doesn't handle large values of t properly
    int pos = (r-1) * M + c;
    return t / (N * M);  // Incomplete logic
}

int main() {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    
    vector<tuple> queries;
    
    for (int i = 0; i < Q; i++) {
        long long t;
        int r, c, col;
        cin >> t >> r >> c >> col;
        queries.push_back({t, r, c, col});
    }
    
    sort(queries.begin(), queries.end());
    
    vector<vector> grid(N+1, vector(M+1, 1));
    
    for (auto [t, r, c, col] : queries) {
        // Wrong: doesn't properly deduce initial state
        int changes = count_changes(t, r, c, N, M);
        if (changes % 2 == 0) {
            grid[r][c] = col;
        } else {
            grid[r][c] = (col == 1) ? 2 : 1;
        }
    }
    
    cout << "POSSIBLE\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << grid[i][j];
            if (j < M) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}