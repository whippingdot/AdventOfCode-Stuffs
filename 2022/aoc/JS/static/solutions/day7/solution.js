function solution(input) {
    const lines = input.split('\n');
    if(lines[lines.length - 1] == '') lines.pop();

    const fs = createFileSystem(lines);
    const unusedSpace = 70000000 - getFileSizes(fs);

    const info = getInfo(fs, unusedSpace);

   return `Part 1 solution: ${info.sum}\nPart 2 solution: ${info.smallest}`; // Ans1: 1427048, Ans2: 2940614
}

function createFileSystem(lines) {
    const fileSystem = {};
    let location = '';

    for(let i=0;i<lines.length;i++) {
        const line = lines[i];
        if(line[0] != '$') continue;

        const cmd = line.slice(2, 4);

        if(cmd == 'cd') {
            const inp = line.slice(5);
            
            switch(inp) {
                case '/':
                    location = '';
                    break;
                
                case '..':
                    location = location.slice(0, location.lastIndexOf('/'));
                    break;
                
                default: 
                    location += '/' + inp;
            }

        }

        else {
            let end;

            for(let j=i+1;j<lines.length;j++) {
                if(lines[j].includes('$') || i + j + 1 == lines.length) break;
                end = j;
            }

            const dir = getFromLocation(fileSystem, location);
            
            for(let j=i+1;j<end+1;j++) {
                const item = lines[j];
                const itemName = item.replace(/(dir|[0-9]|\s)/g, '');

                if(item.includes('dir')) dir[itemName] = {};
                else dir[itemName] = Number(item.replace(/[^0-9]/g, ''));               

            }
        }



    }

    return fileSystem;

}

function getInfo(fs, unusedSpace) {
    let sum = 0;
    let smallest;

    loopThroughDir(fs);

    function loopThroughDir(dir) {
        const dirSize = getFileSizes(dir);
        if((dirSize < smallest && unusedSpace + dirSize >= 30000000) || !smallest) smallest = dirSize;

        if(dirSize <= 100000) sum += dirSize;

        for(let itemName of Object.keys(dir)) {
            const item = dir[itemName];
            if(typeof(item) == 'object') loopThroughDir(item);
        }
    }

    return {
        sum: sum,
        smallest: smallest
    };
}

function getFileSizes(dir) {
    let sum = 0;

    for(let itemName of Object.keys(dir)) {
        const item = dir[itemName];
        
        if(typeof(item) == 'number') sum += item;

        else sum += getFileSizes(item);
    }

    return sum;
}

function getFromLocation(fs, location) {
    if(location == '') return fs;
    const locations = location.split('/');
    locations.shift();

    let dir = fs;
    for(let l of locations) {
        dir = dir[l];
    }

    return dir;
}

export default solution;