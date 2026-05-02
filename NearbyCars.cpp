/*Nearby Cars Problem
You are given the locations of cars on a 2D plane represented by coordinates (cx, cy).
Find the K nearest cars to the origin (0,0) using the Euclidean distance formula.
Given:
C0 = (3, 3)
C1 = (5, -1)
C2 = (-2, 4)
K = 2*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Car {
public:
    int idx;
    int distance;
    Car(int idx, int distance) {
        this->idx = idx;
        this->distance = distance;  
    }

    bool operator<(const Car& other) const {
        return this->distance < other.distance; // For max-heap
    }
};

void nearbyCars(vector<pair<int, int>> pos, int K) {
    vector<Car> cars;

    for(int i=0; i<pos.size(); i++) { // O(n)
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i, distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end()); // O(n)

    for(int i=0; i<K; i++) { // O(nlogn)
        cout << "Car " << pq.top().idx << " is at distance " << pq.top().distance << endl;
        pq.pop();
    }
}

int main() {
  vector<pair<int, int>> cars;
  cars.push_back({3, 3});
  cars.push_back({5, -1});
  cars.push_back({-2, 4});
  int K = 2;
  nearbyCars(cars, K);
  return 0;
}