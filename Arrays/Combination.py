array = [3,2,4,0]
n = len (array)
r = 3

def combination(data, start, index):
  if (index == r):
    print (data)
    return
  for i in range(start, n):
    """  n - i + 1 >= r - index  makes sure that
         including one element  at index will
         make a combination with remaining
         elements at remaining positions
    """
    if (n - i + 1 >= r - index):
      data[index] = array[i]
      combination(data, i+1 , index + 1)

def get_combinations(r):
  combination([0] * r, 0,  0)

if __name__ == "__main__":
  get_combinations(r=3)
