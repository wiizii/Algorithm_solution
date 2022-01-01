function solve(e, oper) {
	let ret = 0;
	let sep1 = /[-*+]/;
	let sep2 = /[0-9]+/;
	let n = e.split(sep1);
	let o = e.split(sep2);
	for (let i = 1; i < o.length - 1; i++) {
		if (o[i] === oper[0]) {
			if (o[i] === '+') n[i] = Number(n[i - 1]) + Number(n[i]);
			else if (o[i] === '-') n[i] = Number(n[i - 1]) - Number(n[i]);
			else n[i] = Number(n[i - 1]) * Number(n[i]);
			o.splice(i, 1);
			n.splice(i - 1, 1);
			i--;
		}
	}
	for (let i = 1; i < o.length - 1; i++) {
		if (o[i] === oper[1]) {
			if (o[i] === '+') n[i] = Number(n[i - 1]) + Number(n[i]);
			else if (o[i] === '-') n[i] = Number(n[i - 1]) - Number(n[i]);
			else n[i] = Number(n[i - 1]) * Number(n[i]);
			o.splice(i, 1);
			n.splice(i - 1, 1);
			i--;
		}
	}
	for (let i = 1; i < o.length - 1; i++) {
		if (o[i] === oper[2]) {
			if (o[i] === '+') n[i] = Number(n[i - 1]) + Number(n[i]);
			else if (o[i] === '-') n[i] = Number(n[i - 1]) - Number(n[i]);
			else n[i] = Number(n[i - 1]) * Number(n[i]);
			o.splice(i, 1);
			n.splice(i - 1, 1);
			i--;
		}
	}

	return Math.abs(n[0]);
}

function solution(expression) {
	let answer = 0;
	let candidate = [];
	candidate.push(solve(expression, ['*', '-', '+']));
	candidate.push(solve(expression, ['*', '+', '-']));
	candidate.push(solve(expression, ['-', '+', '*']));
	candidate.push(solve(expression, ['-', '*', '+']));
	candidate.push(solve(expression, ['+', '-', '*']));
	candidate.push(solve(expression, ['+', '*', '-']));
	answer = Math.max(...candidate);
	return answer;
}
