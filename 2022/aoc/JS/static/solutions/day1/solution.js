function solution(input) {
    const elves = input.split('\n\n'); // splits the string where a line is left i.e between the foods of different elves

    const values = [];

    for(var i=0;i<elves.length;i++) {
        const foods = elves[i].split('\n'); // Seperates the different foods of one elf into an array
        
        let sum = 0;
        for(let j=0;j<foods.length;j++) {
            sum += Number(foods[j]);
        }
        values.push(sum);

    }

    values.sort()
    values.reverse()
    values.length = 3;

    return `Part 1 solution: ${values[0]}\nPart 2 solution: ${values.reduce((a, b) => a + b, 0)}`
}

export default solution;