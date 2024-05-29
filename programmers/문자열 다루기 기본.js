function solution(s) {
    var answer = false;
    var len = s.length;
    if(len == 4 || len == 6)answer = true;
    for(var i=0; i<len; i++){
        if(s[i]>='A'&&s[i]<='z'){
           answer = false;
         }
    }
    return answer;
}
