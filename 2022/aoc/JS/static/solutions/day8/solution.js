function solution(input) {
    const trees = input.replace(/\n/g, '');
    const cols = input.indexOf('\n');
    const rows = trees.length / cols;

    let count = 0;
    let bestView = 0;

    for(let row=1;row<rows-1;row++) {
        for(let col=1;col<cols-1;col++) {
            const idx = getIdx(col, row);
            if((getVisible(idx, -1, 0) && getVisible(idx, 0, -1) && getVisible(idx, 1, 0) && getVisible(idx, 0, 1))) count += 1;
        }
    }

    for(let i=0;i<trees.length;i++) {
        bestView = Math.max(bestView, getView(i, -1, 0) * getView(i, 0, -1) * getView(i, 1, 0) * getView(i, 0, 1));
    }

    function getVisible(idx, shiftX, shiftY) {
        const col = idx % cols
        const row = Math.floor(idx / cols);
        let c = col;
        let r = row;

        do {
            c += shiftX;
            r += shiftY;
            if(trees[getIdx(c, r)] >= trees[getIdx(col, row)]) return true;
        }
        while (c > 0 && c < cols - 1 && r > 0 && r < rows - 1);
    }

    function getView(idx, shiftX, shiftY) {
        const col = idx % cols
        const row = Math.floor(idx / cols);
        let c = col;
        let r = row;
        let num = 0;

        while(c > 0 && c < cols - 1 && r > 0 && r < rows - 1) {
            num++;
            c += shiftX;
            r += shiftY;
            if(trees[getIdx(c, r)] >= trees[getIdx(col, row)]) return num;
        }

        return num;
    }


    function getIdx(col, row) {
        return row * cols + col;
    }

    return `Part 1 solution: ${cols * rows - count}\nPart 2 solution: ${bestView}`; // Ans1: 1695, Ans2: 287040
}



export default solution;