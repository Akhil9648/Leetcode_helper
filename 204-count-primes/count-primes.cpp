class Solution {
public:
    vector<int> sieveOfEratosthenes(int n) {
    if (n < 2) return {};
    std::vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <=sqrt(n); ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
    }
    int countPrimes(int n) {
        int cnt=0;
        vector<int>prime=sieveOfEratosthenes(n);
        for(int i=2;i<n;i++){
            if(prime[i]) cnt++;
        }
        return cnt;
    }
};