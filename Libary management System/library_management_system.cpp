#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>

using namespace std;

// Define a class for Library and Database Management System
class lms
{
private:
    // Private member variables for password and student information
    string pass;
    int sid = 110, sem, totaltackenbook, takenbook[5];
    string sfname = "data Unavailable", slname = "data Unavailable", gname = "data Unavailable", address = "data Unavailable",
           email = "data Unavailable", phone = "data Unavailable", faculty;

    // Private member variables for book information
    int b_id = 650, total_page, price, noofbooks;
    string b_name, a_name;

    // Additional variables for tracking total students, subjects, and available books
    int total_s = 0, total_sub = 0, available_Book, available_Bookmenu = 0, noofbooksmenu = 0;

    //------------check book exist or not
    bool isBookIDExist(int search_id)
    {
        ifstream file("bdata.txt");
        if (!file)
        {
            cerr << "Error: Unable to open book data file." << endl;
            return false;
        }

        int b_id;
        while (file >> b_id)
        {
            if (b_id == search_id)
            {
                file.close();
                return true; // Book ID found
            }

            // Skip the rest of the book record
            string restOfLine;
            getline(file, restOfLine);
        }

        file.close();
        return false; // Book ID not found
    }

    //------------check book exist or not
    bool isstudentIDExist(int search_id)
    {
        ifstream file("sdata.txt");
        if (!file)
        {
            cerr << "Error: Unable to open student data file." << endl;
            return false;
        }
        int s_id;
        while (file >> s_id)
        {
            if (s_id == search_id)
            {
                file.close();
                return true; // Book ID found
            }

            // Skip the rest of the book record
            string restOfLine;
            getline(file, restOfLine);
        }

        file.close();
        return false; // Book ID not found
                      //------------check student exist or not
    }

    //-----for issued total book
    void decreasebookno(int search_id)
    {
        ifstream infile("bdata.txt");
        ofstream tempFile("temp.txt");

        if (!infile || !tempFile)
        {
            cout << "File error" << endl;
            return;
        }

        bool found = false;
        while (infile >> b_id >> b_name >> a_name >> price >> total_page >> available_Book >> noofbooks)
        {
            if (b_id == search_id)
            {
                found = true;

                available_Book = available_Book - 1;
                // Skip the record to be deleted
            }
            tempFile << "\t" << b_id << "\t" << b_name << "\t" << a_name << "\t" << price << "\t" << total_page << "\t" << available_Book << "\t" << noofbooks << endl;
        }

        infile.close();
        tempFile.close();

        if (!found)
        {
            cout << "somthing is wrong! Please Try again" << endl;
        }
        else
        {
            remove("bdata.txt");
            rename("temp.txt", "bdata.txt");
        }
    }
    //-----increse total book
    void increasestudentno(int student_id, int bookid2)
    {
        ifstream infile("sdata.txt");
        ofstream tempFile("temp.txt");

        if (!infile || !tempFile)
        {
            cout << "File error" << endl;
            return;
        }

        int id;
        bool found = false;

        while (infile >> id >> sfname >> slname >> gname >> address >> sem >> faculty >> phone >> email >> totaltackenbook)
        {
            for (int i = 0; i < 5; i++)
            {
                infile >> takenbook[i];
            }

            if (id == student_id)
            {
                found = true;
                if (totaltackenbook >= 5)
                {
                    infile.close();
                    tempFile.close();
                    remove("temp.txt");
                    system("cls");
                    cout << "Student has already taken 5 books. Sorry, cannot add more books." << endl;
                    mainmenu();
                }
                for (int i = 0; i < totaltackenbook; i++)
                {
                    if (takenbook[i] == bookid2)
                    {
                        cout << '\t' << "this  Book is alrady tacken. Try another book" << endl;
                        infile.close();
                        tempFile.close();
                        remove("temp.txt");
                        issudebook();
                    }
                }
                takenbook[totaltackenbook] = bookid2;
                totaltackenbook++;
                cout << '\t' << "Book ID " << bookid2 << " added successfully." << endl;
            }

            tempFile << id << "\t" << sfname << "\t" << slname << "\t" << gname << "\t" << address << "\t" << sem << "\t" << faculty << "\t" << phone << "\t" << email << "\t" << totaltackenbook;
            for (int i = 0; i < 5; i++)
            {
                tempFile << "\t" << takenbook[i];
            }
            tempFile << endl;
        }

        infile.close();
        tempFile.close();

        if (!found)
        {
            cout << '\t' << "Student not found with the given ID." << endl;
        }
        else
        {
            remove("sdata.txt");
            rename("temp.txt", "sdata.txt");
        }
    }

