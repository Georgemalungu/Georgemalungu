#include <iostream>
#include <chrono>

using namespace std;

// Iterative function to calculate factorial
unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Recursive function to calculate factorial
unsigned long long factorialRecursive(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorialRecursive(n - 1);
}

int main() {
    int number;

    cout << "Enter a non-negative integer: ";
    cin >> number;

    if(number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1; // Exit the program with an error
    }

    // Measure time for iterative factorial
    auto start = chrono::high_resolution_clock::now();
    unsigned long long iterativeResult = factorialIterative(number);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> iterativeDuration = end - start;

    // Measure time for recursive factorial
    start = chrono::high_resolution_clock::now();
    unsigned long long recursiveResult = factorialRecursive(number);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> recursiveDuration = end - start;

    // Output results
    cout << "Iterative Factorial of " << number << " is " << iterativeResult << endl;
    cout << "Execution time (iterative): " << iterativeDuration.count() << " seconds" << endl;

    cout << "Recursive Factorial of " << number << " is " << recursiveResult << endl;
    cout << "Execution time (recursive): " << recursiveDuration.count() << " seconds" << endl;

    return 0;
}
