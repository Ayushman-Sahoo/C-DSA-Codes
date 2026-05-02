//using backtracking to find all subsets of a string
#include <iostream>
using namespace std;

// Function to generate and print all subsets
void printSubsets(string str, string subset)
{
    // BASE CASE:
    // If the original string becomes empty,
    // print the subset formed so far
    if(str.size() == 0)
    {
        cout << subset << "\n";
        return; // stop recursion
    }

    // Take first character of string
    char ch = str[0];

    // Remaining string after removing first character
    string remaining = str.substr(1);

    // YES CHOICE: include the character in subset
    printSubsets(remaining, subset + ch);

    // NO CHOICE: exclude the character from subset
    printSubsets(remaining, subset);
}

int main()
{
    string str;

    // Take input from user
    cout << "Enter the string: ";
    cin >> str;

    cout << "\nAll subsets are:\n";

    // Initial call with empty subset
    printSubsets(str, "");

    return 0;
}
