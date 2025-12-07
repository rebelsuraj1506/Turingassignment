#include <bits/stdc++.h>
using namespace std;

// Qwen Attempt 2: Tries DP approach - overcomplicated
int n;
vector<int> a;
map<pair<int,int>, int> memo;

int solve(int start, int len) {
    if (len > n) return 0;
    
    auto key = make_pair(start, len);
    if (memo.count(key)) return memo[key];
    
    if (len % 2 == 0) {
        // Check if current segment is balanced
        map<int, int> freq;
        for (int i = 0; i < len; i++) {
            freq[a[(start + i) % n]]++;
        }
        
        bool balanced = true;
        for (auto [val, cnt] : freq) {
            if (cnt % 2 == 1) {
                balanced = false;
                break;
            }
        }
        
        // Wrong: trying to use DP when simple iteration works
        return memo[key] = (balanced ? 1 : 0) + solve(start, len + 1);
    }
    
    return memo[key] = solve(start, len + 1);
}

int main() {
    cin >> n;
    a.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int total = 0;
    // Wrong: doesn't count all subsegments properly
    for (int i = 0; i < n; i++) {
        memo.clear();
        total += solve(i, 2);
    }
    
    cout << total << endl;
    
    return 0;
}