n = int(input())

for i in range(n):
    str = input()
    str = str.split()

    for letter in str[1]:
        for j in range(int(str[0])):
            print(letter, end='')
    print()
        