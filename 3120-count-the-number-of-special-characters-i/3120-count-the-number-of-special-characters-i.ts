function numberOfSpecialChars(word: string): number {
    let st = new Set<string>();
    let cnt=0;

    for(let ch of word){
        let up = ch.toUpperCase();
        let lw = ch.toLowerCase();
        if(word.includes(up) && word.includes(lw) && !st.has(lw)){
            cnt++;
            st.add(lw);
        }
    }
    
    return cnt;
};