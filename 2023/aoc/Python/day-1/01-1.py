with open("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\Python\\day-1\\input.txt") as f:
  line = f.readlines()

  totalsum = 0
  for i in line:
    list1 = []
    for k in i:
      if k.isdigit() == True:
        k = int(k)
        list1.append(k)
    x = 10*list1[0] + list1[-1]
    totalsum += x
print(totalsum)