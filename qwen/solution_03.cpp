#include <bits/stdc++.h>
using namespace std;

// Qwen Attempt 3: Closer but has off-by-one errors and misses some cases
int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int count = 0;
    
    for (int start = 0; start < n; start++) {
        unordered_map<int, int> freq;
        
        // Wrong: starts from 0 instead of 1
        for (int len = 0; len < n; len++) {
            int pos = (start + len) % n;
            freq[a[pos]]++;
            
            // Wrong: checks len+1 instead of len, and other logic errors
            if ((len + 1) % 2 == 0) {
                bool allEven = true;
                for (auto [val, cnt] : freq) {
                    if (cnt % 2 == 1) {
                        allEven = false;
                        break;
                    }
                }
                if (allEven) count++;
            }
        }
    }
    
    // Wrong: might double count or miss wraparound cases
    cout << count << endl;
    
    return 0;
}