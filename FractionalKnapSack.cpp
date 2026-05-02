#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    return a.first > b.first;  // Sort based on value/weight ratio in descending order
}

int fractionalKnapsack(vector<int> value, vector<int> weight, int W) {
  int n = value.size();
  vector<pair<double, int>> ratio(n, make_pair(0.0, 0)); // pair of (value/weight, index)
  for (int i = 0; i < value.size(); i++)
  {
    double r = (double)value[i] / weight[i];
    ratio[i] = make_pair(r, i);
  }
  sort(ratio.begin(), ratio.end(), compare); // Sort in descending order based on value/weight ratio 

  double totalValue = 0.0;
  for (int i = 0; i < ratio.size(); i++) {
    int idx = ratio[i].second;
    if (weight[idx] <= W) {
      totalValue += value[idx];
      W -= weight[idx];
    } else {
      totalValue += ratio[i].first * W;
      W = 0;
      break;
    }
  }
  cout << "Total value in Knapsack = " << totalValue << endl;
  return totalValue;
}

int main(){
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;
    
    double totalValue = fractionalKnapsack(value, weight, W);
    cout << "Maximum value in Knapsack = " << totalValue << endl;
    return 0;
}