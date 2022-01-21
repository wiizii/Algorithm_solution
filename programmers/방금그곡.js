function solution(m, musicinfos) {
	var answer = '(None)';
	var answerSet = [];
	var info = [];
	musicinfos.map((x) => info.push(x.split(',')));
	m = replaceNote(m);
	for (var i = 0; i < info.length; i++) {
		info[i][3] = replaceNote(info[i][3]);
		var start = getTime(info[i][0]);
		var end = getTime(info[i][1]);
		var playTime = end[0] * 60 + end[1] - (start[0] * 60 + start[1]);
		var note = info[i][3];
		while (info[i][3].length < playTime) info[i][3] += note;
		info[i][3] = info[i][3].slice(0, playTime);
		if (info[i][3].indexOf(m) !== -1) answerSet.push([playTime, i, info[i][2]]);
	}
	answerSet.sort((a, b) => {
		if (a[0] > b[0]) return -1;
		else if (a[0] === b[0]) {
			if (a[1] > b[1]) return 1;
			else return -1;
		} else return 1;
	});
	console.log(answerSet);
	return answerSet.length ? answerSet[0][2] : '(None)';
}

function getTime(times) {
	return times.split(':').map((x) => parseInt(x));
}

function replaceNote(note) {
	var tmp = note.replace(/(C#)/g, 'c').replace(/(D#)/g, 'd').replace(/(F#)/g, 'f').replace(/(G#)/g, 'g').replace(/(A#)/g, 'a');
	return tmp;
}
