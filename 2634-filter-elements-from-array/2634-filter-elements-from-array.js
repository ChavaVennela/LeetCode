/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var arr1=arr.map(fn);
    var ans=[];
    for(let i=0; i<arr.length; i++){
        if(arr1[i]){
            ans.push(arr[i]);
        }
    }
    return ans;
    
};