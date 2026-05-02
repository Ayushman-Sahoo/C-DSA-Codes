//Print all binary strings of size N without consecutive 1s
//Recursive Approach
#include <iostream>
using namespace std;

void printBinary(int n, int last, string ans) {
    // base case
    if (n == 0) {
        cout << ans << endl;
        return;
    }

    // put 0 (always allowed)
    printBinary(n - 1, 0, ans + "0");

    // put 1 only if last is 0
    if (last == 0) {
        printBinary(n - 1, 1, ans + "1");
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    printBinary(n, 0, "");
    return 0;
}

//Loop Approach
/*#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 1 << n;   // 2^n combinations

    for (int i = 0; i < total; i++) {
        string s = "";
        int num = i;
        bool valid = true;

        for (int j = 0; j < n; j++) {
            int bit = num % 2;
            num /= 2;

            if (bit == 1 && s.size() > 0 && s[0] == '1') {
                valid = false;
                break;
            }
            s = char(bit + '0') + s;
        }

        if (valid)
            cout << s << endl;
    }
    return 0;
}
*/