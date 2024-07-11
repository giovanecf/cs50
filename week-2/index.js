/*
  A number of “readability tests” have been developed over the years that 
  define formulas for computing the reading level of a text. One such 
  readability test is the Coleman-Liau index. The Coleman-Liau index of 
  a text is designed to output that (U.S.) grade level that is needed 
  to understand some text. The formula is:

    index = 0.0588 * L - 0.296 * S - 15.8
    where:
      L is the average number of letters per 100 words in the text, and 
      S is the average number of sentences per 100 words in the text.
*/
function isLetter(l) {
  return "a" <= l.toLowerCase() && l.toLowerCase() <= "z";
}

function getNumOfLetters(text) {
  return text
    .trim()
    .replace(/\s/g, "")
    .split("")
    .filter((l) => isLetter(l)).length;
}

function getNumOfWords(text) {
  return text.trim().split(" ").length;
}

function getNumOfSentences(text) {
  return text
    .trim()
    .split("")
    .filter((l) => l === "." || l === "?" || l === "!").length;
}

function exercice1(text) {
  const num_of_words = getNumOfWords(text);
  const num_of_letters = getNumOfLetters(text);
  const num_of_sentences = getNumOfSentences(text);

  const L = num_of_letters / (num_of_words / 100);
  const S = num_of_sentences / (num_of_words / 100);
  const grade = 0.0588 * L - 0.296 * S - 15.8;

  return Math.round(grade);
}

const r = exercice1(
  `Ao subir lentamente, Frodo passou por vários flets: alguns de um
  lado, outros na posição oposta, e outros ainda colocados na copa da árvore,
  de modo que a escada passava por todos eles. N uma grande altura acima do
  solo, deparou com um grande talan, semelhante ao convés de um grande
  navio. Sobre ele estava construída uma casa, tão grande que quase poderia
  ser utilizada como salão para homens no chão. Frodo entrou atrás de H aldir,
  e viu -se num cômodo de formato oval, no meio do qual crescia o tronco do
  grande mallorn, nesse ponto se afilando em direção a coroa, e mesmo assim
  formando um pilar bem largo.`
);

console.log(r);
