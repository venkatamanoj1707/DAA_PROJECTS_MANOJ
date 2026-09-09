#include <iostream>
#include <vector>
using namespace std;

int matrixChain(vector<int>& p, int n)
{
    // DP table
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Length of matrix chain
    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i <= n - length; i++)
        {
            int j = i + length - 1;

            dp[i][j] = 2147483647;

            // Try every possible split
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions: ";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    cout << "Minimum multiplications: "
         << matrixChain(p, n + 1);

    return 0;
}
OUTPUT:

Enter number of matrices: 3
Enter dimensions: 10 20 30 40
Minimum multiplications: 18000