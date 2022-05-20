const fs = require("fs");
const input = fs.readFileSync('./input.txt').toString().split('\n');

function solve(){
    const lowerCaseReg = /[a-z]/;
    const upperCaseReg = /[A-Z]/;
    const numReg = /\d/;
    const spaceReg = / /;
    
    for(let i=0; i<input.length-1; i++){
        const str = input[i];
        let lowerCount = 0;
        let upperCount = 0;
        let numCount = 0;
        let spaceCount = 0;
        for (let c of str){
            if(lowerCaseReg.test(c)){
                lowerCount++;
                continue;
            }
            if(upperCaseReg.test(c)){
                upperCount++;
                continue;
            }
            if(numReg.test(c)){
                numCount++;
                continue;
            }
            if(spaceReg.test(c)){
                spaceCount++;
            }
        }
        console.log(lowerCount + ' ' + upperCount + ' ' + numCount + ' ' + spaceCount);
    }
    
}

solve();