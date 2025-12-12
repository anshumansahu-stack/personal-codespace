arr = (1, 2, 3, 4, 5)
i = 0
j = set()
while i < len(arr):
    j.add(arr[i])
    i = i + 1
if len(arr) == len(j):
    print(True)
else:
    print(False)