    //----- for recived total book
    void increasebookno(int search_id)
    {
        ifstream infile("bdata.txt");
        ofstream tempFile("temp.txt");

        if (!infile || !tempFile)
        {
            cout << "File error" << endl;
            return;
        }

        bool found = false;
        while (infile >> b_id >> b_name >> a_name >> price >> total_page >> available_Book >> noofbooks)
        {
            if (b_id == search_id)
            {
                found = true;

                available_Book = available_Book + 1;
                // Skip the record to be deleted
            }
            tempFile << "\t" << b_id << "\t" << b_name << "\t" << a_name << "\t" << price << "\t" << total_page << "\t" << available_Book << "\t" << noofbooks << endl;
        }

        infile.close();
        tempFile.close();

        if (!found)
        {
            cout << "somthing is wrong! Please Try again" << endl;
        }
        else
        {
            remove("bdata.txt");
            rename("temp.txt", "bdata.txt");
        }
    }

    void decreasestudentno(int student_id, int bookid2)
    {
        ifstream infile("sdata.txt");
        ofstream tempFile("temp.txt");

        if (!infile || !tempFile)
        {
            cout << "File error" << endl;
            return;
        }

        int id;
        bool found = false;

        while (infile >> id >> sfname >> slname >> gname >> address >> sem >> faculty >> phone >> email >> totaltackenbook)
        {
            for (int i = 0; i < 5; i++)
            {
                infile >> takenbook[i];
            }

            if (id == student_id)
            {
                found = true;

                if (totaltackenbook < 1)
                {
                    cout << "Student Tacken Book number is 0" << endl;
                    infile.close();
                    tempFile.close();
                    remove("temp.txt");
                    mainmenu();
                }

                bool bookFound = false;
                for (int i = 0; i < totaltackenbook; i++)
                {
                    if (takenbook[i] == bookid2)
                    {
                        bookFound = true;
                        for (int j = i; j < totaltackenbook - 1; j++)
                        {
                            takenbook[j] = takenbook[j + 1];
                        }
                        takenbook[totaltackenbook - 1] = 0;
                        totaltackenbook--;
                        cout << '\t' << "Book ID " << bookid2 << " received successfully in library." << endl;
                        break;
                    }
                }

                if (!bookFound)
                {
                    cout << '\t' << "This book is not taken by this student" << endl;
                    infile.close();
                    tempFile.close();
                    remove("temp.txt");
                    mainmenu();
                }
            }

            // Write student details back to the temporary file
            tempFile << id << "\t" << sfname << "\t" << slname << "\t" << gname << "\t" << address << "\t" << sem << "\t" << faculty << "\t" << phone << "\t" << email << "\t" << totaltackenbook;
            for (int i = 0; i < 5; i++)
            {
                tempFile << "\t" << takenbook[i];
            }
            tempFile << endl;
        }

        infile.close();
        tempFile.close();

        if (!found)
        {
            cout << '\t' << "Student not found with the given ID." << endl
                 << endl
                 << endl;
        }
        else
        {
            remove("sdata.txt");
            rename("temp.txt", "sdata.txt");
        }
    }

public:
    // Function to handle user login
    void login()
    {
        int ch;
        cout << '\t' << " " << endl
             << endl
             << endl;
        cout << '\t' << "====================================================================" << endl;
        cout << '\t' << '\t' << '\t' << "WELCOME TO LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << '\t' << "====================================================================" << endl;

        // Prompt user for password
        cout << "\t" << "Please Enter Authorized Key: ";
        while (ch = getch())
        {
            if (ch == 13)
            {
                if (pass == "abc")
                {
                    cout << "\nLogin successful" << endl;
                    break;
                }
                pass = "";
                cout << "\t" << "\nPassword Incorrect. Please try again." << "\n"
                     << endl;
                login(); // Recursive call to login again if password is incorrect
            }
            else if (ch == 8)
            {
                if (pass.length() > 0)
                {

                    cout << "\b\b" << endl;
                    pass.erase(pass.length() - 1);
                }
            }
            else
            {
                cout << "*";
                pass += ch;
            }
        }
    }

