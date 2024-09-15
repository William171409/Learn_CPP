
int successive_decrease13(int num) {
  if (num < 0) {
    return num;
  }
  while (num >= 0) {
    num -= 13;
  }
  return num;
}