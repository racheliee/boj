#find fractions
n = int(input())

#find the diagonal line
line = 1
while n > line:
    n -= line #subtract the number of diagonal line from n
    line +=1
    
# print("line: " + str(line)) 
# print("n: " + str(n))

#find the numerator and denominator
# even line
if line %2 == 0:
    numerator = n
    denominator = line-n+1
#odd line
else:
    numerator = line-n+1
    denominator = n
    
print(str(numerator) + "/" + str(denominator))
