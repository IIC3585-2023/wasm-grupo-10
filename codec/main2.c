#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void assign_jobs_to_clusters(int jobs[], int n, int m, int assigned_jobs[][n]) {
  int cluster_times[m];
  for (int i = 0; i < m; i++) {
    cluster_times[i] = 0;
    for (int j = 0; j < n; j++) {
      assigned_jobs[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    int min_diff = INT_MAX;
    int min_cluster = -1;
    for (int j = 0; j < m; j++) {
      int diff = abs(cluster_times[j] - jobs[i]);
      if (diff < min_diff) {
        min_diff = diff;
        min_cluster = j;
      }
    }
    assigned_jobs[min_cluster][i] = jobs[i];
    cluster_times[min_cluster] += jobs[i];
  }
}

int main() {
  int jobs[] = {30, 50, 10, 20, 90};
  int n = 5;
  int m = 2;
  int assigned_jobs[m][n];

  assign_jobs_to_clusters(jobs, n, m, assigned_jobs);

  for (int i = 0; i < m; i++) {
    printf("Cluster %d: ", i+1);
    for (int j = 0; j < n; j++) {
      if (assigned_jobs[i][j] != 0) {
        printf("%d ", assigned_jobs[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}
