def multiply_vectors(vec1, vec2):
    if len(vec1) != len(vec2):
        raise ValueError("Both vectors must be of the same length")
    for i in vec1:
        if not isinstance(i, (int, float)):
            raise TypeError("vec1 must contain only numbers")
    for i in vec2:
        if not isinstance(i, (int, float)):
            raise TypeError("vec2 must contain only numbers")
    result = []
    for i in range(len(vec1)):
        result.append(int(vec1[i]) * int(vec2[i]))
    return result
vec1 = list(map(int, input("enter number: ").split()))
vec2 = list(map(int, input("enter number: ").split()))

print(multiply_vectors(vec1, vec2))
