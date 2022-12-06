function solution(input) {
    let start1 = getStart(input, 4);
    let start2 = getStart(input, 14);

    return `Part 1 solution: ${start1}\nPart 2 solution: ${start2}`; // Ans1: 1920, Ans2: 2334
}

function getStart(input, length) {
    for(let i=length-1;i<input.length-length;i++) { 

        const characters = input.slice(i - length + 1, i + 1);

        let found = true;
        for(let j in characters) {
            if(characters.lastIndexOf(characters[j]) != j) {
                found = false;
                break;
            }
        }

        if(found) return i + 1;
    }
}

export default solution;