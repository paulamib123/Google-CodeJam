from itertools import permutations, combinations


def makePermuatations(n):
    perms = []
    perms =  permutations(range(1, n + 1))
    return perms

def revEngineer(n, perm, expectedCost):
    perm = list(perm)
    minValIndex = 0
    minVal = perm[0]
    cost = 0;

    for i in range(0,n - 1):
        
        minValIndex = i
        minVal = perm[i]

        for j in range(i, n):
            if (minVal > perm[j]):
                minVal = perm[j]
                minValIndex = j;

        cost += (minValIndex - i + 1)
        perm = perm[:i] + perm[i : minValIndex + 1][::-1] + perm[minValIndex + 1:]
    return cost == expectedCost

def helperMain(n, expectedCost):
    perms = []
    perms = makePermuatations(n)
    for perm in perms:
        temp = list(perm)
        if (revEngineer(n, perm, expectedCost)):
            return temp

def main():
    t = int(input())
    for count in range(1, t + 1):
        ans = []
        n, c = input().split()
        ans = helperMain(int(n), int(c))
        print("Case #" + str(count) + ": ", end="")
        if (ans == None):
            print("IMPOSSIBLE")
        else:
            result = ""
            for i in ans:
                result += str(i) + " "
            print(result[:-1])

main()


