const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString();

function solve() {
    let barCount = 0;
    let answer = 0;
    let prev = '';
    for(let c of input){
        if( c == '('){
            barCount++;
            prev = '(';
        }
        else if(c == ')'){
            if(prev == '('){
                barCount -= 1;
                answer += barCount;
            }
            else if(prev == ')'){
                answer += 1
                barCount--;
            }
            prev = ')';
        }
    }

    console.log(answer);
}

solve();