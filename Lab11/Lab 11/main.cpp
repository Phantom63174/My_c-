#include <iostream>

using namespace std;

bool prime_numbers(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i*i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the number  N: ";
    cin >> n;

    int *primes = new int[n+1];
    int *p = primes;
    for (int i = 2; i <= n; i++) {
        if (prime_numbers(i)) {
            *p = i;
            p++;
        }
    }

    cout << "Primes numbers up to " << n << ": ";
    for (int *z = primes; z < p; z++) {
        cout << *z << " ";
    }
    cout << endl;

    delete[] primes;

    return 0;
}

