
def checksum(list1, num):

    for i in range(0, len(list1)):

        if list1[i] == num:
            print("In list at postition of ", i+1)
        else:
            print("Number is not in list")



list1 = []

print("HOw many numbers: ")

n = int(input())

for i in range(0, n):

    print("Enter number: ", i+1)

    number = int(input())
    list1.append(number)


print("Enter the number to be searched: ")

item = int(input())

checksum(list1, item)
    
        