    // Function to display the main menu
    void mainmenu()
    {
        int choice;
        do
        {
            ifstream file("sdata.txt");  // Open the file containing student data
            ifstream bfile("bdata.txt"); // Open the file containing book data

            total_s = 0,
            total_sub = 0,
            available_Bookmenu = 0,
            noofbooksmenu = 0;

            // Read student data line by line from the file
            while (file >> sid >> sfname >> slname >> gname >> address >> sem >> faculty >> phone >> email >> totaltackenbook)
            {
                total_s++;
            }
            // Read book data line by line from the file
            while (bfile >> b_id >> b_name >> a_name >> price >> total_page >> available_Book >> noofbooks)
            {
                total_sub = total_sub + 1;
                available_Bookmenu = available_Bookmenu + available_Book;
                noofbooksmenu = noofbooksmenu + noofbooks;
            }

            file.close();  // Close the student data file after reading
            bfile.close(); // Close the book data file after reading
            system("cls");

            cout << '\t' << " " << endl
                 << endl
                 << endl;
            cout << '\t' << "===================================================" << endl
                 << endl;
            cout << '\t' << '\t' << "WELCOME TO LIBRARY MANAGEMENT SYSTEM" << endl
                 << endl;
            cout << '\t' << "===================================================" << endl;
            cout << '\t' << "---------------------------------------------------" << endl;
            cout << '\t' << "Total number of books: " << noofbooksmenu << '\t' << "Total students: " << total_s << endl;
            cout << '\t' << "---------------------------------------------------" << endl;
            cout << '\t' << "1. Student Details" << endl;
            cout << '\t' << "2. Book Details" << endl;
            cout << '\t' << "3. Issude and Recived Book" << endl;
            cout << '\t' << "4. Display all Student Details" << endl;
            cout << '\t' << "5. Display all Book Details" << endl;
            cout << '\t' << "6. Add Student/Book Details" << endl;
            cout << '\t' << "7. Close Application" << endl;
            cout << '\t' << "---------------------------------------------------" << endl;
            cout << '\t' << "Total subjects (books): " << total_sub << '\t' << "Total available books: " << available_Bookmenu << endl;
            cout << '\t' << "---------------------------------------------------" << endl;

            cout << '\t' << "Please Enter Your Choice: ";
            cin >> choice;
            system("cls");

            switch (choice)
            {
            case 1:
                student_details();
                break;
            case 2:
                book_details();
                break;
            case 3:
                issuderecivebook();
                break;
            case 4:
                all_student_details();
                break;
            case 5:
                all_book_details();
                break;
            case 6:
                add_book_student_details();
                break;
            case 7:
                exitProgram();
                break;
            default:
                system("cls");
                cout << "Invalid Choice. Please Try Again." << endl;
            }
        } while (choice != 7);
    }

