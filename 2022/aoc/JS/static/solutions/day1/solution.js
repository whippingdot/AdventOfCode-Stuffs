function solution(input) {
    const elves = input.split('\n\n'); // splits the string where a line is left i.e between the foods of different elves

    let greatestValue = 0;
    let gElfIdx = -1;

    for(var i=0;i<elves.length;i++) {
        const foods = elves[i].split('\n'); // Seperates the different foods of one elf into an array
        
        let sum = 0;
        for(var j=0;j<foods.length;j++) {
            sum += Number(foods[j]);
        }
        
        if(sum > greatestValue) {
            greatestValue = sum;
            gElfIdx = i;
        }

    }

    return `The elf carrying the most number of calories is elf number ${gElfIdx + 1}, which is carrying ${greatestValue} calories.`
}

export default solution;