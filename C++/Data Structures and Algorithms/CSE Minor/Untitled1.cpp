
 find_roots(a, b, c):
    
    discriminant = b**2 - 4*a*c
    
    
    root1 = (-b + cmath.sqrt(discriminant)) / (2 * a)
    root2 = (-b - cmath.sqrt(discriminant)) / (2 * a)
    
    
    if discriminant > 0:
        nature = "real and different"
    elif discriminant == 0:
        nature = "real and the same"
    else:
        nature = "complex"
    
    return root1, root2, nature

def main():
    print("Quadratic equation: ax^2 + bx + c = 0")
    a = float(input("Enter coefficient a: "))
    b = float(input("Enter coefficient b: "))
    c = float(input("Enter coefficient c: "))
    
    
    if a == 0:
        print("Coefficient a cannot be zero.")
        return
    
    root1, root2, nature = find_roots(a, b, c)
    
    print(f"Root 1: {root1}")
    print(f"Root 2: {root2}")
    print(f"The roots are {nature}.")

if __name__ == "__main__":
    main()

