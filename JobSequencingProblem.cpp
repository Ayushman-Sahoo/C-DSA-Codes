/*Job Sequencing Problem

Given an array of jobs where every job has a deadline and profit associated with it.
Each job takes 1 unit of time to complete.
The profit is only earned if the job is completed by its deadline.

Find the maximum profit that can be earned.

Example:
Jobs = [
    {1, 4, 20},
    {2, 1, 10},
    {3, 1, 40},
    {4, 1, 30}
]

Output: 60 (Jobs with IDs 3 and 1 are selected)*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;   // sort by profit descending
}

int maxProfit(vector<pair<int, int>> jobs) {

    int n = jobs.size();

    // Step 1: sort jobs by profit (descending)
    sort(jobs.begin(), jobs.end(), compare);

    // Find maximum deadline
    int maxDeadline = 0;
    for(int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].first);
    }

    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0;

    // Step 2: assign jobs to free slots
    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].first; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].second;
                break;
            }
        }
    }

    return totalProfit;
}

int main(){
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));

    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    cout << maxProfit(jobs);

    return 0;
}

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs) {

    int n = pairs.size();
    vector<Job> jobs;

    for(int i = 0; i < n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second); // idx, deadline, profit
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    }); // descending order of profit

    cout << "selecting Job\n";

    int profit = jobs[0].profit;
    int safeDeadline = 2;   // already selected first job

    cout << "selecting Job " << jobs[0].idx << endl;

    for(int i = 1; i < n; i++) {
        if(jobs[i].deadline >= safeDeadline) {
            cout << "selecting Job " << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }

    cout << "max profit = " << profit << endl;

    return profit;
}

int main(){

    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));

    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    maxProfit(jobs);

    return 0;
}*/