    //--------main menu -1 ------------------------------
    void student_details()
    {
        system("cls");               // Clear the console screen
        ifstream file("sdata.txt");  // Open the file containing student data
        ifstream bfile("bdata.txt"); // Open the file containing book data

        if (!file || !bfile)
        {
            cout << "File error" << endl; // Display an error message if file opening fails
            return;
        }

        cout << '\t' << " " << endl
             << endl
             << endl;
        cout << '\t' << "---------------------------------------------------" << endl;
        cout << '\t' << "---------------------------------------------------" << endl;
        int search_id;
        cout << '\t' << "Please Enter a Student ID: ";
        cin >> search_id;
        cout << '\t' << "---------------------------------------------------" << endl;

        bool found = false;
        // Read student data line by line from the file
        while (file >> sid >> sfname >> slname >> gname >> address >> sem >> faculty >> phone >> email >> totaltackenbook)
        {
            for (int i = 0; i < 5; i++)
            {
                file >> takenbook[i];
            }

            if (search_id == sid)
            {
                // Display the student details if the ID matches
                found = true;
                cout << '\t' << "---------------------------------------------------" << endl;
                cout << '\t' << "Student ID: " << sid << endl;
                cout << '\t' << "Student First Name: " << sfname << endl;
                cout << '\t' << "Student Last Name: " << slname << endl;
                cout << '\t' << "Semester: " << sem << endl;
                cout << '\t' << "Faculty: " << faculty << endl;
                cout << '\t' << "Guardian Name: " << gname << endl;
                cout << '\t' << "Contact No.: " << phone << endl;
                cout << '\t' << "Email: " << email << endl;
                cout << '\t' << "Total taken book: " << totaltackenbook << endl;
                cout << '\t' << "Total taken book ID(s): ";

                while (bfile >> b_id >> b_name)
                {
                    for (int i = 0; i < totaltackenbook; i++)
                    {
                        if (takenbook[i] == b_id)
                        {
                            cout << b_name << "(" << b_id << ") " << "\t";
                        }
                    }
                }

                cout << endl
                     << '\t' << "---------------------------------------------------" << endl
                     << endl;
                break; // Stop searching once the student is found
            }
        }

        file.close(); // Close the file after reading
        bfile.close();

        if (!found)
        {
            // Display a message if student with the provided ID is not found
            cout << endl
                 << endl
                 << '\t' << "Student not found with the given ID." << endl
                 << endl;
        }

        cout << '\t' << "---------------------------------------------------" << endl;

        int ch;
        do
        {
            cout << '\t' << "Enter Your Choice: " << endl;
            cout << '\t' << "1. Search for another student details" << endl;
            cout << '\t' << "2. Return to Main Menu" << endl;
            cin >> ch;

            switch (ch)
            {
            case 1:
                system("cls");
                student_details(); // Recursively call the function to search for another student
                return;            // Return after the recursive call to prevent further execution
            case 2:
                system("cls");
                mainmenu(); // Return to the main menu
                return;     // Return to prevent further execution
            default:
                system("cls");
                cout << '\t' << "Wrong Input" << endl;
                mainmenu();
            }
        } while (ch != 2);

        cout << '\t' << "---------------------------------------------------" << endl;
    }

    //--------main menu -2 ------------------------------
    void book_details()
    {
        system("cls"); // Clear the console screen

        ifstream file("bdata.txt"); // Open the file containing book data

        if (!file)
        {
            cout << "File error" << endl; // Display an error message if file opening fails
            return;
        }

        int book_id;
        cout << '\t' << " " << endl
             << endl
             << endl;
        cout << '\t' << "---------------------------------------------------" << endl;
        cout << '\t' << "---------------------------------------------------" << endl;
        cout << '\t' << "Please Enter a Book ID: ";
        cin >> book_id; // Prompt user to enter a book ID
        cout << '\t' << "---------------------------------------------------" << endl;

        bool found = false;
        // Read book data line by line from the file

        while (file >> b_id >> b_name >> a_name >> price >> total_page >> available_Book >> noofbooks)
        {
            if (book_id == b_id)
            { // Check if the current book ID matches the user-provided ID
                found = true;
                cout << '\t' << "---------------------------------------------------" << endl;
                cout << '\t' << "Book ID: " << b_id << endl;
                cout << '\t' << "Book Name: " << b_name << endl;
                cout << '\t' << "Total Pages: " << total_page << endl;
                cout << '\t' << "Author Name: " << a_name << endl;
                cout << '\t' << "Price: " << price << endl;
                cout << '\t' << "No of Available Book : " << available_Book << endl;
                cout << '\t' << "No of total books : " << noofbooks << endl;
                cout << '\t' << "---------------------------------------------------" << endl;
                break; // Stop searching once the book is found
            }
        }

        file.close(); // Close the file after reading

        if (!found)
        {
            cout << "\t" << "Book not found with the given ID." << endl; // Display a message if book with the provided ID is not found
        }

        cout << '\t' << "---------------------------------------------------" << endl;

        int ch;
        do
        {
            cout << "\t"
                    "Enter Your Choice: "
                 << endl;
            cout << "\t"
                    "1. Search for another Book details"
                 << endl;
            cout << "\t"
                    "2. Return to Main Menu"
                 << endl;
            cin >> ch; // Prompt user for choice

            switch (ch)
            {
            case 1:
                book_details(); // Call the function recursively to search for another book
                break;
            case 2:
                system("cls");
                mainmenu(); // Return to the main menu
                break;
            default:
                system("cls");
                cout << "Wrong Input" << endl;
                mainmenu(); // Return to the main menu in case of invalid input
            }
        } while (ch != 2);
    }

