let WALL_HEIGHT_INFORMED_BY_USER = 4;

if (WALL_HEIGHT_INFORMED_BY_USER <= 0) console.log("Digite um valor válido.");

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
