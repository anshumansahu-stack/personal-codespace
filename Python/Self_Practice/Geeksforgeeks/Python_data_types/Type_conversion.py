# Type conversion in python can be of two types:
# 1: Implicit type conversion: This type of conversion takes place without the programmer taking action on the code.
# 2: Explicit Type conversion: This type of conversion requires the programmer to write some code for the conversion to take place.
# Implicit Type Conversion
a = 2
b = 3.5
c = a + b  # a typecasted to float
print(c)
d = True
e = c + d  # d typecasted to float, value 1
print(e)
# Explicit Type Conversion
s = "135"
t = 10 + int(s)
print(t)
print(float(t))
# Interconversion between different containers is entirely possible. i.e.
name = "Anshuman"
print(list(name))
print(tuple(name))
print(set(name))

# String representation of containers
l = [a, b, c]  # given a list
print(str(l))  # Outputs the entire list as a string
x = 15
print(str(l) + str(x))  # Here the actual difference can be noticed.
# Converting Containers to lists
m = tuple(l)  # List converted into a tuple
n = set(l)  # List converted into a set
l = list(m)  # Tuple Converted to a list
l = list(n)

# converting only the items in a list to normal string:
l = ["a", "b", "c"]
result = "".join(
    l
)  # provide space between the '' if you want spaces between the strings. Any other separator works similarly.
print(result)  # Output: abc

# Binary, Octal And Hexadecimal Conversions
number = 99375
print(bin(number))  # 0b11000010000101111
print(oct(number))  # 0o302057
print(hex(number))  # 0x1842f
# The prefixes 0b, 0o and 0x denote teh numbers are binary, octal and hexadecimal respectively, hence separating from normal integers.

# To convert a binary, octal or hexadecimal number to integer, use the number with the corresponding base.
a = "10101"
print(int(a, 2))  # for Binary
b = "76432"
print(int(b, 8))  # for Octal
c = "4372F"
print(int(c, 16))  # for hexadecimal
# if you already have the 0b/0o/0x prefix then the base neednt be mentioned.