    // issude recive books-----3-------------------------
    void issuderecivebook()
    {
        int choice, bookIDToIssue;
        cout << '\t' << "------------------------------------" << endl;
        cout << '\t' << "Please Enter your choice:" << endl;
        cout << '\t' << "1. Issude Book" << '\t' << "2. Recived Book" << endl;
        cout << '\t' << "------------------------------------" << endl;
        cin >> choice;

        // Process user's choice
        switch (choice)
        {
        case 1:
            issudebook(); // Call add_student() to add a new student
            break;
        case 2:
            recive_book(); // Call add_book() to add a new book
            break;
        default:
            system("cls");
            cout << "Invalid Choice" << endl;
            mainmenu();
        }
    }
    /// for issuded book------- //
    void issudebook()
    {
        int book_id;
        cout << '\t' << " Enter Book ID: ";
        cin >> book_id;

        if (!isBookIDExist(book_id))
        {
            system("cls");
            cout << " This  Book ID is not exist" << endl;
            issudebook();
        }

        int student_id;
        cout << '\t' << " Enter Student ID: ";
        cin >> student_id;

        if (!isstudentIDExist(student_id))
        {
            cout << " This  Student ID is not exist" << endl;
            mainmenu();
        }
        decreasebookno(book_id);
        increasestudentno(student_id, book_id);
        system("cls");
        cout << "Issued book by student ID " << endl;
        mainmenu();
    }
    //-------- receved book by student
    void recive_book()
    {
        system("cls");
        int book_id;
        cout << '\t' << " Enter Book ID : ";
        cin >> book_id;

        if (!isBookIDExist(book_id))
        {
            cout << " This  Book ID is not exist" << endl;
            mainmenu();
        }
        int student_id;
        cout << '\t' << " Enter Student ID : ";
        cin >> student_id;

        if (!isstudentIDExist(student_id))
        {
            system("cls");
            cout << " This  Student ID is not exist" << endl;
            mainmenu();
        }

        increasebookno(book_id);
        decreasestudentno(student_id, book_id);
        system("cls");
        cout << '\t' << "Received book by student ID " << endl;
        mainmenu();
    }

