/*Select the maximum number of activities that can be performed by a single person, given that:
A person can work on only one activity at a time.
Each activity has a start time and end time.
An activity can be selected only if its start time is greater than or equal to the finish time of the previously selected activity.

Given:
start = [10, 12, 20]
end   = [20, 25, 30]*/

#include <iostream>
#include <vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end) {

    // sort on end-time

    // A0 select
    int count = 1;
    int currEndTime = end[0];

    for (int i = 1; i < start.size(); i++) {
        if (start[i] >= currEndTime) {   // non-overlapping
            count++;
            currEndTime = end[i];
        }
    }

    return count;
}
int main(){
    vector<int> start = {10, 12, 20};
    vector<int> end   = {20, 25, 30};

    cout << maxActivities(start, end) << endl;
    return 0;
}