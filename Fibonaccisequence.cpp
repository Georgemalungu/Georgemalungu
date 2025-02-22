#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

// Recursive Implementation (Naive)
long long fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Dynamic Programming (Memoization)
long long fibonacci_memoization(int n, unordered_map<int, long long> &memo) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    if (n <= 1) {
        return n;
    }
    memo[n] = fibonacci_memoization(n - 1, memo) + fibonacci_memoization(n - 2, memo);
    return memo[n];
}

// Iterative Implementation
long long fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }
    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

// Function to evaluate the runtime of each method
void evaluate_fibonacci_runtime(int n) {
    // Testing Recursive
    auto start = high_resolution_clock::now();
    fibonacci_recursive(n);
    auto end = high_resolution_clock::now();
    auto recursive_time = duration_cast<microseconds>(end - start);
    cout << "Recursive: " << recursive_time.count() << " microseconds\n";

    // Testing Memoization
    unordered_map<int, long long> memo;
    start = high_resolution_clock::now();
    fibonacci_memoization(n, memo);
    end = high_resolution_clock::now();
    auto memoization_time = duration_cast<microseconds>(end - start);
    cout << "Memoization: " << memoization_time.count() << " microseconds\n";

    // Testing Iterative
    start = high_resolution_clock::now();
    fibonacci_iterative(n);
    end = high_resolution_clock::now();
    auto iterative_time = duration_cast<microseconds>(end - start);
    cout << "Iterative: " << iterative_time.count() << " microseconds\n";
}

int main() {
    int n = 30; // You can change this value for testing

    cout << "Fibonacci number at position " << n << ":\n";
    evaluate_fibonacci_runtime(n);

    return 0;
}
