n = int(input("Enter a number:"))
fact = True
if n <= 1:
    print("Not Prime!")
else:
    for i in range(2, n):
        if n % i == 0:
            fact = False
            print("Not Prime!")
            break
    if fact:
        print("Prime!")

# Another logic: If there is no factor till sqrt(n), there is no chance that further a factor will appear.
# Good for optimisation.
