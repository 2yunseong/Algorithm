const fs = require("fs");
const input = fs.readFileSync('./input.txt').toString().split('\n');

function solve(){
    const n = parseInt(input[0]);
    
    for(let i=1; i<n+1; i++){
        const strArr = input[i].split(' ');
        const ansArr = [];
        strArr.forEach((e) => {
            let reverseWord = "";
            e.split('').reverse().forEach((char) => {
                reverseWord += char;
            })
            ansArr.push(reverseWord);
        })
        const ans = ansArr.join(' ');
        console.log(ans);
    }
}

solve();