numbers = []
flag = False
number_of_values = int(input("The number of values to enter "))

for i in range(number_of_values):
    x = int(input("Enter a number "))
    numbers.append(x)
    
value = int(input("Enter a number to seach for"))

for i in range(len(numbers)): #will iterate over each index
    if numbers[i] == value:
        flag = True #indicates that the value is found
        break
    
if flag == True:
    print(value, "found at ", (i+1), "position")
else:
    print("Number not found")