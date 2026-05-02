//recursion meathod to count substrings
#include <iostream>
using namespace std;

int countSubstrings(string s, int start, int end) {
    // Base case: if string is empty
    if (start == s.length())
        return 0;

    // If end reaches end of string, move start forward
    if(end == s.length()) {
        return countSubstrings(s, start + 1, start + 1);
    }

    // Recursive case: count substrings in the first n-1 characters
    int count = 0;

    // Check if starting and ending characters are same
    if (s[start] == s[end])
        count = 1;

    // Recursive call to increase end
    return count + countSubstrings(s, start, end + 1);
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = countSubstrings(s, 0, 0);
    cout << "Total substrings with same starting and ending characters: " << result << endl;

    return 0;
}

//loop meathod to count substrings
/*#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    int count = 0;
    int n = s.length();

    // Check all substrings
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // If starting and ending characters are same
            if (s[i] == s[j])
            {
                count++;
            }
        }
    }

    cout << "Count of substrings starting and ending with same character: ";
    cout << count << endl;

    return 0;
}*/