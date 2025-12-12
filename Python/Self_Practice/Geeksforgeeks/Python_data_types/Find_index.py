# Given a tuple arr with distinct elements and an integer x, find the index position of x.
# Assume to have x in the tuple always. Print the index (0-based).
arr = (0, 1, 2, 3, 4, 5)
x = 3
i = 0
while i < len(arr):
    if arr[i] == x:
        print(i)
        break
    i = i + 1
# else, an alternative method
# print(arr.index(x))  # directly prints the index. Uncomment this to see effect.
