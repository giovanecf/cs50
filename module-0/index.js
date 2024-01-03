const names = ["a", "b", "c", "d", "e", "f", "g", "h"];

function getLongArr(size = 1000000) {
  const arr = [];
  for (let i = 0; i < size; i++) {
    arr.push(`${i}`);
  }
  return arr;
}

function basicSearch(target_element = "", elements_arr = []) {
  for (let i = 0; i < elements_arr.length; i++) {
    if (elements_arr[i] === target_element) return elements_arr[i];
  }
  return "Not found!";
}

function dobleBasicSearch(target_element = "", elements_arr = []) {
  for (let i = 0; i < elements_arr.length; i += 2) {
    if (elements_arr[i] === target_element) return elements_arr[i];
  }
  return "Not found!";
}

function binarySearch(target_element = "", elements_arr = []) {
  let new_array = elements_arr;
  let arr_middle_index = Math.floor(new_array.length / 2);
  let start = 0;
  let end = new_array.length;
  while (start - end > 1) {
    if (new_array[arr_middle_index] === target_element)
      return new_array[arr_middle_index];

    if (new_array[arr_middle_index] > target_element) {
      end = start + arr_middle_index - 1;

      arr_middle_index = start + Math.floor((end - start) / 2);
    } else if (new_array[arr_middle_index] < target_element) {
      start = arr_middle_index;

      arr_middle_index = start + Math.floor((end - start) / 2);
    }
  }

  return "Element not found";
}

const long_arr = getLongArr(10000000);

const timer_start = new Date().getTime();

//const r = basicSearch("A", long_arr);

//const r = dobleBasicSearch("A", long_arr);

const r = binarySearch("A", long_arr);

const timer_end = new Date().getTime();

console.log(`Result: ${r} (${timer_end - timer_start}ms)`);
