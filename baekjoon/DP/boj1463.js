const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split('\n');

function min(a, b){
    if(a > b) return b;
    return a;
}
function solve(){
    const n = parseInt(input[0]);
    const d = [];
    d[1] = 0;
    for(let i=2; i<=n; i++){
        d[i] = d[i-1]+1; // 1을 더해서 만들 수 있는 것
        if(i%2 ==0) d[i] = min(d[i], d[i/2]+1);
        if(i%3 ==0) d[i] = min(d[i], d[i/3]+1);
    }
    console.log(d[n]);
}

solve();