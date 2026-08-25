#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n)
{
    // 1D DP array
    vector<int> dp(W + 1, 0);

    // Process each item
    for (int i = 0; i < n; i++)
    {
        // Traverse capacity backwards
        for (int w = W; w >= wt[i]; w--)
        {
            int take = val[i] + dp[w - wt[i]];

            // Don't use max()
            if (take > dp[w])
            {
                dp[w] = take;
            }
        }
    }

    return dp[W];
}

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n);
    vector<int> val(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int result = knapsack(W, wt, val, n);

    cout << "Maximum value = " << result << endl;

    return 0;
}

output :
Enter number of items: 3
Enter weights: 2
1
3
Enter values: 12
10
20
Enter knapsack capacity: 5
Maximum value = 32