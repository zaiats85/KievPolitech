const hash = (x) => {
    let hash = 0;
    let i;
    let chr;
    let xlen = x.length;
    if (xlen === 0) return hash;
    for (i = 0; i < xlen; i++) {
        chr = x.charCodeAt(i);
        hash = ((hash << 5) - hash) + chr;
        // Convert to 32bit integer
        hash |= 0;
    }
    return badHash(hash);
    /*return hash;*/
};

const badHash = (int) => {
    int = Math.round(Math.abs(int/2));
    if(int > 10) {
        return badHash(int);
    }
    return int;
};

class DumbMap {
    constructor() {
        this.list = []
    }

    get(x) {
        let i = hash(x);
        if(!this.list[i]) return undefined;

        let result;
        this.list[i].forEach(pairs => {
            if(pairs[0] === x){
                result = pairs[1]
            }
        });

        return result;

        /*return this.list[hash(x)];*/
    }

    set(x, y) {
        let i = hash(x);
        if(!this.list[i]) {
            this.list[i] = [];
        }

        this.list[i].push([x, y]);

        /*this.list[hash(x)] = y;*/
    }
}

let foo = new DumbMap();
for (let i = 0; i < 1000000; i++) {
    foo.set(`element-${i}`, i)
}

console.time('large');
console.log(foo.get('unExisting'));
console.timeEnd('large');
