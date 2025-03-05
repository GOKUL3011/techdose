class Solution {
public:

    bool is_prime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    void sieve_of_Eratosthenes(vector<int>& primes, int n) {
        vector<bool> prime_flag(n + 1, true);
        prime_flag[0] = false;
        prime_flag[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (prime_flag[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime_flag[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (prime_flag[i]) {
                primes.push_back(i);
            }
        }
    }

    vector<int> segmented_sieve(int low, int high) {
        vector<int> primes;
        sieve_of_Eratosthenes(primes, static_cast<int>(sqrt(high)));
        vector<bool> segsieve(high - low + 1, true);

        for (int prime : primes) {
            int start = max(prime * prime, (low + prime - 1) / prime * prime);
            for (int j = start; j <= high; j += prime) {
                segsieve[j - low] = false;
            }
        }

        vector<int> segment_primes;
        for (int i = 0; i < (high - low + 1); i++) {
            if (segsieve[i] && (low + i) > 1) {
                segment_primes.push_back(low + i);
            }
        }
        return segment_primes;
    }


    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = segmented_sieve(left, right);

        if (primes.size() < 2) {
            return {-1, -1};
        }

        int min_diff = INT_MAX;
        int first = -1, second = -1;

        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < min_diff) {
                min_diff = diff;
                first = primes[i];
                second = primes[i + 1];
            }
        }

        return {first, second};
    }
};
