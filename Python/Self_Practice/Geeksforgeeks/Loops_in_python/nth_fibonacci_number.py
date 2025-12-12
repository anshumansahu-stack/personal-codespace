# Below code gives the n+1 th Fibonacci term.
n = int(input("Enter a number: "))
first, second = 1, 1
result = first + second  # second term=2
prev = second  # previous term=1
i = 2
# To add the loop n-2 more times.
while i <= n:
    temp = result
    result += prev
    prev = temp
    i += 1

print("The ", n + 1, "th value of the fibonacci sequence is ", result)
print("OK Thank you!")

# Below code gives the nth Fibonacci term.

n = int(input("Enter a number: "))
if n == 0 or n == 1:
    result = 1
else:
    first, second = 1, 1
    for i in range(2, n + 1):
        result = first + second
        first, second = second, result

print("The", n, "th value of the Fibonacci sequence is", result)

# F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) Actual Fibonacci Sequence.
# Valid question that you ask in interviews: Do you mean 0-indexed or 1-indexed Fibonacci?
