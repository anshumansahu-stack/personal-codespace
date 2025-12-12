# import keyword
# print("Here is the complete list of keywords:")
# print(keyword.kwlist)#Complete keyword list imported

#***Value Keywords: True, False, None

# print(False==0)
# print(True==1)

# print(True+True+True)
# print(True+False+True)

# print(None==0)
# print(None==[])

# ***Operator Keywords: and, or, not,in is 

# a,b=True,False
# print(a and b)
# print(a or b)
# print(not b)

# #in keyword: checks whether a value exists in a sequence like string, tuple or list.

# print()
# list=[1,2,3,4]
# print(5 in list)
# print(3 in list)

# #is keyword: check whether two variables point to the same object in memory.

# print()
# dist=5
# cyst=[1,2,3,4]
# print(dist is cyst)
# print(list is cyst)#Prints False since another object of same value is being created
# list=cyst
# print(list is cyst)#Prints True

#*** Conditional Keywords in python: if,else,elif

# x=0
# if x>0:
#     print("positive")
# elif x<0:
#     print("negative")
# else:
#     print("zero")

#***Iteration Keywords in python: for, while break, continue, pass

# count=0
# while count<=5:
#     print(count)
#     count+=1

# print()
# count=0
# while count<=5:
#     print(count,end=" ")
#     count+=1
# print()
# #Printing triangular pattern

# for i in range(6):
#     for j in range (i):
#         print("*",end="")
#     print()
# print()

# #More Control
# import sys
# sys.stdout.write("Hello ")
# sys.stdout.write("World!")
# print()

#break and continue statements
count=0
while count<=5:
    if count==1:
        count+=1
        continue
    print(count,end=" ")
    count+=1
print()

count=0
while count<=5:
    if count==1:
        count+=1 
        break
    print(count,end=" ")
    count+=1
print()

#Pass is the null statement in python. nothing happens when this is encountered.
#comparing pass and null statements

for i in range(6):
    if i==2:
        continue
    if i==3:
        pass #Nothing happens. code runs as usual.
    print(i,end=" ")
print() 

