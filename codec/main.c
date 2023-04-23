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

int*** getAllClusterCombinations(int** lists, int n, int* allJobs){

}

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
  
  for (int i = 0; i < allSubsetsLength; i++){
    free(subsets[i]);
  };
  free(subsets);
};
