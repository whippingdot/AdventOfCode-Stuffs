function solution(input) {
    const pairs = input.split('\n');
    if(pairs[pairs.length - 1] == '') pairs.pop();
    
    let sum1 = 0;
    let sum2 = 0;

    for(let i in pairs) {
        const tasks = pairs[i].split(',');
        const t1 = getTask(tasks[0]);
        const t2 = getTask(tasks[1]);

        if((t1.start <= t2.start && t1.end >= t2.end) || (t2.start <= t1.start && t2.end >= t1.end)) sum1 += 1;
        if(((t1.start <= t2.start && t1.end >= t2.start) || (t1.start <= t2.end && t1.end >= t2.end)) || 
           ((t2.start <= t1.start && t2.end >= t1.start) || (t2.start <= t1.end && t2.start >= t1.end))) sum2 += 1;
    }

    return `Part 1 solution: ${sum1}\nPart 2 solution: ${sum2}`;

}

function getTask(task) {
    return {
        start: Number(task.slice(0, task.indexOf('-'))),
        end: Number(task.slice(task.indexOf('-') + 1))
    }
}

export default solution;