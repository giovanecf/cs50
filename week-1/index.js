function exercice1(WALL_HEIGHT_INFORMED_BY_USER) {
  if (WALL_HEIGHT_INFORMED_BY_USER <= 0) {
    console.log("Digite um valor válido.");
    return;
  }

  for (let i = 0; i <= WALL_HEIGHT_INFORMED_BY_USER; i++) {
    const spaces_quantity = WALL_HEIGHT_INFORMED_BY_USER - i;

    let row = "";
    for (let s = 0; s < spaces_quantity; s++) {
      row += " ";
    }

    for (let h = 0; h < i; h++) {
      row += "#";
    }

    console.log(row);
  }
}

function exercice2(WALL_HEIGHT_INFORMED_BY_USER) {
  if (WALL_HEIGHT_INFORMED_BY_USER <= 0) {
    console.log("Digite um valor válido.");
    return;
  }

  for (let i = 0; i <= WALL_HEIGHT_INFORMED_BY_USER; i++) {
    const spaces_quantity = WALL_HEIGHT_INFORMED_BY_USER - i;

    let row = "";
    for (let s = 0; s < spaces_quantity; s++) {
      row += " ";
    }

    for (let h = 0; h < i; h++) {
      row += "#";
    }

    row += "  ";

    for (let h = 0; h < i; h++) {
      row += "#";
    }

    console.log(row);
  }
}

function exercice3(change, coins_values = [25, 10, 5, 1]) {
  if (change <= 0) return false;
  if (typeof change !== "number") return false;

  const units = parseInt(parseFloat(change).toString().split(".")[0]);
  const decimals = parseInt(parseFloat(change).toString().split(".")[1]);

  const change_in_cents = units * 100 + decimals;

  let change_coins = [];
  let change_left = change_in_cents;

  // Todo later: DESC RE-ORDER
  coins_values = coins_values;

  while (change_left > 0) {
    for (const coin_value of coins_values) {
      if (change_left >= coin_value) {
        change_coins.push(coin_value);
        change_left = change_left - coin_value;
        break;
      }
    }
  }

  return change_coins;
}

function exercice4(card_number) {
  if (card_number <= 0) return false;
  if (typeof card_number !== "number") return false;
  if (card_number.toString().length < 13) return false;

  const num_arr = card_number.toString().split("");
  const reverse_num_arr = num_arr.reverse();

  let total = 0;
  const first_step_numbers = [];

  for (let i = 1; i < reverse_num_arr.length; i += 2) {
    const digit = parseInt(reverse_num_arr[i]);
    first_step_numbers.push(digit * 2);
  }

  for (const f_s_num of first_step_numbers) {
    for (const d of f_s_num.toString().split("")) {
      const digit = parseInt(d);
      total += digit;
    }
  }

  for (let i = 0; i < reverse_num_arr.length; i += 2) {
    const digit = parseInt(reverse_num_arr[i]);
    total += digit;
  }

  if (total % 10 !== 0) return "INVALID";

  card_number = card_number.toString();
  if (card_number[0] == 4) return "VISA";

  if (card_number.slice(0, 2) == 34 || card_number.slice(0, 2) == 37)
    return "AMERICAN EXPRESS";

  if (
    card_number.slice(0, 2) == 51 ||
    card_number.slice(0, 2) == 52 ||
    card_number.slice(0, 2) == 53 ||
    card_number.slice(0, 2) == 54 ||
    card_number.slice(0, 2) == 55
  )
    return "MASTERCARD";
}

console.log(exercice4(4003600000000014));
