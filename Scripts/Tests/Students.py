
header = ["StudentName", "Std", "BloopGroup", "Contact"]


def GetStudents():
    Student = [] # empty list for now // to contain the particular student data.
    Students = [] # to contains all the students.
    
    for i in range(2):
        print("Enter Student Enteries: \n")
        Student.clear()
        
        for col in header:
            
            Student.append(input(f"{col}: "))

        Students.append(Student.copy())
    
    return Students


Students = GetStudents()

print("%-20s \t %-20s \t %-20s \t %-20s" % (header[0], header[1], header[2], header[3]))

for student in Students:
    print()
    print("%-20s \t %-20s \t %-20s \t %-20s" %(student[0],student[1], student[2], student[3]))
