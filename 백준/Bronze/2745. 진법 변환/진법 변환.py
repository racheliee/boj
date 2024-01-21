given = input().split()
n = given[0]
b = int(given[1])

exponent = 0
decimal = 0

#A = 65, Z = 90
for letter in n[::-1]:
    if letter >= 'A':
        decimal += (ord(letter)-55)*(b**exponent)
    else:
        decimal += int(letter)*(b**exponent)
    exponent += 1

print(decimal)