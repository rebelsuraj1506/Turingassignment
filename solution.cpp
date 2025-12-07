#include <bits/stdc++.h>
using namespace std;

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
    
    // Try each starting position
    for (int start = 0; start < n; start++) {
        map<int, int> freq;
        int oddCount = 0;
        
        // Try each length from this starting position
        for (int len = 1; len <= n; len++) {
            int pos = (start + len - 1) % n;
            int element = a[pos];
            
            // Update frequency
            if (freq[element] % 2 == 1) {
                oddCount--;
            } else {
                oddCount++;
            }
            freq[element]++;
            
            // Check if balanced (even length and all frequencies even)
            if (len % 2 == 0 && oddCount == 0) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}