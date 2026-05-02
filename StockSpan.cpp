#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to calculate stock span
void stockSpanProblem(vector<int>& prices) {

    stack<int> s;  
    // Stack will store INDEXES of days, not prices

    vector<int> span(prices.size());  
    // This vector will store span values for each day

    // For first day, span is always 1
    s.push(0);        // Push index of first day
    span[0] = 1;      // Span of first day is always 1

    // Loop through remaining days
    for (size_t i = 1; i < prices.size(); i++) {

        int currentPrice = prices[i];  
        // Store current day's price

        // Remove elements from stack while:
        // stack is not empty AND
        // price at top index is less than or equal to current price
        while (!s.empty() && prices[s.top()] <= currentPrice) {
            s.pop();  
            // Pop because those days are included in span
        }

        // If stack becomes empty,
        // it means current price is highest so far
        if (s.empty()) {
            span[i] = i + 1;  
            // Span is entire range from day 0 to i
        }
        else {
            span[i] = i - s.top();  
            // Span is difference between current index and last higher price index
        }

        // Push current index into stack
        s.push(i);
    }

    // Print the span values
    cout << "Stock Span: ";
    for (size_t i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main() {

    // Example stock prices
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    // Call function
    stockSpanProblem(prices);

    return 0;
}