#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> memo;

int findMaxSubstringsRemoved(string currentStr, const vector<string>& substrings) {
    if (memo.find(currentStr) != memo.end()) {
        return memo[currentStr];
    }
    
    int maxRemovals = 0;
    for (const string& sub : substrings) {
        size_t pos = currentStr.find(sub);
        
        if (pos != string::npos) {
            string updatedStr = currentStr;
            updatedStr.erase(pos, sub.length());
            maxRemovals = max(maxRemovals, 1 + findMaxSubstringsRemoved(updatedStr, substrings));
        }
    }
    memo[currentStr] = maxRemovals;
    return maxRemovals;
}

int main() {
    int numSubstrings;
    cin >> numSubstrings;
    
    vector<string> substrings(numSubstrings);
    for (int i = 0; i < numSubstrings; i++) {
        cin >> substrings[i];
    }

    string mainString;
    cin >> mainString;
    int result = findMaxSubstringsRemoved(mainString, substrings);
    cout << result;

    return 0;
}
