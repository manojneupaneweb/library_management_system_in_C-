### 2nd Semester C++ College Project  

# Library and Database Management System (LMS)  

This project is a console-based **Library and Database Management System** developed in **C++**. It allows users to manage student details, book details, and book issuance efficiently.

---

## Project Features  

1. **Login System**  
   - Ensures authorized access with password verification.

2. **Main Menu**  
   - Displays total books and students.
   - Provides options for various operations:
     - Student Details
     - Book Details
     - Issuing and Receiving Books
     - Displaying All Details
     - Adding New Records  
     
3. **Core Functionalities**  
   - **Student Details**: Search and display information by student ID.  
   - **Book Details**: Search and display book information.  
   - **Issuing Books**: Allow students to borrow books.  
   - **Receiving Books**: Track book returns.  
   - **Adding Records**: Add new students or books to the system.  

4. **File Handling**  
   - All data is stored in external files (`sdata.txt` for student data, `bdata.txt` for book data).  

5. **Error Handling**  
   - Prevents invalid inputs and displays appropriate error messages.

---

## Functions Overview  

Here is a brief explanation of the key functions:  

- `login()`: Handles user authentication.  
- `mainmenu()`: Displays the main menu with options to access different modules.  
- `student_details()`: Fetches and displays student information from the database.  
- `book_details()`: Fetches and displays book information from the database.  
- `issuderecivebook()`: Manages book issuance and receiving.  
  - `issudebook()`: Issues a book to a student.  
  - `recive_book()`: Processes the return of a book.  
- `all_student_details()`: Displays all student records.  
- `all_book_details()`: Displays all book records.  
- `add_student()`: Adds a new student to the database.  
- `add_book()`: Adds a new book to the database.  
- `add_book_student_details()`: Manages combined student and book addition.  
- `exitProgram()`: Exits the application.  

---

## How to Run  

1. Compile the project using a C++ compiler (e.g., g++).  
   ```bash
   g++ lms.cpp -o lms
   ```  
2. Run the executable.  
   ```bash
   ./lms
   ```  
3. Follow the on-screen instructions to navigate the system.  

---

## System Requirements  

- **Operating System**: Windows/Linux  
- **Compiler**: Any C++ compiler (e.g., GCC, Turbo C++)  

---

## Project Details  

- **Project Name**: Library and Database Management System (LMS)  
- **Developer**: Manoj Neupane  
- **Semester**: 2nd Semester  
- **Course**: Bachelor of Information Technology (BIT)  

---  

This project demonstrates practical use of **OOP**, **file handling**, and **control structures** in C++. It can be further enhanced with a GUI or integrated into a web application for broader functionality.  

