def permutation(array, start = 0):
  if (start == len(array)):
    print(array)
    return
  for i in range(start, len(array)):
    array[start], array[i] = array[i], array[start]
    permutation(array, start + 1)
    array[start], array[i] = array[i], array[start]
if __name__ == "__main__":
  permutation(['d','a','n'])
