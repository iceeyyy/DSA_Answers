function canBeEqual(s1: string, s2: string): boolean {
    let even_s1 = [s1[0], s1[2]].sort();
    let even_s2 = [s2[0], s2[2]].sort();
        
    let odd_s1 = [s1[1], s1[3]].sort();
    let odd_s2 = [s2[1], s2[3]].sort();
        
    return even_s1.toString() === even_s2.toString() && odd_s1.toString() === odd_s2.toString();
};