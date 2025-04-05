# Student Management System

## Description
This is a simple Student Management System implemented in C. The program allows users to perform various operations on student records, including adding, displaying, searching, updating, and deleting student information. It also provides functionality to calculate average GPA and find the student with the highest GPA.

## Features
- Add a new student with ID, name, age, and GPA
- Display all students in the system
- Search for a student by ID
- Update student information (name, age, GPA)
- Delete a student record
- Calculate average GPA of all students
- Find the highest GPA among students

## Data Structure
The program uses a linked list to store student records. Each node in the list contains:
- Student data (ID, name, age, GPA)
- Pointer to the next student node

## Functions
1. `addStudent()` - Adds a new student to the end of the list
2. `displayStudents()` - Displays all student records
3. `searchStudentByID()` - Searches for a student by ID
4. `updateStudent()` - Updates a student's information
5. `deleteStudent()` - Deletes a student record
6. `calculateAverageGPA()` - Calculates the average GPA of all students
7. `searchHighestGPA()` - Finds the highest GPA among students

## How to Use
1. Compile the program using a C compiler (e.g., gcc)
2. Run the executable
3. Follow the menu prompts to perform operations

## Menu Options
1. Add a Student
2. Display All Students
3. Search For a Student by ID
4. Update Student Information
5. Delete a Student
6. Calculate Average GPA
7. Find Student with Highest GPA
8. Exit

## Requirements
- C compiler (e.g., gcc)
- Standard C libraries

## Notes
- The program checks for duplicate IDs when adding new students
- All student data is stored in memory and not persisted to disk
- The program uses a simple console interface

## Example Usage
```bash
gcc student_management.c -o student_management
./student_management
```
