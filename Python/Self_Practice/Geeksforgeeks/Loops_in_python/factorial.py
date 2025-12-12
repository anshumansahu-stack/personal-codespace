x = int(input("Enter a number:"))
result = 1
print("The factorial of ", x, " is ", end="")
while x > 1:
    result *= x
    x -= 1
print(result)
print("OK Thank you!")
