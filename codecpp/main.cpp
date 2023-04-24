#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;


vector<vector<int>> getAllSubsets(vector<int> jobs) {
    vector<vector<int>> allSubsets = {{}};

    for (const int& value : jobs) {
        int n = allSubsets.size();
        for (int i = 0; i < n; ++i) {
            vector<int> subset = allSubsets[i];
            subset.push_back(value);
            allSubsets.push_back(subset);
        }
    }

    return allSubsets;
}


void recursiveGroup(vector<vector<int>> remainingLists, vector<vector<int>> currentGroup, int n, vector<int> allJobs, vector<vector<vector<int>>>& results) {
    if (currentGroup.size() == n) {
        vector<int> combinedList;
        for (int i = 0; i < currentGroup.size(); i++) {
            sort(currentGroup[i].begin(), currentGroup[i].end());
            vector<int> list = currentGroup[i];
            combinedList.insert(combinedList.end(),list.begin(), list.end());
            sort(combinedList.begin(), combinedList.end());
        }
        if (combinedList.size() == allJobs.size() && allJobs == combinedList) {
            results.push_back(currentGroup);
        }
        return;
    }
    for (int i = 0; i < remainingLists.size(); i++) {
        vector<int> newList = remainingLists[i];
        vector<vector<int>> newGroup = currentGroup;
        newGroup.push_back(newList);
        vector<vector<int>> newRemainingLists(remainingLists.begin()+i+1, remainingLists.end());
        recursiveGroup(newRemainingLists, newGroup, n, allJobs, results);
    }
}

vector<vector<vector<int>>> getAllClusterCombinations(vector<vector<int>> lists, int n, vector<int> allJobs) {
    vector<vector<vector<int>>> results;
    recursiveGroup(lists, {}, n, allJobs, results);
    return results;
}

vector<vector<int>> getBestClusterCombination(vector<vector<vector<int>>> combinations) {
    int minTime = INT_MAX;
    vector<vector<int>> bestClusterCombination = combinations[0];
    for (const auto& combination : combinations) {
        int maxTime = 0;
        for (const auto& cluster : combination) {
            int sum = 0;
            for (const auto& time : cluster) {
                sum += time;
            }
            maxTime = max(maxTime, sum);
        }
        if (maxTime < minTime) {
            minTime = maxTime;
            bestClusterCombination = combination;
        }
    }
    return bestClusterCombination;
}

int main() {
    vector<int> allJobs = { 90, 50, 30, 20, 10 };
    sort(allJobs.begin(), allJobs.end());

    vector<vector<int>> allSubsets = getAllSubsets(allJobs);
    // for (const vector<int>& subset : allSubsets) {
    //     for (const int& element : subset) {
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<vector<int>>> results = getAllClusterCombinations(allSubsets, 2, allJobs);
    // cout << "Results: " << results.size() << endl;
    // for (int i = 0; i < results.size(); i++) {
    //     vector<vector<int>> group = results[i];
    //     std::cout << "Group " << i+1 << ": ";
    //     for (int j = 0; j < group.size(); j++) {
    //         vector<int> list = group[j];
    //         std::cout << "{";
    //         for (int k = 0; k < list.size(); k++) {
    //             std::cout << list[k];
    //             if (k < list.size()-1) {
    //                 std::cout << ", ";
    //             }
    //         }
    //         std::cout << "}";
    //         if (j < group.size()-1) {
    //             std::cout << " + ";
    //         }
    //     }
    //     std::cout << endl;
    // 

    vector<vector<int>> bestCluster = getBestClusterCombination(results);
    for (const vector<int>& cluster : bestCluster) {
        for (const int& job : cluster) {
            cout << job << " ";
        }
        cout << endl;
    }
    return 0;
}

extern "C" void cppSolve(int* arrJobs, int jobsSize, int clusterNum) {
    vector<int> allJobs(arrJobs, arrJobs + jobsSize);
    sort(allJobs.begin(), allJobs.end());
    vector<vector<int>> allSubsets = getAllSubsets(allJobs);
    vector<vector<vector<int>>> results = getAllClusterCombinations(allSubsets, clusterNum, allJobs);
    vector<vector<int>> bestCluster = getBestClusterCombination(results);
    int i = 1;
    int j = 0;
    for (const vector<int>& cluster : bestCluster) {
        cout << "Cluster " << i << ": [";
        for (const int& job : cluster) {
            if (j == cluster.size()-1) {
                cout << job;
            } else {
                cout << job << ", ";
            }
            j++;
        }
        cout << "]";
        i++;
        j = 0;
        cout << endl;
    }
}