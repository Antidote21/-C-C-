function solution(array, commands) {
    const answer = [];

    for (let i = 0; i < commands.length; i++) {
        const start = commands[i][0] - 1;
        const end = commands[i][1];
        const k = commands[i][2] - 1;

        const partialArray = array.slice(start, end).sort((a, b) => a - b);
        answer.push(partialArray[k]);
    }

    return answer;
}
