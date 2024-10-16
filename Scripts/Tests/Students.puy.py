
header = ["StudentName", "Std", "BloopGroup", "Contact"]


Student = [] # empty list for now // to contain the particular student data.
Students = [] # to contains all the students.

def GetStudents():

    print("Enter Student Enteries: \n")
    for col in header:
        Student.append(input(f"{col}: "))

    Students.append(Student.copy())
    Student.clear()


GetStudents()

for col in header:
    print(col, endl='\t')

for student in Students:
    print("\t".join(student))
