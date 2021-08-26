function parse(s) {
	const result = s
		.substring(2, s.length - 2)
		.split('},{')
		.map((v) => v.split(',').map((v) => parseInt(v)));
	return result;
}

function solution(s) {
	const answer = [];
	const tuples = parse(s);
	tuples.sort((a, b) => a.length - b.length);
	const set = new Set();
	for (let i = 0; i < tuples.length; i++) {
		for (let j = 0; j < tuples[i].length; j++) {
			const k = tuples[i][j];
			if (!set.has(k)) {
				answer.push(k);
				set.add(k);
			}
		}
	}
	return answer;
}
