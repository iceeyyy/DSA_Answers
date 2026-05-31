function asteroidsDestroyed(mass: number, asteroids: number[]): boolean {
    asteroids.sort((a,b)=>a-b)
    let masss = mass;

    for(let x of asteroids){
        if(masss>=x) masss+=x;
        else if(masss<x) return false;
    }

    return true;
};