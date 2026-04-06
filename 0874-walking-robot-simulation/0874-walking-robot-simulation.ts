function robotSim(commands: number[], obstacles: number[][]): number {
    let st =  new Set<string>();

    for(let obs of obstacles){
        let key = obs[0].toString() + "_" + obs[1].toString();
        st.add(key);
    }

    let x=0;
    let y=0;
    let ans=0;

    let [dirx,diry] = [0,1];

    for(let i=0;i<commands.length;i++){
        if(commands[i]===-2){
            [dirx,diry] = [-diry,dirx]; //turning left
        }
        else if(commands[i]===-1){
            [dirx,diry] = [diry,-dirx]; //turning right
        }
        else{
            for(let j=0;j<commands[i];j++){
                let newX = x+dirx;
                let newY = y+diry;

                let nextKey = newX.toString() +"_"+ newY.toString();
                if(st.has(nextKey)){
                    break;
                }
                x=newX;
                y=newY;
            }
            
        }
        ans=Math.max(ans,x*x+y*y);
    }

    return ans;
};