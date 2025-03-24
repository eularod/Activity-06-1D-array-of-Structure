#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string firstName;
    string secondName;
    string lastName;
    string course;
    int studentID;
    double prevGPA;
};

void displayMenu()
{
    cout << "\n---Menu---\n";
    cout << "[1] Add student\n";
    cout << "[2] Edit student\n";
    cout << "[3] Delete student\n";
    cout << "[4] View students\n";
    cout << "[5] Exit\n";
    cout << "Choose an option: ";
}

const int MAX_students = 100;
Student p[MAX_students];
int studentCount = 0;

void addStudent()
{
   if (studentCount >= MAX_students)
   {
    cout << "Error: Database is full.";
    return;
   }

   Student data;
   cout << "Enter student ID: ";
   cin >> data.studentID;

    cout << "Enter First Name: ";
    cin >> data.firstName;

    cout << "Enter Last Name: ";
    cin >> data.lastName;

    cout << "Enter Course: ";
    cin >> data.course;

    cout << "Enter previous GPA: ";
    cin >> data.prevGPA;

    for (int i = 0; i < studentCount; i++)
    {
            if (data.studentID == p[i].studentID)
            {
                cout << "\nStudent ID already exists.\n";
                cout << "New Student ID: ";
                cin >> data.studentID;

                i = -1;
            }
    }

    p[studentCount++] = data;
    cout << "\nStudent added successfully!\n";
}


void editStudent()
 {
    Student data;
    if (studentCount == 0)
    {
        cout << "\nStudent not found.\n";
        return;
    }

    cout << "\nEnter student ID to edit: ";
    cin >> data.studentID;

    int studentIndex = -1;
    for (int i = 0; i < studentCount; i++)
    {
        if (p[i].studentID == data.studentID)
        {
            studentIndex = i;

            cout << "Enter new Student ID: ";
            cin >> data.studentID;

            cout << "Enter new First Name: ";
            cin >> data.firstName;

            cout << "Enter new Last Name: ";
            cin >> data.lastName;

            cout << "Enter new Course: ";
            cin >> data.course;

            cout << "Enter new previous GPA: ";
            cin >> data.prevGPA;

        }
    }

    bool FoundDuplicate = false;

        do
        {
            FoundDuplicate = false;

            for (int i = 0; i < studentCount; i++)
            {
                if (data.studentID == p[i].studentID)
                {
                    cout << "\nDuplicate Student ID found.\n";
                    cout << "New Student ID: ";
                    cin >> data.studentID;

                    FoundDuplicate = true;
                    break;
                }
            }

        } while (FoundDuplicate);


        p[studentIndex] = data;
        cout << "\nStudent updated successfully!\n";

}

void deleteStudent()
{
    Student data;
    if (studentCount == 0)
    {
        cout << "\nStudent not found.\n";
        return;
    }

    cout << "\nEnter student ID to delete: ";
    cin >> data.studentID;

    for(int i = 0; i < studentCount; i++)
    {
        if (p[i].studentID == data.studentID)
        {
           for (int j = i; j < studentCount - 1; j++)
           {
            p[i] = p[j + 1];
           }
           studentCount--;
           cout << "\nStudent deleted successfully!\n";
           return;
        }
    }
    cout << "\nStudent not found.\n";
}

void viewStudents()
{
    if (studentCount == 0)
    {
        cout << "\nNo students to display.\n";
        return;
    }

    int choice;
    cout << "\nView students by:\n";
    cout << "[1] Alphabetical order\n";
    cout << "[2] GPA (ascending)\n";
    cout << "Choose an option: ";
    cin >> choice;

    Student sortedStudents[MAX_students];
    for (int i = 0; i < studentCount; i++)
    {
        sortedStudents[i] = p[i];
    }

    if (choice == 1)
    {
        for (int i = 0; i < studentCount - 1; i++)
        {
            for (int j = 0; j < studentCount - i - 1; j++)
            {
                if ((sortedStudents[j].lastName > sortedStudents[j + 1].lastName) ||
                    (sortedStudents[j].lastName == sortedStudents[j + 1].lastName &&
                     sortedStudents[j].firstName > sortedStudents[j + 1].firstName))
                {
                    Student temp = sortedStudents[j];
                    sortedStudents[j] = sortedStudents[j + 1];
                    sortedStudents[j + 1] = temp;
                }
            }
        }
    }
    else if (choice == 2)
    {
        for (int i = 0; i < studentCount - 1; i++)
        {
            for (int j = 0; j < studentCount - 1; j++)
            {
                if (sortedStudents[j].prevGPA > sortedStudents[j + 1].prevGPA)
                {
                    Student temp = sortedStudents[j];
                    sortedStudents[j] = sortedStudents[j + 1];
                    sortedStudents[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        cout << "\nInvalid choice.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++)
    {
        cout << "ID: " << sortedStudents[i].studentID << " | "
             << sortedStudents[i].firstName << " "
             << sortedStudents[i].lastName << " | "
             << " Course: " << sortedStudents[i].course << " | GPA: "
             << sortedStudents[i].prevGPA << endl;
    }
}

int main()
{
    int choice;
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                editStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                viewStudents();
                break;
            case 5:
                cout << "\nExiting program.....\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;

}
