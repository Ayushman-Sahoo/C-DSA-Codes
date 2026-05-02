#include <iostream>
using namespace std;

// Function to calculate trapped water
int trapWater(int height[], int n) {
    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;
    int water = 0;

    while(left <= right) {
        if(height[left] < height[right]) {
            if(height[left] >= maxLeft)
                maxLeft = height[left];
            else
                water += maxLeft - height[left];
            left++;
        } else {
            if(height[right] >= maxRight)
                maxRight = height[right];
            else
                water += maxRight - height[right];
            right--;
        }
    }
    return water;
}

int main() {
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;

    int height[n];
    cout << "Enter the heights of the bars:\n";
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int totalWater = trapWater(height, n);
    cout << "Total water trapped: " << totalWater << endl;

    return 0;
}