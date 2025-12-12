x = int(input("Enter any number greater than 0: "))
count = 0
if x < 0:
    x *= -1
if x == 0:
    print("Enter a number greater than 0!")  # This error can be fixed using if else
while x > 0:
    y = x % 10
    count += 1
    x = (x - y) / 10
print("The number of digits in the input is ", count)
