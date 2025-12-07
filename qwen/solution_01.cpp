#include <bits/stdc++.h>
using namespace std;

// Qwen Attempt 1: Tries to actually match pairs - too complex and wrong
bool isBalanced(vector<int> seg) {
    int n = seg.size();
    if (n % 2 == 1) return false;
    
    sort(seg.begin(), seg.end());
    
    // Try to greedily pair elements
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        bool found = false;
        for (int j = i + 1; j < n; j++) {
            if (!used[j] && seg[i] == seg[j]) {
                used[i] = used[j] = true;
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int count = 0;
    
    // Wrong: doesn't properly handle circular array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> seg;
            for (int k = i; k <= j; k++) {
                seg.push_back(a[k]);
            }
            if (isBalanced(seg)) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}