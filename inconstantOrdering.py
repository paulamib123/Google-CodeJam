def inconstantOrdering(arr, n):  #odd rev
    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    ans = "A"

    for i in range(len(arr)):
        if i % 2 == 0:
            ans += alpha[1: arr[i] + 1]
        else:
            chars = alpha[ : arr[i]][::-1]
            if ans[-1] <= chars[0]:
                index = alpha.index(chars[0])
                newChar = alpha[index + 1]
                new = ans[:-1] + newChar
                ans = new
            ans += chars

    return ans;


def main():
    t = int(input())
    for count in range(1, t + 1):
        n = int(input())
        arr = list(map(int, input().split()))
        ans = inconstantOrdering(arr, n)
        print("Case #" + str(count) + ": " + ans)

main()