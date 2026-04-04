function decodeCiphertext(encodedText: string, rows: number): string {
    let l=encodedText.length;
    let m=Math.floor(l/rows);

    let orgText:string = "";

    for(let col=0;col<m;col++){
        for(let j=col;j<l;j+=(m+1)){
            orgText+=encodedText[j];
        }
    }

    let ans:string[] = orgText.split("");

    while(ans.length>0 && ans[ans.length-1]===" "){
        ans.pop();
    }

    return ans.join("");
};