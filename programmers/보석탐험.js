function dist(a) {
	return a[1] - a[0];
}

function solution(gems) {
	let answer = [];
	let cnt = {};
	let kinds = new Set(gems);
	let l = 0,
		r = 0;
	kinds.forEach((x) => (cnt[x] = 0));
	kinds.clear();
	for (let i = 0; i < gems.length; i++) {
		if (!kinds.has(gems[i])) {
			kinds.add(gems[i]);
			r = i;
		}
	}
	for (let i = 0; i <= r; i++) cnt[gems[i]]++;
	answer = [l + 1, r + 1];
	while (l < r && r < gems.length) {
		if (cnt[gems[l]] === 1) {
			cnt[gems[++r]]++;
		} else {
			cnt[gems[l++]]--;
			if (dist([l, r]) < dist(answer)) answer = [l + 1, r + 1];
		}
	}
	return answer;
}
