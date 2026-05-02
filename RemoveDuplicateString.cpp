//Recursion Approach 
#include <iostream>
using namespace std;
void removeDuplicates(string str, string result, int index) {
  if (index == str.length()) {
        cout << "After removing duplicates: " << result;
        return;
  }
  bool duplicate = false;
  for (int i = 0; i < result.length(); i++) {
    if (str[index] == result[i]) {
      duplicate = true;
      break;
    }
  }

  if (!duplicate) {
    result += str[index];
  }
  removeDuplicates(str, result, index + 1);
}
int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    removeDuplicates(str, "", 0);
    return 0;
}
//loop
/*#include <iostream>
using namespace std;
int main(){
  string str;
  cout << "Enter string: ";
  cin >> str;
  string result = "";
  for (int i = 0; i < str.length(); i++) {
        bool duplicate = false;

        for (int j = 0; j < result.length(); j++) {
            if (str[i] == result[j]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            result += str[i];
        }
  }
  cout << "String after removing duplicates: " << result << endl;
  return 0;
}*/