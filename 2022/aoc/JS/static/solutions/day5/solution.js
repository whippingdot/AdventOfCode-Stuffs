function solution(input) {
    const lines = input.split('\n');
    if(lines[lines.length - 1] == '') lines.pop();

    const colsEnd = getColsEndIdx(lines);
    const crates = getCrates(lines, colsEnd);

    const newCrates1 = execInstructions(crates, lines.slice(colsEnd + 2), true);
    const newCrates2 = execInstructions(crates, lines.slice(colsEnd + 2), false);
    

    return `Part 1 solution: ${getTopCrates(newCrates1)}\nPart 2 solution: ${getTopCrates(newCrates2)}`; // Ans1: LBLVVTVLP, Ans2: TPFFBDRJD
}

function execInstructions(crates, instructions, reverse) {
    const newCrates = JSON.parse(JSON.stringify(crates));

    for(let line of instructions) {
        const ins = line.split(/[^0-9]/).filter(str => str != '').map(Number);

        const removeCol = newCrates[ins[1] - 1];
        const addCol = newCrates[ins[2] - 1];
        const toAdd = [];

        for(let i=0;i<ins[0];i++) {
            if(reverse) toAdd.push(removeCol.pop());
            else toAdd.unshift(removeCol.pop());
        }

        addCol.push(...toAdd);
    }

    return newCrates;
}

function getTopCrates(crates) {
    let topCrates = '';
    for(let stack of crates) {
        topCrates += stack[stack.length - 1]
    }

    return topCrates;
}

function getCrates(lines, colsEnd) {
    const crates = new Array(9).fill().map(() => []);

    for(let i=0;i<colsEnd;i++) {

        for(let j=0;j<9;j++) {
            const block = lines[i][1 + j * 4];
            if(block != ' ') crates[j].unshift(block);
        }
    }

    return crates;
}

function getColsEndIdx(lines) {
    for(let i=0;i<lines.length;i++) {
        if(!(lines[i].includes('['))) return i;
    }
}

export default solution;