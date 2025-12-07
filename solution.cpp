#include <bits/stdc++.h>
using namespace std;

struct Snapshot {
    long long time;
    int row, col, color;
};

long long count_updates(long long from_time, long long to_time, int r, int c, int N, int M) {
    if (to_time <= from_time) return 0;
    
    long long total_cells = (long long)N * M;
    long long cell_pos = (long long)(r - 1) * M + c;
    
    // Cell updates at times: cell_pos, cell_pos + total_cells, cell_pos + 2*total_cells, ...
    // We need to count how many of these fall in (from_time, to_time]
    
    if (cell_pos > to_time) return 0;
    
    // First update time >= from_time + 1
    long long first_update;
    if (cell_pos > from_time) {
        first_update = cell_pos;
    } else {
        // Find next update after from_time
        long long k = (from_time - cell_pos) / total_cells + 1;
        first_update = cell_pos + k * total_cells;
    }
    
    if (first_update > to_time) return 0;
    
    // Count updates in [first_update, to_time]
    return (to_time - first_update) / total_cells + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    
    map<pair, vector> cell_snapshots;
    
    for (int i = 0; i < Q; i++) {
        long long t;
        int r, c, col;
        cin >> t >> r >> c >> col;
        cell_snapshots[{r, c}].push_back({t, r, c, col});
    }
    
    // Sort snapshots for each cell by time
    for (auto& [pos, snaps] : cell_snapshots) {
        sort(snaps.begin(), snaps.end(), [](const Snapshot& a, const Snapshot& b) {
            return a.time < b.time;
        });
    }
    
    // Validate consistency and determine initial colors
    vector<vector> grid(N + 1, vector(M + 1, 1));
    
    for (auto& [pos, snaps] : cell_snapshots) {
        int r = pos.first;
        int c = pos.second;
        
        // Check consecutive snapshots for consistency
        for (size_t i = 0; i + 1 < snaps.size(); i++) {
            long long t1 = snaps[i].time;
            long long t2 = snaps[i + 1].time;
            int col1 = snaps[i].color;
            int col2 = snaps[i + 1].color;
            
            long long updates = count_updates(t1, t2, r, c, N, M);
            
            if (updates % 2 == 0) {
                // Even updates: colors must be same
                if (col1 != col2) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            } else {
                // Odd updates: colors must differ
                if (col1 == col2) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
        
        // Determine initial color from earliest snapshot
        long long t0 = snaps[0].time;
        int col0 = snaps[0].color;
        
        long long updates_from_zero = count_updates(0, t0, r, c, N, M);
        
        if (updates_from_zero % 2 == 0) {
            grid[r][c] = col0;
        } else {
            // Must be different from col0
            if (K == 2) {
                grid[r][c] = (col0 == 1) ? 2 : 1;
            } else {
                grid[r][c] = (col0 == 1) ? 2 : 1;
            }
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