n = int(input())

nums = []
for i in range(n):
    nums.append(int(input()))

for i in range(n):
    for j in range(n-1):
        if nums[j] > nums [j+1]:
            temp = nums[j]
            nums[j] = nums[j+1]
            nums[j+1] = temp
        
for num in nums:
    print(num)