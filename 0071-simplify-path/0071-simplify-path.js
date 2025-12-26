/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    let arr = path.split('/');
    let n = arr.length;
    let stack = [];

    for(let i=0;i<n;i++){
        if(arr[i]=="" || arr[i]==".") continue;
        else if(arr[i]==".."){
            if(stack.length>0) stack.pop(); //remove the last directory in case of parent
        }
        else{
            stack.push(arr[i]);
        }
    }

    return '/' + stack.join('/');
};