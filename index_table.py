import json


students = []
index = []

def create_students():
    global students
    with open('students.json', 'r', encoding='utf-8') as file: 
        students = json.load(file)

def print_students():
    for student in students:
        print(f"Nombre: {student['Nombre']} --- Codigo: {student['Codigo']} --- Carrera: {student['Carrera']}")

def binary_search_index(code: int):
    lower = 0
    upper = len(index) - 1
    while lower <= upper:
        middle = (lower + upper) // 2
        if index[middle][0] == code:
            return index[middle][1] #trae el indice del codigo que se encontro para buscarlo en la tabla original
        if index[middle][0] < code:
            lower = middle + 1
        else:
            upper = middle - 1
    return -1

def search(code: int):
    student_i = binary_search_index(code)
    if student_i != -1:
        print(students[student_i])
    else:
        print("Student not found")


def index_create():
    global index
    for i, student in enumerate(students):
        index.append((student['Codigo'], i))
    index = sorted(index, key=lambda x: x[0])
    print(index)

create_students()
print_students()
index_create()
search(1701)