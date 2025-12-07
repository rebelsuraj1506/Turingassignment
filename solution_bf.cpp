#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> seg) {
    if (seg.size() % 2 == 1) return false;
    
    map<int, int> freq;
    for (int x : seg) {
        freq[x]++;
    }
    
    for (auto [val, cnt] : freq) {
        if (cnt % 2 == 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int count = 0;
    
    // Try all starting positions and all even lengths
    for (int start = 0; start < n; start++) {
        for (int len = 2; len <= n; len += 2) {
            vector<int> segment;
            for (int i = 0; i < len; i++) {
                segment.push_back(a[(start + i) % n]);
            }
            
            if (canPartition(segment)) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}