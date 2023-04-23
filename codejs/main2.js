function assignJobsToClusters(jobs, m) {
  // Sort the jobs in decreasing order of time
  jobs.sort((a, b) => b - a);

  // Initialize an object to store the jobs assigned to each cluster
  const assignedJobs = {};
  for (let i = 0; i < m; i++) {
    assignedJobs[`Cluster ${i+1}`] = [];
  }

  // Assign each job to the cluster with the least total time so far
  for (let i = 0; i < jobs.length; i++) {
    let minTime = Infinity;
    let minCluster = "";
    for (let j = 1; j <= m; j++) {
      const clusterTime = assignedJobs[`Cluster ${j}`].reduce((acc, val) => acc + val, 0);
      if (clusterTime < minTime) {
        minTime = clusterTime;
        minCluster = `Cluster ${j}`;
      }
    }
    assignedJobs[minCluster].push(jobs[i]);
  }

  return assignedJobs;
}

// Example usage
const jobs = [30, 50, 10, 20, 70]
const m = 2;
const assignedJobs = assignJobsToClusters(jobs, m);
console.log(assignedJobs);
