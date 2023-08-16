# first importing the json module
import json  # to work wit json data
import random  # to generate random numbers

# opening the file
file = open("Person data.json")

data = json.load(file)  # data is dictionary
users = data["users"]  # users is a list from data

# print(data)

# 1. retrieve the required data.


# subject to allocate for each student.
subjects = ["hindi", 'english', 'science', 'math', 'social science']


# function to extract info
def extract_info(user, keys=["id", 'firstName', 'lastName', 'email']):
    user_data = {}
    for key in keys:
        user_data[key] = user.get(key, "")

    user_data["marks"] = {subject: random.randint(
        30, 100) for subject in subjects}
    return user_data


# Calculate result for each individual subject
# calculating that a student pass or failed in individual subjects
def calculate_result(student, min_pass=45):

    marks = student["marks"]
    test_result = {}
    for subject, mark in marks.items():

        if mark > min_pass:
            test_result[subject] = True
        else:
            test_result[subject] = False

    return (student['firstName']+" "+student["lastName"], test_result)


# pass or fail
def pass_fail(student):
    name, subjects = student
    return (name, all(subjects.values()))


# data pipeline for each operation.

# 1. creating map with all students and extract info.
school_student = map(extract_info, users)


def markSheet(students):

    lw = 120
    print("="*lw)
    print(f"{'Name':20s} {'Hindi':15s} {'English':15s} {'Science':15s} {'Math':15s} {'Social Science':15s}")
    print("="*lw)

    for student in students:
        name = student.get("firstName")

        marks = student.get("marks")

        hindi_marks = marks.get("hindi", 0)
        english_marks = marks.get("english", 0)
        science_marks = marks.get("science", 0)
        math_marks = marks.get("math", 0)
        social_marks = marks.get("social science", 0)

        print(f"{name:20s} {hindi_marks:<15d} {english_marks:<15d} {science_marks:<15d} {math_marks:<15d} {social_marks:<15d}")


# 2. Creating map with all student to get pass fail result in each subject.
# school_student_result1 = map(calculate_result, school_student)

markSheet(school_student)


# school_student_result_final = map(pass_fail, school_student_result1)

# for name, result in school_student_result_final:
#     print(f"{name:20s} {result}")
