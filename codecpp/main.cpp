#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEqual(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void recursiveGroup(vector<vector<int>> remainingLists, vector<int> currentGroup, int n, vector<int> allJobs, vector<vector<int>>& results) {
    if (currentGroup.size() == n) {
        int groupSize = 0;
        for (int i = 0; i < currentGroup.size(); i++) {
            groupSize += remainingLists[currentGroup[i]].size();
        }
        vector<int> combinedList;
        for (int i = 0; i < currentGroup.size(); i++) {
            vector<int> list = remainingLists[currentGroup[i]];
            combinedList.insert(combinedList.end(), list.begin(), list.end());
        }
        sort(combinedList.begin(), combinedList.end());
        if (groupSize == allJobs.size() && isEqual(allJobs, combinedList)) {
            results.push_back(currentGroup);
        }
        return;
    }
    for (int i = 0; i < remainingLists.size(); i++) {
        vector<int> newList = remainingLists[i];
        vector<int> newGroup = currentGroup;
        newGroup.push_back(i);
        vector<vector<int>> newRemainingLists(remainingLists.begin()+i+1, remainingLists.end());
        recursiveGroup(newRemainingLists, newGroup, n, allJobs, results);
    }
}

vector<vector<int>> getAllClusterCombinations(vector<vector<int>> lists, int n, vector<int> allJobs) {
    vector<vector<int>> results;
    recursiveGroup(lists, {}, n, allJobs, results);
    return results;
}

int main() {
    vector<vector<int>> lists = {{1, 2}, {3}, {4, 5}};
    vector<int> allJobs = {1, 2, 3, 4, 5};
    vector<vector<int>> results = getAllClusterCombinations(lists, 3, allJobs);
    for (int i = 0; i < results.size(); i++) {
        vector<int> group = results[i];
        cout << "Group " << i+1 << ": ";
        for (int j = 0; j < group.size(); j++) {
            vector<int> list = lists[group[j]];
            cout << "{";
            for (int k = 0; k < list.size(); k++) {
                cout << list[k];
                if (k < list.size()-1) {
                    cout << ", ";
                }
            }
            cout << "}";
            if (j < group.size()-1) {
                cout << " + ";
            }
        }
        cout << endl;
    }
    return 0;
}
