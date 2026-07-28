#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Factorial
// Time Complexity: O(n)
// Space Complexity: O(1)
unsigned long long iterativeFactorial(int num)
{
    unsigned long long fact = 1;

    for (int i = 2; i <= num; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive Factorial
// Time Complexity: O(n)
// Space Complexity: O(n)
unsigned long long recursiveFactorial(int num)
{
    if (num == 0 || num == 1)
        return 1;

    return num * recursiveFactorial(num - 1);
}

int main()
{
    int num;

    cout << "Enter a number: ";

    if (!(cin >> num) || num < 0)
    {
        cout << "Please enter a valid non-negative number." << endl;
        return 1;
    }

    // Iterative Execution Time
    auto start1 = high_resolution_clock::now();
    unsigned long long ans1 = iterativeFactorial(num);
    auto stop1 = high_resolution_clock::now();

    duration<double, nano> time1 = stop1 - start1;

    // Recursive Execution Time
    auto start2 = high_resolution_clock::now();
    unsigned long long ans2 = recursiveFactorial(num);
    auto stop2 = high_resolution_clock::now();

    duration<double, nano> time2 = stop2 - start2;

    // Display Output
    cout << "\n===== FACTORIAL RESULT =====" << endl;
    cout << "Number                : " << num << endl;
    cout << "Iterative Factorial   : " << ans1 << endl;
    cout << "Iterative Time        : " << time1.count() << " ns" << endl;

    cout << "----------------------------------" << endl;

    cout << "Recursive Factorial   : " << ans2 << endl;
    cout << "Recursive Time        : " << time2.count() << " ns" << endl;

    return 0;
}