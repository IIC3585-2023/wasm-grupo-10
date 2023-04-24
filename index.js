Module.onRuntimeInitialized = () => {
    let inputJobs = document.getElementById("input-jobs")
    let inputClusters = document.getElementById("input-clusters")
    let buttonWASM = document.getElementById("button-wasm")
    let buttonJS = document.getElementById("button-js")
    buttonWASM.addEventListener("click", function(){
        console.log("WASM - C++ button clicked")
        const jobs = inputJobs.value.split(',').map((job) => parseInt(job, 10))
        const clusters = parseInt(inputClusters.value, 10)
        const size = jobs.length;
        const arrPtr = Module._malloc(size * Int32Array.BYTES_PER_ELEMENT);
        const arr = new Int32Array(Module.HEAPU8.buffer, arrPtr, size);

        for (let i = 0; i < size; i++) {
            arr[i] = jobs[i];
        }
        const t0 = Date.now();
        Module.ccall('cppSolve', null, ['number', 'number', 'number'], [arrPtr, size, clusters]);
        const t1 = Date.now();
        Module._free(arrPtr);
        console.log(`WASM - C++ took ${t1 - t0} milliseconds.`)
    })
    buttonJS.addEventListener("click", function(){
        console.log("JavaScript button clicked")
        const jobs = inputJobs.value.split(',').map((job) => parseInt(job, 10))
        const clusters = parseInt(inputClusters.value, 10)
        const t0 = Date.now();
        jsSolve(jobs, clusters)
        const t1 = Date.now();
        console.log(`JavaScript took ${t1 - t0} milliseconds.`)
    })
};