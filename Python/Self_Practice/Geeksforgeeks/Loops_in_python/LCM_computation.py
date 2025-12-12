x, y = int(input("Enter two numbers:")), int(input())
print("The LCM of ", x, " and ", y, " is:", end=" ")
if x == 0 or y == 0:
    print(0)
else:
    high, low = max(x, y), min(x, y)
    while high % low != 0:
        rem = high % low
        high = low
        low = rem
    print((x * y) // low)
print("OK Thank you!")