    //--------main menu -4 ------------------------------
    void all_student_details()
    {
        system("cls"); // Clear the console screen

        ifstream file("sdata.txt"); // Open the file containing student data

        if (!file)
        {
            cout << "File error" << endl; // Display an error message if file opening fails
            return;
        }

        cout << '\t' << "All Student Details:" << endl
             << endl
             << endl;
        cout << '\t' << "S.no" << '\t' << "Student_id" << '\t' << "First_Name" << '\t' << "Last_Name" << '\t' << "Semester" << '\t' << "Faculty" << '\t' << '\t' << "Guardian_Name" << '\t' << "Contact_No. " << '\t' << "Email" << '\t' << "Total taken books" << endl;

        total_s = 0; // Initialize the total student count

        // Read student data line by line from the file
        while (file >> sid >> sfname >> slname >> gname >> address >> sem >> faculty >> phone >> email >> totaltackenbook)
        {
            total_s++; // Increment the total student count for each student

            // Display student details in formatted output
            cout << '\t' << "------------------------------------------------------------------------------------------------------" << endl;
            cout << '\t' << total_s << '\t' << sid << '\t' << '\t' << sfname << '\t' << '\t' << slname << '\t' << '\t' << sem << '\t' << '\t' << faculty << '\t' << '\t' << gname << '\t' << '\t' << phone << '\t' << '\t' << email << '\t' << '\t' << totaltackenbook << "\n";
        }

        cout << '\t' << "---------------------------------------------------" << endl;
        cout << '\t' << "Total Students: " << total_s << endl; // Display the total number of students
        cout << '\t' << "---------------------------------------------------" << endl;

        file.close(); // Close the file after reading

        int ch;
        do
        {
            cout << '\t' << "---------------------------------------------------" << endl
                 << endl
                 << endl;
            cout << '\t' << "Enter 1 to return to the main menu" << endl
                 << '\t';
            cin >> ch; // Prompt user for input

            switch (ch)
            {
            case 1:
                system("cls");
                mainmenu(); // Return to the main menu
                break;
            default:
                system("cls");
                cout << "Wrong Input" << endl; // Display message for invalid input
                mainmenu();                    // Return to the main menu
            }
        } while (ch != 1);
    }

    //--------main menu -5 ------------------------------
    void all_book_details()
    {
        system("cls"); // Clear the console screen

        ifstream file("bdata.txt"); // Open the file containing book data

        if (!file)
        {
            cout << "File error" << endl; // Display an error message if file opening fails
            return;
        }

        cout << '\t' << "All Book Details:" << endl
             << endl
             << endl;
        cout << '\t' << "S.no" << '\t' << "Book_id" << '\t' << '\t' << "Book_Name" << '\t' << "Author_name" << '\t' << "Price" << '\t' << '\t' << "Total_page" << '\t' << "available Book" << '\t' << "Total_Books" << endl;

        total_sub = 0; // Initialize the total book count

        // Read book data line by line from the file
        while (file >> b_id >> b_name >> a_name >> price >> total_page >> available_Book >> noofbooks)
        {
            total_sub++; // Increment the total book count for each book

            // Display book details in formatted output
            cout << '\t' << "------------------------------------------------------------------------------------------------------" << endl;
            cout << '\t' << total_sub << '\t' << b_id << '\t' << '\t' << b_name << '\t' << '\t' << a_name << '\t' << '\t' << price << '\t' << '\t' << total_page << '\t' << '\t' << available_Book << '\t' << '\t' << noofbooks << endl;
        }

        file.close(); // Close the file after reading

        cout << '\t' << "---------------------------------------------------" << endl;
        cout << '\t' << "Total Books: " << total_sub << '\t' << "Enter 1 to return to the main menu" << endl;
        cout << '\t' << "---------------------------------------------------" << endl
             << '\t';

        int ch;
        cin >> ch; // Prompt user for input

        switch (ch)
        {
        case 1:
            system("cls");
            mainmenu(); // Return to the main menu
            break;
        default:
            cout << "Wrong Input" << endl; // Display message for invalid input
        }
    }

