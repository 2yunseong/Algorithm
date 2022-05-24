const fs = require("fs");
const input = fs.readFileSync('./input.txt').toString().split('\n');

const table = {
    "000" : "0",
    "001" : "1",
    "010" : "2",
    "011" : "3",
    "100" : "4",
    "101" : "5",
    "110" : "6",
    "111" : "7"
};
function solve(){
    let binaryNum = input[0];
    let answer = "";
    while(binaryNum.length % 3 != 0){
        binaryNum = "0" + binaryNum;
    }
    for(let i=0; i<binaryNum.length; i+=3){
        let keyBinary = "";
        for(let j=i; j<3+i; j++){
            keyBinary += binaryNum[j];
        }
        answer += table[keyBinary]; 
    }

    console.log(answer);
}

solve();