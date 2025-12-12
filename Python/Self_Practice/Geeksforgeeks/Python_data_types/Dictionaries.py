# Dictionaries in python
# data structure like sets, but have distinct differences that make them unique.

# Characteristics of a dictionary:
# Collection of Key-Value Pairs: Dictionaries store values in pairs, where each key is associated with a value.
# Unordered: All the items in a dictionary are unordered.
# Unique Keys: All the keys in a dictionary must be uniqque.
# Duplicate Values: Unlike keys, Duplicate values are allowed.
# Keys must be immutable (e.g., string, number, tuple), and values can be of any type.
# Dictionary uses internal hashing to access and organise all the data.

# Creating and using Dictionaries:
d = {100: "Abhay", 105: "Anshuman", 110: "Prince"}
print(d)
print(
    d[105]
)  # Always the value on the left of the colon is the input. That value must be unique.
d = {}  # Declaring Empty Dictionary
d["Abhay0"] = 5000  # Entering items in a dictionary
d["Abhay1"] = 5001
d["Abhay2"] = 5002
print(d)
print(d["Abhay1"])

# Real world Application of dictionaries:
# Word Dictionary
# College Roll Number
# Election Vote Counting

# Accessing Dictionary values with the get() function
# This function acts as a safe gateway and allows accessing the values without raising an error if the key does not exist.
print(d.get("Abhay2"))
print(d.get(500001))  # Prints None since the key does not exist.
print(d.get(50001, "NA"))  # Prints NA if the key is not available.
if 125 in d:
    print(d["Abhipsa"])  # Not using the get function to avoid errors.
else:
    print("NA")

# Modifying Dictionaries
print(len(d))  # prints the size of the dictionary
print(d.pop("Abhay1"))  # pops the item and returns the value
print(d)
del d["Abhay0"]  # Pops the item without returning anything
print(d)
d["Abhipsa"] = 9937538398
print(d)
d.popitem()  # Returns the tuple in which the last entered item is present.
print(d)
print("Thanks for going through my code. Ok Thank you!")
