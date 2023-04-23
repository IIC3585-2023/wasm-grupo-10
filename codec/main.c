#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// void assign_jobs_to_clusters(int jobs[], int num_jobs, int num_clusters, int assigned_jobs[][num_jobs]) {
//   // Sort the jobs in decreasing order of time
//   for (int i = 0; i < num_jobs; i++) {
//     for (int j = i + 1; j < num_jobs; j++) {
//       if (jobs[j] > jobs[i]) {
//         int temp = jobs[i];
//         jobs[i] = jobs[j];
//         jobs[j] = temp;
//       }
//     }
//   }

//   // Initialize the assigned_jobs array to store the jobs assigned to each cluster
//   for (int i = 0; i < num_clusters; i++) {
//     for (int j = 0; j < num_jobs; j++) {
//       assigned_jobs[i][j] = 0;
//     }
//   }

//   // Assign each job to the cluster with the least total time so far
//   for (int i = 0; i < num_jobs; i++) {
//     int min_time = __INT_MAX__;
//     int min_cluster = -1;
//     for (int j = 0; j < num_clusters; j++) {
//       int cluster_time = 0;
//       for (int k = 0; k < num_jobs; k++) {
//         cluster_time += assigned_jobs[j][k];
//       }
//       if (cluster_time < min_time) {
//         min_time = cluster_time;
//         min_cluster = j;
//       }
//     }
//     assigned_jobs[min_cluster][i] = jobs[i];
//   }
// }

// // Example usage
// int main() {
//   // Define the jobs and the number of clusters
//   int jobs[] = {1, 2, 3};
//   int num_jobs = 3;
//   int num_clusters = 2;

//   // Initialize the assigned_jobs array
//   int assigned_jobs[num_clusters][num_jobs];

//   // Call the function to assign the jobs to the clusters
//   assign_jobs_to_clusters(jobs, num_jobs, num_clusters, assigned_jobs);

//   // Print the assigned jobs for each cluster
//   for (int i = 0; i < num_clusters; i++) {
//     printf("Cluster %d: ", i+1);
//     for (int j = 0; j < num_jobs; j++) {
//       if (assigned_jobs[i][j] != 0) {
//         printf("%d ", assigned_jobs[i][j]);
//       }
//     }
//     printf("\n");
//   }

//   return 0;
// }

int** getAllSubsets(int* jobs, int jobsSize) {
  // retorna un array de 2**len(jobs)
  int allSubsetsLength = 1;
  int exp = jobsSize;
  while (exp != 0) {
    allSubsetsLength *= 2;
    --exp;
  };
  int** allSubsets = calloc(allSubsetsLength, sizeof(int*));
  for (int i = 0; i < allSubsetsLength; i++){
    allSubsets[i] = calloc(jobsSize, sizeof(int));
  };

  for (int i = 0; i < jobsSize; i++) {
    int job = jobsSize[i];
    int power2 = 1;
    int cont = power2;
    for (int j = 0; j < allSubsetsLength; j++){
      if ()
    }
  };

  for (int i = 0; i < allSubsetsLength; i++){
    free(allSubsets[i]);
  };
  free(allSubsets);
  // []
  // [], [a]
  // [], [a], [b], [a,b]
  // [], [a], [b], [a,b], [c], [a,c], [b,c], [a,b,c]
  // a = 1, 3, 5, 7, ... mod 2 >= 2/1 
  // b = 2, 3, 6, 7, 10, 11, ... mod 4 >= 4/2
  // c = 4, 5, 6, 7, 12, 13, 14, 15, ... mod 8 >= 8/2
};

// int **getAllSubsets2(int *jobs, int jobsSize, int *subsetsSize, int **subsets) {
//     // Tamaño máximo de subconjuntos
//     int maxSubsets = 1 << jobsSize; // 2**jobsSize ?
    
//     // Asignar memoria para los subconjuntos
//     *subsets = (int *) malloc(maxSubsets * sizeof(int *));
//     for (int i = 0; i < maxSubsets; i++) {
//         (*subsets)[i] = (int *) malloc(jobsSize * sizeof(int));
//         (*subsetsSize)[i] = 0;
//     }

//     // Generar subconjuntos
//     for (int i = 0; i < jobsSize; i++) {
//         int subsetCount = 1 << i;
//         for (int j = 0; j < subsetCount; j++) {
//             for (int k = 0; k < *subsetsSize[j] ; k++) {
//                 (*subsets)[j + subsetCount][k] = (*subsets)[j][k];
//             }
//             (*subsets)[j + subsetCount][(*subsetsSize)[j]++] = jobs[i];
//         }
//     }

//     return subsets;
// }

int main() {
  int jobs[] = {30, 50, 10, 20, 90};
  getAllSubsets(jobs, 5);
};

// int main() {
//     
//     int jobsSize = sizeof(jobs)/sizeof(jobs[0]);
//     int maxSubsets = 1 << jobsSize;
//     int *subsetsSize = (int *) malloc(maxSubsets * sizeof(int));
//     int **subsets;

//     getAllSubsets(jobs, jobsSize, &subsetsSize, &subsets);

//     // Imprimir subconjuntos
//     for (int i = 0; i < maxSubsets; i++) {
//         printf("{ ");
//         for (int j = 0; j < subsetsSize[i]; j++) {
//             printf("%d ", subsets[i][j]);
//         }
//         printf("}\n");
//     }

//     // Liberar memoria
//     for (int i = 0; i < maxSubsets; i++) {
//         free(subsets[i]);
//     }
//     free(subsetsSize);
//     free(subsets);

//     return 0;
// }