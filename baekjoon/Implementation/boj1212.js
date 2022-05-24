const fs = require("fs");
const input = fs.readFileSync('./input.txt').toString().split('\n');

const table = {
    "0" : "000",
    "1" : "001",
    "2" : "010",
    "3" : "011",
    "4" : "100",
    "5" : "101",
    "6" : "110",
    "7" : "111"
};

const tableWithoutZero = {
    "0" : "0",
    "1" : "1",
    "2" : "10",
    "3" : "11"
}
function solve(){
    let octalNum = input[0];
    let answer = "";
    
    for(let i = 0; i < octalNum.length; i++){
        if(i==0 && octalNum[i] < 4){
            answer = answer + tableWithoutZero["" + octalNum[i]];
        }
        else{
            answer = answer + table["" + octalNum[i]];
        }
    }

    console.log(answer);
}

solve();