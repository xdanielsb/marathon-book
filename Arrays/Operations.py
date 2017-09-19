from itertools import permutations, combinations

def pers(array):
    ps = permutations(array)
    for p in ps: print (p)

def combs(array, r=2):
    cmb = combinations(array, r)
    for c in cmb: print (c)

if __name__ == "__main__":
    pers([1,2,3,4,5])
    combs([1,2,3,4,5])
