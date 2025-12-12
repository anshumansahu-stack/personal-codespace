# Given a string s of single space-separated words. Capitalize the first letter of all words and count the number of the words in the string. Print the line and the number in separate lines with new line character at the end.
s = input("Enter a string with spaces:")
count = 0
l = list(s)
for i in range(len(s)):
    if i == 0 or l[i - 1] == " ":
        a = l[i]
        n = ord(a) - 32
        l[i] = chr(n)
        count += 1
s = "".join(l)
print(s)
print(count)
