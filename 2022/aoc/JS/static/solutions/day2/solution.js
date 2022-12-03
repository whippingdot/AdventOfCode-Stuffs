function solution(input) {
    const moves = input.split('\n');
    let score1 = 0;
    let score2 = 0;

    for(let i=0;i<moves.length;i++) {
        const move = moves[i];
        const opponent = move.charCodeAt(0) - 65;
        const self = move.charCodeAt(2) - 88;

        console.log(opponent, self)

        score1 += self + 1;

        if(opponent == (self + 1) % 3) continue;
        if(opponent == self) score1 += 3;
        if((opponent + 1) % 3 == self) score1 += 6;
    }

    for(let i=0;i<moves.length;i++) {
        const move = moves[i];
        const opponent = move.charCodeAt(0) - 65;
        const action = move.charCodeAt(2) - 88;

        score2 += action * 3;
        
        let self = (opponent + action - 1) % 3;
        if(self < 0) self = 2;
        score2 += self + 1;
    }

    return `Part 1 solution: ${score1}\nPart 2 solution: ${score2}`;
}

export default solution;