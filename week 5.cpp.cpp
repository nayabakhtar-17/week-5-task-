/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <string>

using namespace std;

// Student class (Node)
class Student {
public:
    string name;
    int marks;
    Student* next;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
        this->next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Student* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push student onto stack
    void push(string name, int marks) {
        Student* newStudent = new Student(name, marks);
        newStudent->next = top;
        top = newStudent;
    }

    // Pop student from stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Student* temp = top;
        top = top->next;
        delete temp;
    }

    // Display all students in stack
    void display() {
        Student* temp = top;
        while (temp != nullptr) {
            cout << "Name: " << temp->name << ", Marks: " << temp->marks << endl;
            temp = temp->next;
        }
    }

    // Display top 3 positions of students
    void displayTop3() {
        Student* temp = top;
        Student* top3[3]; // array to store top 3 students

        // Initialize top3 array with nullptr
        for (int i = 0; i < 3; i++) {
            top3[i] = nullptr;
        }

        // Find top 3 students with highest marks
        while (temp != nullptr) {
            if (top3[0] == nullptr || temp->marks > top3[0]->marks) {
                top3[2] = top3[1];
                top3[1] = top3[0];
                top3[0] = temp;
            } else if (top3[1] == nullptr || temp->marks > top3[1]->marks) {
                top3[2] = top3[1];
                top3[1] = temp;
            } else if (top3[2] == nullptr || temp->marks > top3[2]->marks) {
                top3[2] = temp;
            }
            temp = temp->next;
        }

        // Display top 3 students
        cout << "Top 3 Positions:" << endl;
        for (int i = 0; i < 3; i++) {
            if (top3[i] != nullptr) {
                cout << "Position " << (i + 1) << ": " << top3[i]->name << " - " << top3[i]->marks << endl;
            } else {
                cout << "Position " << (i + 1) << ": No student" << endl;
            }
        }
    }
};

int main() {
    Stack mainStack;

    int choice;
    do {
        cout << "1. Add student to stack" << endl;
        cout << "2. Remove student from stack" << endl;
        cout << "3. Display all students" << endl;
        cout << "4. Display top 3 positions" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int marks;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student marks: ";
            cin >> marks;
            mainStack.push(name, marks);
            break;
        }
        case 2:
            mainStack.pop();
            break;
        case 3:
            mainStack.display();
            break;
        case 4:
            mainStack.displayTop3();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}