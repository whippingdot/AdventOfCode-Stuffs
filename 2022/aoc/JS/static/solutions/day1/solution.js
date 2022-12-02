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

    return `The most calories carried by a single elf is ${values[0]}, and the number of calories carried by the top three elves is ${values.reduce((a, b) => a + b, 0)}.`
}

export default solution;