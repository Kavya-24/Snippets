#Python program that rotates an array by two positions to the right
orig_list = [23, 12, 5, 24, 23, 76, 86, 24, 86, 24, 75]  
print("Original list before rotation: ", orig_list)  
n=2 # rotate by 2 places
if n>len(orig_list):
    n = int(n%len(orig_list))
orig_list = (orig_list[-n:] + orig_list[:-n])
print("List after rotation is : ", orig_list) 
