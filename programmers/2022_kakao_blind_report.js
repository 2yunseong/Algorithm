function solution(id_list, report, k) {
  const answer = new Array(id_list.length).fill(0);

  const uniqueReport = [...new Set([...report])];
  const users = id_list.map((user, idx) => ({
    id: idx,
    name: user,
    count: 0,
    reportFroms: [],
  }));

  // 신고 결과 수합
  uniqueReport.forEach((r) => {
    const [from, to] = r.split(' ');
    const toIdx = users.findIndex((u) => u.name === to);
    users[toIdx].count++;
    users[toIdx].reportFroms.push(from);
  });

  const banUsers = users.filter((u) => u.count >= k);

  banUsers.forEach((b) => {
    b.reportFroms.forEach((r) => {
      const mailId = id_list.findIndex((i) => i === r);
      answer[mailId]++;
    });
  });

  return answer;
}
