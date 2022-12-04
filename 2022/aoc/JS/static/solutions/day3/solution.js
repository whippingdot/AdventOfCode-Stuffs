function solution(input) {
    const rucksacks = input.split('\n');
    let sum1 = 0;
    let sum2 = 0;

    rucksacks.forEach(rucksack => {
        const comp1 = rucksack.substr(0, rucksack.length / 2);
        const comp2 = rucksack.substr(rucksack.length / 2);

        let commonChar;

        for(let i=0;i<comp1.length;i++) {
            if(comp2.includes(comp1[i])) {
                commonChar = comp1[i];
                break
            }

            comp1.replace(comp1[i], '');
        }

        sum1 += commonChar.charCodeAt(0) - (commonChar.toUpperCase() == commonChar ? 38 : 96); 
    })

    for(let i=0;i<rucksacks.length;i+=3) {
        const threeRS = rucksacks.slice(i, i + 3);

        let commonChar;
        for(let j=0;j<threeRS[0].length;j++) {
            const first = threeRS[0];
            if(threeRS[1].includes(first[j]) && threeRS[2].includes(first[j])) {
                commonChar = first[j];
                break;
            }

            threeRS[0].replace(first[j], '');
        }

        sum2 += commonChar.charCodeAt(0) - (commonChar.toUpperCase() == commonChar ? 38 : 96);

    }

    return `Part 1 solution: ${sum1}\nPart 2 solution: ${sum2}`; // Ans1: 7746, Ans2: 2604
}

export default solution;