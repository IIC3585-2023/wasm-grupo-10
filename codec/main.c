#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** getAllSubsets(int* jobs, int jobsSize, int allSubsetsLength) {
  int** allSubsets = calloc(allSubsetsLength, sizeof(int*));
  for (int i = 0; i < allSubsetsLength; i++){
    allSubsets[i] = calloc(jobsSize, sizeof(int));
  };

  for (int i = 0; i < jobsSize; i++) {
    int job = jobs[i];
    int power2 = pow(2, i+1);
    for (int j = 0; j < allSubsetsLength; j++){
      if (j % power2 >= power2/2) {
        for (int k = 0; k < jobsSize; k++) {
          if (allSubsets[j][k] == 0){
            allSubsets[j][k] = job;
            break;
          };
        };
      };
    };
  };

  for (int i = 0; i < allSubsetsLength; i++) {
    for (int j = 0; j < jobsSize; j++) {
      printf("%d ", allSubsets[i][j]);
    };
    printf("\n");
  };
  return allSubsets;

  // []
  // [], [a]
  // [], [a], [b], [a,b]
  // [], [a], [b], [a,b], [c], [a,c], [b,c], [a,b,c]
  // a = 1, 3, 5, 7, ... mod 2 >= 2/1 
  // b = 2, 3, 6, 7, 10, 11, ... mod 4 >= 4/2
  // c = 4, 5, 6, 7, 12, 13, 14, 15, ... mod 8 >= 8/2
};

int factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  };
};

int*** getAllClusterCombinations(int** lists, int listLength, int n, int* allJobs, int totalCombinations){
  int*** results = calloc(totalCombinations, sizeof(int**));
  
  for (int i = 0; i < n; i++) {
    results[i] = calloc(n, sizeof(int*));
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < totalCombinations; j++) {
  //     int* subset = lists[j]
      
  //   }
  // }

  return results;
};

int main() {
  int jobs[] = {30, 50, 10, 20, 90};
  int jobsSize = 5;
  int clusterNum = 2;

  int allSubsetsLength = 1;
  int exp = jobsSize;
  while (exp != 0) {
    allSubsetsLength *= 2;
    --exp;
  };
  int** subsets = getAllSubsets(jobs, jobsSize, allSubsetsLength);
  
  int totalCombinations = factorial(allSubsetsLength) / (factorial(allSubsetsLength - clusterNum) * factorial(clusterNum));
  int*** clusterCombinations = getAllClusterCombinations(subsets, allSubsetsLength, clusterNum, jobs, totalCombinations);
  
  for (int i = 0; i < totalCombinations; i++) {
    free(clusterCombinations[i]);
  };
  free(clusterCombinations);
  for (int i = 0; i < allSubsetsLength; i++){
    free(subsets[i]);
  };
  free(subsets);
};

/*

[ a, b ]
[ a, c ]
[ a, d ]
[ a, e ]
[ a, f ]
[ a, g ]
[ a, [ 50, 30, 10 ] ]
[ b, c ]
[ b, d ]
[ b, e ]
[ b, f ]
[ b, g ]
[ b, [ 50, 30, 10 ] ]
[ c, d ]
[ c, e ]
[ c, f ]
[ c, g ]
[ c, [ 50, 30, 10 ] ]
[ d, e ]
[ d, f ]
[ d, g ]
[ d, [ 50, 30, 10 ] ]
[ e, f ]
[ e, g ]
[ e, [ 50, 30, 10 ] ]
[ f, g ]
[ f, [ 50, 30, 10 ] ]
[ g, [ 50, 30, 10 ] ]

*/