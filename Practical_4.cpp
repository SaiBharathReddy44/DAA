#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// 1. Iterative Factorial
long long factorialUsingLoop(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

// 2. Recursive Factorial
long long factorialUsingRecursion(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorialUsingRecursion(n - 1);
    }
}

int main() {
    int num;

    cout << "Enter a number from 1-10: ";
    cin >> num;

    if (num < 0) {
        cout << "Enter positive integer." << endl;
        return 1;
    }

    
    const int RUNS = 1000000; 

 
    auto startLoop = high_resolution_clock::now();
    
    long long loopResult = 0;
    for (int i = 0; i < RUNS; i++) {
        loopResult = factorialUsingLoop(num);
    }
    
    auto endLoop = high_resolution_clock::now();

    auto loopDuration = duration_cast<microseconds>(endLoop - startLoop).count();

    auto startRec = high_resolution_clock::now();
    
    long long recursionResult = 0;
    for (int i = 0; i < RUNS; i++) {
        recursionResult = factorialUsingRecursion(num);
    }
    
    auto endRec = high_resolution_clock::now();

    auto recDuration = duration_cast<microseconds>(endRec - startRec).count();

    cout << "\nResults for:" << num <<"!"<< endl;
    cout << "Iterative: " << loopResult << endl;
    cout << "Iterative Time: " << loopDuration << " microseconds (" << loopDuration / 1000.0 << " ms)" << endl;
    cout << "Recursion Result : " << recursionResult << endl;
    cout << "Recursion Time: " << recDuration << " microseconds (" << recDuration / 1000.0 << " ms)" << endl;

    return 0;
}