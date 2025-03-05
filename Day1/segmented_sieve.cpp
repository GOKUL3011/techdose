#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void simpleSieve(int limit, vector<int>& primes) {
    vector<bool> isPrime(limit + 1, true);
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

void segmentedSieve(int low, int high) {
    int limit = sqrt(high);
    vector<int> primes;
    simpleSieve(limit, primes);

    vector<bool> isPrime(high - low + 1, true);
    for (int p : primes) {
        int start = max(p * p, (low + p - 1) / p * p);
        for (int j = start; j <= high; j += p) {
            isPrime[j - low] = false;
        }
    }

    for (int i = 0; i < isPrime.size(); i++) {
        if (isPrime[i] && (i + low) > 1) cout << i + low << " ";
    }
    cout << endl;
}

int main() {
    int low, high;
    cin >> low >> high;
    segmentedSieve(low, high);
    return 0;
}
