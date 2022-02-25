/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(v1, v2) {
    v1=v1.split(".").map(Number);
    v2=v2.split(".").map(Number);
    for(let i=0;i<Math.min(v1.length,v2.length);i++){
        if(v1[i]>v2[i])
            return 1;
        else if(v2[i]>v1[i])
            return -1;
    }
    if(v1.length>v2.length){
        for(let i=v2.length;i<v1.length;i++){
            if(v1[i]!=0)
                return 1;
        }
    }else{
        for(let i=v1.length;i<v2.length;i++){
            if(v2[i]!=0)
                return -1;
        }
    }
    return 0;
};