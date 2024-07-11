import process from "node:process";

function addVote(voted_name, candidates, points = 0) {
  const index = candidates.findIndex(
    (c) => c.name.toLowerCase() === voted_name.toLowerCase()
  );
  index;

  if (index === -1) return null;

  if (points > 0) {
    candidates[index].points += points;
    candidates[index].votes += points === candidates.length ? 1 : 0;
  } else candidates[index].votes += 1;

  return candidates;
}

function getWinner(candidates, in_points = false) {
  let max = 0;
  let winner = {};

  for (const c of candidates) {
    const number = in_points ? c.points : c.votes;
    if (number > max) {
      max = number;
      const index = candidates.indexOf(c);
      winner = candidates[index];
    }
  }

  return winner;
}

function exercice1() {
  const VOTES = ["Marilda", "Ivanei", "Thomas", "Stephanie", "Thomas"];
  const NUM_VOTES = VOTES.length;
  const candidates_names = process.argv.slice(2);

  if (candidates_names.length < 2) return "Less then 2 candidates set";

  let candidates = candidates_names.map((c) => ({ name: c, votes: 0 }));

  for (const vote of VOTES) {
    const arr = addVote(vote, candidates);
    candidates = arr ? arr : candidates;
  }

  return getWinner(candidates).name;
}

function exercice2() {
  const ranked_votes = [
    ["Thomas", "Marilda", "Ivanei", "Stephanie"],
    ["Thomas", "Ivanei", "Marilda", "Stephanie"],
    ["Ivanei", "Stephanie", "Thomas", "Marilda"],
    ["Ivanei", "Marilda", "Thomas", "Stephanie"],
    ["Marilda", "Ivanei", "Thomas", "Stephanie"],
    ["Thomas", "Stephanie", "Ivanei", "Marilda"],
    ["Stephanie", "Ivanei", "Marilda", "Thomas"],
  ];

  const candidates_names = process.argv.slice(2);

  if (candidates_names.length < 2) return "Less then 2 candidates set";

  let candidates = candidates_names.map((c) => ({
    name: c,
    votes: 0,
    points: 0,
  }));

  for (const rv of ranked_votes) {
    const names_reversed = rv.reverse();
    for (const nr of names_reversed) {
      const votes_in_points = names_reversed.indexOf(nr) + 1;
      candidates = addVote(nr, candidates, votes_in_points);
    }
  }

  const winner_in_votes = getWinner(candidates);

  if (winner_in_votes.votes > ranked_votes.length / 2)
    return "Winner by majority: " + winner_in_votes.name;
  else return "Winner by rank: " + getWinner(candidates, true).name;
}

function registerX1Match(winner, loser, current_pair_votes, ref_candidates) {
  const winner_index = ref_candidates.indexOf(winner); //0 (Alice)
  const loser_index = ref_candidates.indexOf(loser); //1 (Bob)

  current_pair_votes[winner_index][loser_index] += 1;

  return current_pair_votes;
}

function winnersPairsAndWinDiffOnX1Match(m) {
  const pairs = [];
  for (let i = 0; i < m.length; i++) {
    for (let j = i; j < m[i].length; j++) {
      if (i === j) continue;
      if (m[i][j] >= m[j][i]) pairs.push([i, j, m[i][j] - m[j][i]]);
      else pairs.push([j, i, m[j][i] - m[i][j]]);
    }
  }

  return pairs;
}

function hasCycle(arr) {
  const winners = [];
  for (let i = 0; i < arr.length; i++) {
    if (winners.indexOf(arr[i][0]) > -1) return false;
    else winners.push(arr[i][0]);
  }

  return true;
}

function exercice3() {
  const CANDIDATES = ["Alice", "Bob", "Charlie"];
  const ranked_votes = [
    ["Thomas", "Marilda", "Ivanei", "Stephanie"],
    ["Thomas", "Ivanei", "Marilda", "Stephanie"],
    ["Ivanei", "Stephanie", "Thomas", "Marilda"],
    ["Ivanei", "Marilda", "Thomas", "Stephanie"],
    ["Marilda", "Ivanei", "Thomas", "Stephanie"],
    ["Thomas", "Stephanie", "Ivanei", "Marilda"],
    ["Stephanie", "Ivanei", "Marilda", "Thomas"],
  ];
  const ballots = [
    ["Alice", "Bob", "Charlie"],
    ["Alice", "Bob", "Charlie"],
    ["Alice", "Bob", "Charlie"],
    ["Bob", "Charlie", "Alice"],
    ["Bob", "Charlie", "Alice"],
    ["Charlie", "Alice", "Bob"],
    ["Charlie", "Alice", "Bob"],
    ["Charlie", "Alice", "Bob"],
    ["Charlie", "Alice", "Bob"],
  ];

  //START - VOTES
  let just_by_votes = CANDIDATES.map((c) => ({ name: c, votes: 0 }));
  ballots.forEach((b) => {
    just_by_votes = addVote(b[0], just_by_votes);
  });

  const winner_by_vote = getWinner(just_by_votes);
  if (winner_by_vote.votes > ballots.length / 2) return winner_by_vote.name;
  //END - VOTES

  //Tideman
  const candidates = CANDIDATES;
  let score_matrix = Array(candidates.length)
    .fill(0)
    .map(() => Array(candidates.length).fill(0));

  for (let i = 0; i < candidates.length; i++) {
    for (let row = 0; row < ballots.length; row++) {
      const home_candidate_points =
        ballots[row].length - ballots[row].indexOf(candidates[i]);

      for (let collumn = 0; collumn < ballots[row].length; collumn++) {
        if (ballots[row][collumn] === candidates[i]) continue;
        const visit_candidate_points = ballots[row].length - collumn;

        if (home_candidate_points > visit_candidate_points)
          score_matrix = registerX1Match(
            candidates[i],
            ballots[row][collumn],
            score_matrix,
            CANDIDATES
          );
      }
    }
  }

  const score_pairs = winnersPairsAndWinDiffOnX1Match(score_matrix);

  const sorted_score_pairs = score_pairs.sort((a, b) => b[2] - a[2]);

  const has_cycle = hasCycle(sorted_score_pairs);

  let tideman_winner_index = sorted_score_pairs[0][0];
  if (has_cycle) {
    tideman_winner_index =
      sorted_score_pairs[sorted_score_pairs[0].length - 2][0];
  }

  return CANDIDATES[tideman_winner_index];
}

//
