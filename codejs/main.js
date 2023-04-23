const _ = require('lodash')

// Basado en https://stackoverflow.com/a/47147597
function getAllSubsets(jobs) {
    let allSubsets = jobs.reduce(
        (subsets, value) => subsets.concat(subsets.map(set => [value,...set])), [[]]
    )
    return allSubsets
}

function getAllClusterCombinations(lists, n, allJobs) {
    const results = [];
    function recursiveGroup(remainingLists, currentGroup) {
        if (currentGroup.length === n) {
            const groupSize = currentGroup.reduce((prev, curr) => prev + curr.length, 0)
            const combinedList = currentGroup.reduce((prev, curr) => prev.concat(curr), []).sort()
            if (groupSize == allJobs.length && _.isEqual(allJobs, combinedList)) {
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
        const maxTime = Math.max(...combination.map(cluster => _.sum((Array.from(cluster)))))
        if (maxTime < minTime) {
            minTime = maxTime
            bestClusterCombination = combination
        }
    })
    return bestClusterCombination
}

let jobs = [30, 50, 10, 20, 90].sort()
const subsets = getAllSubsets(jobs)
// console.log(subsets.length)
const clusterCombinations = getAllClusterCombinations(subsets, 2, jobs)
// console.log(clusterCombinations, clusterCombinations.length)
const bestCluster = getBestClusterCombination(clusterCombinations)
// console.log(bestCluster, bestCluster.length)

// let a = new Set(jobs)
// console.log(_.sum(Array.from(a)))

// let a = new Set([1,2])
// let b = new Set([2,1])
// console.log(_.isEqual(a,b))


// // // Ejemplo de uso:
// const jobs = [30, 50, 10, 20, 90]
// const numClusters = 2;
// const result = getCombinations(jobs, numClusters);
// console.log(result);


// INPUT
// ['a', 'b', 'c'];


// OUTPUT
// [ 
//     [['a'], ['b', 'c']],
//     [['b'], ['a', 'c']],
//     [['c'], ['a', 'b']],
//     [['a', 'b', 'c'], []]
// ]
