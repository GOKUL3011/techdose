#include <iostream>
using namespace std;

void findFactors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cout << i << " ";
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;
    findFactors(num);
    return 0;
}
