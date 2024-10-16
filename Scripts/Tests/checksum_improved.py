
def checknum(list1, num):

    for item in list1:

        if item == num:
            print("In list at postition of ", i+1)
            return

    print("Number is not in list")
    return


def checknum2(list, num):
    
    
    if num in list:
        return list.index(num)
    
    return -1



def checknum_print(list1, num):

    result = checknum2(list1, num)

    if result != -1:
        print("Number is found at : ", result+1)
    else:
        print("Number is not found")


list1 = []

print("HOw many numbers: ")

n = int(input())

for i in range(0, n):

    print("Enter number: ", i+1)

    number = int(input())
    list1.append(number)


print("Enter the number to be searched: ")

item = int(input())

checknum_print(list1, item)


