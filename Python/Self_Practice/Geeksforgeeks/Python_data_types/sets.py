# Sets in Python

# Like lists, sets can contain items of the same type, or of different types like those of strings, integers,and other sets.
# Sets can contain only mutable objects. Sets cannot contain lists, as they are mutable. They can contain a specific type of set called
# frozensets that are immutable(cannot be changed).
# Sets can contain Tuples, if and only if the tuple contains immutable items. If the tuple contains a list, the tuple cannot be included in
# the set.
# Unordered: Sets do not contain items in an ordered manner. If you print a set, the items may appear in any random order.
# Since sets are unordered, they dont support indexing. Hence the items in the set cannot be accessed via indices.
# Sets cannot contain duplicate items. If an element, say 20 is entered twice in the set, the 20 is registered once.

# Advantages of using a set:
# Operations like union, intersection and difference are performed real fast using sets.
# Internally sets use hashing, which allows for faster search, insert and delete operations.

s1 = {100, 200, 300}  # Sets can be declared using braces
print(type(s1), s1)
s2 = set([40, 50, 60])  # Sets can be declared using the set() constructor as well.
print(type(s2), s2)
s3 = {}  # Empty Braces declare a dictionary, and not an empty set.
print(type(s3), s3)
s4 = set()  # To create an empty set, a set constructor is used.
print(type(s4), s4)
# Frozenset Example:
fs = frozenset([1, 2, 3])
s = {fs, 10, 20}
print(s)  # Valid

new_set = s1.copy()
# Above function is intact for keeping the original set intact before performing destructive operations.

# Set comprehension:
squares = {x * x for x in range(1, 6)}
print(squares)  # {1, 4, 9, 16, 25}


# Adding elements to a set:
s = {10, 20, 30, 40}  # Consider this set.
s.add(60)
print(s)
s.add(50)
print(s)
s.add(50)
print(s)  # No Multiple elements are allowed.
s.update(
    s1
)  # The update() function can add multiple elements at once, be it from another list, another set or tuple.
print(s)

# Removing elements from a set
s.discard(100)  # Removes the element. If not found, does nothing.
print(s)
s.remove(200)  # Removes the element. If not found, Raises an error.
print(s)
s.clear()  # Clears the entire set.
print(s)
s.add(50)
del s  # After this line, accessing s will raise an error.

# Other Set Operations
s = {10, 20, 30, 40}
print(len(s))  # Prints the length of the set
print(20 in s)  # Prints True
print(50 in s)  # Prints False
del s
# The above operations are faster in sets than that of lists due to the underlying Hashing Mechanism.

# Set Operations: Union, Intersection, Difference and symmetric difference
print(s1, " is the first set")
print(s2, " is the second set")
print(
    "The union of both the sets is ", s1 | s2
)  # '|' operator is used in the union operation.
print(
    "The intersection of both the sets is ", s1 & s2
)  # '&' operator is used in intersection operation.
print(
    "The difference of both the sets is ", s1 - s2
)  # '-' operator is used in difference operation.
print(
    "The symmetric difference of both the sets is ", s1 ^ s2
)  # '^' operator is used in symmetric difference operation.
result = (s1 | s2) - (s1 & s2)  # Equivalent to symmetric difference
print(result, "is an example of symmetric difference using union and intersection")

# Subset and superset operations
print(s1, " is the first set")
print(s2, " is the second set")
print("Is s1 equal to s2? ", s1 == s2)
print("Is s1 disjoint to s2? ", s1.isdisjoint(s2))
print("Is s1 subset to s2? ", s1 <= s2)
print("Is s1 superset to s2? ", s1 >= s2)
print("Is s1 proper subset to s2? ", s1 < s2)
print("Is s1 proper superset to s2? ", s1 > s2)

print("Thanks for going through my program, OK Thank you!")
