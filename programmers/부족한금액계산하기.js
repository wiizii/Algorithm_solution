function solution(price, money, count) {
	let answer = ((count * (count + 1)) / 2) * price - money;
	return answer < 0 ? 0 : answer;
}
