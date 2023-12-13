total = 0
cvar = True
for i,k in enumerate(lines):
    setss = k.strip().split(': ')[1].split('; ')
    print(setss)
    for sets in setss:
        base_dict = {"green": 0, "blue":0, "red": 0}
        for element in sets.split(', '):
            #print(element)
            number, colour = element.split()
            base_dict[colour] = int(number)
            #print(base_dict)
        if base_dict["green"] > 13 or base_dict["blue"] > 14 or base_dict["red"] > 12:
                break
    else:
            total += i + 1
print(total)
