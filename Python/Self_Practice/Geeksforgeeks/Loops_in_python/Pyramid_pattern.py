# here input is the number of rows.
x = int(input("Enter the number of rows: "))
space = x - 1
# If x=5, there must be 2x-1=9 stars in the last row.
for i in range(1, x + 1):
    for j in range(1, space + 1):
        print(" ", end=" ")
    space -= 1
    for j in range(1, 2 * i):
        print("*", end=" ")
    print()
