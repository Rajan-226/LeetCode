/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    s=s.split(" ");
    if(pattern.length!=s.length)
        return false;
    var obj={},obj2={};
    for(let i=0;i<s.length;i++){
        if(!(pattern[i] in obj)){
            if(s[i] in obj2)
                return false;
            obj[pattern[i]]=s[i];
            obj2[s[i]]=pattern[i];
        }
        if(obj[pattern[i]]!=s[i])
            return false;
        
    }
    return true;
};