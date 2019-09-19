class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        set<int> s(primes.begin(), primes.end());
        for(int i = 0; i < n - 2; i++) {
            auto it = s.begin();
            int num = *it;
            s.erase(*it);
            for(int j = 0; j < primes.size(); j++) {
                if((2147483647 / num) < primes[j]) continue;
                s.insert(primes[j] * num);
            }
        }
        return *s.begin();
    }
};