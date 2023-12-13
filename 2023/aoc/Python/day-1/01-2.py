with open("Advent of Code Day 1.txt") as f:
    lines = f.readlines()

totalsum=0
words = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
for line in lines:
    idx = []
    nums = []
    for i in range(len(words)):
        word = words[i]
        if word in line:
            idx.append(line.index(word))
            nums.append(i+1)
            if line.index(word)!=line.rindex(word):
                idx.append(line.rindex(word))
                nums.append(i+1)    
    for i in range(len(line)):
        char = line[i]
        if char.isdigit() == True and char !="0":
            idx.append(i)
            nums.append(int(char))
    no1 = nums[idx.index(min(idx))]
    no2 = nums[idx.index(max(idx))]
    #if min(idx) == max(idx): totalsum+=10*int(no1)
    totalsum+=10*int(no1) + int(no2)
print(totalsum)
