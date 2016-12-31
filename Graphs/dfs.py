class node:
    def __init__(self,n):
        self.neighbors = []
        self.visited = False
        self.name = n 

def dfs(start):
    stack = []
    stack.append(start)

    while (stack != []):
        top = stack.pop()

        if (top.visited == False):

            top.visited = True
            print(top.name)
            #In this part in the termination condition

        n = top.neighbors
        for i in n:
            stack.append(i)



a = node("a")
b = node("b")
c = node("c")
d = node("d")


a.neighbors = [b,c]
c.neighbors = [d]
dfs(a)
        

