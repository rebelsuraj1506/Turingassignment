#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long randll(long long l, long long r) {
    return uniform_int_distribution(l, r)(rng);
}

int main(int argc, char* argv[]) {
    if (argc < 6) {
        cerr << "Usage: ./generator N M K Q max_time\n";
        return 1;
    }
    
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int K = atoi(argv[3]);
    int Q = atoi(argv[4]);
    long long max_time = atoll(argv[5]);
    
    cout << N << " " << M << " " << K << " " << Q << "\n";
    
    set<tuple> used;
    
    for (int i = 0; i < Q; i++) {
        long long t;
        int r, c;
        
        do {
            t = randll(0, max_time);
            r = randll(1, N);
            c = randll(1, M);
        } while (used.count({t, r, c}));
        
        used.insert({t, r, c});
        
        int col = randll(1, min(K, 100)); // Limit color range for practicality
        cout << t << " " << r << " " << c << " " << col << "\n";
    }
    
    return 0;
}