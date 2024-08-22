class Student:

    def __init__(self, name: str, age: int, height: float):
        self.name = name
        self.age = age
        self.height = height

    def displayInfo(self):
        name = "xyz"
        print("Student Name: ", self.name)
        print("Student age: ", self.age)
        print("Student height: ", self.height)


student = Student()
