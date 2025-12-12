n = int(input("Enter a number:"))
print("The divisors are: ")
print("1", end=",")
for i in range(2, n):
    if n % i == 0:
        print(i, end=",")
print(n, ".")

# print(i, end=", " if i != n else ".\n")\
# Use the above line to diminish the weird space before the fullstop in the output.
