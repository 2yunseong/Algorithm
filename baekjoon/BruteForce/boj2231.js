let fs = require("fs");
const input = fs.readFileSync("./input.txt").toString().split("\n");

const main = () => {
    const n = parseInt(input);
    for(let i=0; i<=n; i++){
        let sum = 0;
        sum += i;
        const str = "" + i;
        for(s of str){
            sum += parseInt(s);
        }

        if(sum === n){
            console.log(i);
            return ;
        } 
    }
    console.log(0);
    return 0;
}

main();
