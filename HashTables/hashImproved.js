/*Goal*/
/*let dict = new HashTable();
dict.set("PI", 3.14);
dict.get("PI"); // 3.14*/

function NaiveDict(){
    this.keys = [];
    this.values = [];
}

NaiveDict.prototype.set = function(key, value){
    this.keys.push(key);
    this.keys.push(value);
};

NaiveDict.prototype.get = function(lookupKey){
    for(let i=0; i<this.keys.length;i++){
        let key = this.keys[i];
        if(key === lookupKey){
            return this.values[i];
        }
    }
};

const HashTable = () => {
    this.bucketCount = 100000;
    this.buckets = [];
    for(let i=0;i<bucketCount;i++){
        this.buckets.push(new NaiveDict());
    }
};

HashTable.prototype.hashFunction = (key) => {
    let hash = 0;
    for (let i=0;i< key.length;i++){
        hash += key.charCodeAt(i)
    }
    return hash;
};

HashTable.prototype.getBucketIndex = (key) => {
    return this.hashFunction(key) % this.bucketCount;
};

HashTable.prototype.getBucket = (key) => {
    return this.buckets[this.getBucketIndex(key)];
};

HashTable.prototype.set = () => {
    this.getBucket(key).set(key, value);
};

HashTable.prototype.get = () => {
    return this.getBucket(lookupKey).get(lookupKey);
};

var dict = new HashTable();

var keys = []
var values = []
for (var i = 0;i< 100000;i++){
    keys.push(makeid())
    values.push(Math.round())
}

console.time("SET")
for (var i = 0;i < keys.length;i++){
    dict.set(keys[i], values[i])
}
console.timeEnd("SET")

console.time("GET")
for (var i = 0;i < keys.length;i++){
    var val = dict.get(keys[i])
}
console.timeEnd("GET")