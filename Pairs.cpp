/*Given an array of integers, form maximum number of pairs such that the difference between elements in each pair is ≤ k.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;  // Sort based on end time in ascending order
    //return a.second > b.second; // Sort based on end time in descending order

    //return a.first < b.first;  // Sort based on start time in ascending order
    //return a.first > b.first; // Sort based on start time in descending order
}

int main(){
    vector<int> start = {0, 1, 3};
    vector<int> end   = {9, 2, 4};

    vector<int> vec(5, 0); 

    vector<pair<int, int>> activity(3);

    activity[0] = make_pair(0, 9);
    activity[1] = make_pair(1, 2);
    activity[2] = make_pair(3, 4);

    for (int i = 0; i < activity.size(); i++)
    {
      cout << "Activity " << i << ": " 
           << activity[i].first << " " 
           << activity[i].second << endl;
    }

    sort(activity.begin(), activity.end(), compare);

    return 0;
}

/* */