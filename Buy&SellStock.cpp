/*#include <iostream>
using namespace std;

// Function to calculate maximum profit
int maxProfit(int prices[], int n) {
    int minPrice = prices[0];   // assume first day's price is the lowest initially
    int maxProfit = 0;          // profit starts at 0 (in case no profit is possible)

    // Go through each day starting from day 2
    for (int i = 1; i < n; i++) {
        // Update the lowest price so far
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Profit if we sell at today's price
        int profit = prices[i] - minPrice;

        // Update maxProfit if today's profit is better
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }
    return maxProfit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int prices[n];  // array to store stock prices
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maxProfit(prices, n);
    cout << "Maximum Profit = " << result << endl;

    return 0;
}*/
/*#include <iostream>
using namespace std;

// Function to calculate maximum profit with multiple transactions allowed
int maxProfit(int prices[], int n) {
    int profit = 0;

    // Go through each day
    for (int i = 1; i < n; i++) {
        // If today's price is higher than yesterday's, we make a profit
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int prices[n];
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maxProfit(prices, n);
    cout << "Maximum Profit = " << result << endl;

    return 0;
}*/
#include <iostream>
#include <vector>
#include <climits> // Needed for INT_MAX
using namespace std;

// Function to calculate maximum profit with only one transaction allowed
void maxProfit(const vector<int>& prices, int n) {
    vector<int> bestBuy(n);
    bestBuy[0] = INT_MAX;

    for (int i = 1; i < n; i++) {
        bestBuy[i] = min(bestBuy[i - 1], prices[i - 1]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }

    cout << "Maximum Profit = " << maxProfit << endl;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    maxProfit(prices, n);

    return 0;
}
