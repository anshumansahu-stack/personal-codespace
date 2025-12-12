x, y = int(input("Enter two numbers:")), int(input())
print("The GCD of ", x, " and ", y, " is:", end=" ")
if x == 0 or y == 0:
    print(max(x, y))
else:
    high, low = max(x, y), min(x, y)
    while high % low != 0:
        rem = high % low
        high = low
        low = rem
    print(low)
print("OK Thank you!")

# Below is the implementation using Pythons built in functions. Uncomment to activate.

# import math

# a = 10
# b = 15
# gcd = math.gcd(a, b)
# print("The GCD of", a, "and", b, "is", gcd)
