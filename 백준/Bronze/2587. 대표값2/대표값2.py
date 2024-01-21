nums = []

for i in range(5):
    nums.append(int(input()))

average = 0
for num in nums:
    average += num

average /= 5
print(int(average))

for i in range(5):
    for j in range(4):
        if nums[j] > nums[j+1]:
            temp = nums[j]
            nums[j] = nums[j+1]
            nums[j+1] = temp

print(nums[2])