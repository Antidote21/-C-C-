function solution(s) {
    var answer = true;
    var len = s.length;
    for(var i=0; i<len; i++){
        if(s[i]>='A'&&s[i]<='z'){
           answer = false;
         }
    }
    return answer;
}
