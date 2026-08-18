#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coin(n);

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    cout << "Enter amount: ";
    cin >> amount;

    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coin[j] <= i)
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }

    cout << "Minimum coins = " << dp[amount];

    return 0;
}

OUTPUT :
Enter number of coins: 5
Enter coin values: 4
2
1
3
6
Enter amount: 50
Minimum coins = 9