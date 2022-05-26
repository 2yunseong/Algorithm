const fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().trim();


const solve = () => {
    let result = "";
    let buffer = "";
    let isTagOn = false;
    
    for(let i = 0; i<input.length; i++){
        if(input[i] === '<'){
            result += [...buffer].reverse().join("");
            buffer = "";
            result += input[i];
            isTagOn = true;
            continue;
        }
        if(input[i] === '>'){
            result += input[i];
            isTagOn = false;
            continue;
        }
        if(isTagOn){
            result += input[i];
            continue;
        }
        if(!isTagOn){
            if(input[i] === ' '){
                result += [...buffer].reverse().join("");
                buffer = "";
                result += input[i];
            } else {
                buffer += input[i];
            }
        }
    }
    result += [...buffer].reverse().join("");
    console.log(result);
}

solve();