    //--------main menu -6 ------------------------------
    void add_student()
    {
        // Open the file "sdata.txt" in append mode
        ofstream file("sdata.txt", ios::app);
        if (!file)
        {
            cout << "File error" << endl;
            return;
        }

        // Increment student ID for the new student
        sid++;
        totaltackenbook = 0;
        // Prompt user to enter student details
        cout << endl
             << endl;
        cout << "\t" << "student First name: ";
        cin >> sfname;

        cout << "\t" << "student Last name: ";
        cin >> slname;

        cout << "\t" << "student Guardian name: ";
        cin >> gname;

        cout << "\t" << "student address: ";
        cin >> address;

        cout << "\t" << "student semester: ";
        cin >> sem;

        cout << "\t" << " faculty: " << endl;
        cout << "\t" << "Note: Faculty options are BIT, BBA, BCA, CSIT: ";
        cin >> faculty;
        if (!(faculty == "BIT" || faculty == "bit" || faculty == "bba" || faculty == "BBA" || faculty == "bca" || faculty == "BCA" || faculty == "BIT" || faculty == "CSIT"))
        {
            cout << "Wrong input for faculty." << endl;
            mainmenu();
        }

        cout << "\t" << "student phone: ";
        cin >> phone;

        cout << "\t" << " student email: ";
        cin >> email;

        // Write student details to the file in a tab-separated format
        file << sid << "\t" << sfname << "\t" << slname << "\t" << gname << "\t"
             << address << "\t" << sem << "\t" << faculty << "\t" << phone << "\t" << email << "\t" << totaltackenbook << "\t" << takenbook[5] << endl;

        // Close the file
        file.close();

        // Increment total student count
        total_s++;

        // Prompt user for further action
        int ch;
        cout << "\t" << "-------------------------------------------------------" << endl;
        cout << "\t" << "Student ID is  " << sid << endl;
        cout << "\t" << "Student details added Successfully ! " << endl;
        cout << "\t" << "-------------------------------------------------------" << endl;
        cout << "\t" << "Enter Your Choice" << endl;
        cout << "\t" << "1. Add another Student" << '\t' << "2. Main Menu" << endl;
        cin >> ch;

        // Process user's choice
        switch (ch)
        {
        case 1:
            add_student(); // Recursively call add_student() to add another student
            break;
        case 2:
            system("cls");
            mainmenu(); // Return to main menu
            break;
        default:
            cout << "Wrong Input" << endl;
        }
    }
    void add_book()
    {
        // Open the file "bdata.txt" in append mode
        ofstream file("bdata.txt", ios::app);
        if (!file)
        {
            cout << "File error" << endl;
            return;
        }

        // Increment book ID for the new book
        b_id++;

        // Prompt user to enter book details
        cout << "\t" << "Book Name: ";
        cin >> b_name;

        cout << "\t" << "Book Author Name: ";
        cin >> a_name;

        cout << "\t" << "Book Price: ";
        cin >> price;

        cout << "\t" << "Book total page: ";
        cin >> total_page;

        cout << "\t" << "total Books: ";
        cin >> noofbooks;
        available_Book = noofbooks;
        // Write book details to the file
        file << b_id << "\t" << b_name << "\t" << a_name << "\t" << price << "\t" << total_page << "\t" << available_Book << "\t" << noofbooks << endl;

        // Close the file
        file.close();

        // Increment total book count
        total_sub++;

        // Prompt user for further action
        int ch;
        cout << "\t" << "--------------------------------------------------------------" << endl;
        cout << "\t" << "Book id is " << b_id << endl;
        cout << "\t" << "Book added successfully ! " << endl;
        cout << "\t" << "--------------------------------------------------------------" << endl;
        cout << "\t" << "Enter Your Choice" << endl;
        cout << "\t" << "1. Add another Book" << '\t' << "2. Main Menu" << endl;
        cin >> ch;

        // Process user's choice
        switch (ch)
        {
        case 1:
            add_book(); // Recursively call add_book() to add another book
            break;
        case 2:
            system("cls");
            mainmenu(); // Return to main menu
            break;
        default:
            system("cls");
            cout << "Wrong Input" << endl;
            mainmenu(); // Return to main menu
        }
    }
    void add_book_student_details()
    {
        int choice;
        cout << endl
             << endl
             << endl;
        cout << "\t" << "-------------------------------------------------------" << endl;

        cout << "\t" << "Please Enter your choice:" << endl;
        cout << "\t" << "1. Add Student" << '\t' << "2. Add Book" << endl;
        cout << "\t" << "-------------------------------------------------------" << endl;

        cout << "\t";
        cin >> choice;
        cout << "\t" << "-------------------------------------------------------" << endl;

        // Process user's choice
        switch (choice)
        {
        case 1:
            add_student(); // Call add_student() to add a new student
            break;
        case 2:
            add_book(); // Call add_book() to add a new book
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }

    //--------main menu -7 ------------------------------
    void exitProgram()
    {

        exit(0);
    }
};

int main()
{
    lms obj;
    obj.login();
    obj.mainmenu();

    return 0;
}
