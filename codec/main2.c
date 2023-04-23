#include <stdio.h>
#include <stdlib.h>

void generate_clusters(int jobs[], int n, int m, int curr_sum[], int index, int assigned_jobs[][n], int *min_sum) {
    if (index == n) {
        // All jobs have been assigned, check if current sum is better than previous best
        int max_sum = 0;
        for (int i = 0; i < m; i++) {
            if (curr_sum[i] > max_sum) {
                max_sum = curr_sum[i];
            }
        }
        if (max_sum < *min_sum) {
            *min_sum = max_sum;
            // Save the current assignment of jobs to clusters
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    assigned_jobs[i][j] = 0;
                }
            }
            int cluster = 0;
            for (int i = n - 1; i >= 0; i--) {
                assigned_jobs[cluster][i] = jobs[i];
                curr_sum[cluster] += jobs[i];
                if (cluster == m - 1) {
                    cluster = 0;
                } else {
                    cluster++;
                }
            }
        }
        return;
    }
    // Try adding the current job to each cluster and recursively call the function
    for (int i = 0; i < m; i++) {
        curr_sum[i] += jobs[index];
        generate_clusters(jobs, n, m, curr_sum, index+1, assigned_jobs, min_sum);
        curr_sum[i] -= jobs[index];
    }
}

// Example usage
int main() {
    int jobs[] = {30, 50, 10, 20, 90};
    int n = 5;
    int m = 2;
    int assigned_jobs[m][n];

    // Initialize the current sum of each cluster to 0
    int curr_sum[m];
    for (int i = 0; i < m; i++) {
        curr_sum[i] = 0;
    }

    // Find the best cluster assignment
    int min_sum = __INT_MAX__;
    generate_clusters(jobs, n, m, curr_sum, 0, assigned_jobs, &min_sum);

    // Print the assigned jobs for each cluster
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
