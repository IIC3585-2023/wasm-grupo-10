// Basado en https://stackoverflow.com/a/47147597
function getAllSubsets(jobs) {
    let allSubsets = jobs.reduce(
        (subsets, value) => subsets.concat(subsets.map(set => [value,...set])), [[]]
    )
    return allSubsets
}

function sum(arr) {
    return arr.reduce((a,b) => a + b, 0);
}

function isEqual(a, b) {
    return a.length === b.length && a.every((v, i) => v === b[i]);
}

function getAllClusterCombinations(lists, n, allJobs) {
    const results = [];
    function recursiveGroup(remainingLists, currentGroup) {
        if (currentGroup.length === n) {
            const groupSize = currentGroup.reduce((prev, curr) => prev + curr.length, 0)
            const combinedList = currentGroup.reduce((prev, curr) => prev.concat(curr), []).sort()
            if (groupSize == allJobs.length && isEqual(allJobs, combinedList)) {
                results.push(currentGroup);
            }
            return;
        }
        for (let i = 0; i < remainingLists.length; i++) {
            const newList = [...remainingLists[i]];
            const newGroup = [...currentGroup, newList];
            const newRemainingLists = remainingLists.slice(i + 1);
            recursiveGroup(newRemainingLists, newGroup);
        }
    }
    recursiveGroup(lists, []);
    return results;
}     

function getBestClusterCombination(combinations) {
    let minTime = Infinity
    let bestClusterCombination = combinations[0]
    combinations.forEach((combination) => {
        const maxTime = Math.max(...combination.map(cluster => sum((Array.from(cluster)))))
        if (maxTime < minTime) {
            minTime = maxTime
            bestClusterCombination = combination
        }
    })
    return bestClusterCombination
}

// let jobs = [30, 50, 10, 20, 90].sort()

function jsSolve(jobs, clusterNum){
    jobs.sort((a, b) => a - b)
    const subsets = getAllSubsets(jobs)
    const clusterCombinations = getAllClusterCombinations(subsets, clusterNum, jobs)
    const bestClusterCombination = getBestClusterCombination(clusterCombinations)

    for (let i = 0; i < bestClusterCombination.length; i++) {
        let assignedJobs = bestClusterCombination[i]
        assignedJobs = assignedJobs.reduce((prev, curr) => prev+", "+curr.toString(), "").slice(2)
        console.log(`Cluster ${i+1}: [${assignedJobs}]`)
    }
}

// jsSolve([30, 50, 10, 20, 90], 2)