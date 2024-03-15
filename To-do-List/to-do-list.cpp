#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Task
{
    string description;
    string startDate;
    string endDate;
    bool status; // true if completed, false if not completed
    Task *next;
};

class TodoList
{
private:
    Task *head;

public:
    TodoList() : head(nullptr) {}

    // Function to display the menu
    // Function to display the menu
    void displayMenu()
    {
        cout     << "\n===== To-Do List Menu =====" << endl;
        cout     << "1. Add Task" << endl;
        cout     << "2. List Tasks" << endl;
        cout     << "3. Change Task Status" << endl;
        cout     << "4. Delete Task" << endl; // New option
        cout     << "5. Generate Reports" << endl;
        cout     << "6. Exit" << endl;
    }

    // Function to add a task
    void addTask()
    {
        string description, startDate, endDate;
        cout     << "Enter task description: ";
        cin.ignore();
        getline(cin, description);

        cout     << "Enter start date (YYYY-MM-DD): ";
        getline(cin, startDate);

        cout     << "Enter end date (YYYY-MM-DD): ";
        getline(cin, endDate);

        Task *newTask = new Task;
        newTask->description = description;
        newTask->startDate = startDate;
        newTask->endDate = endDate;
        newTask->status = false; // Initially, task is not completed
        newTask->next = nullptr;

        // Add task to the linked list
        if (head == nullptr)
        {
            head = newTask;
        }
        else
        {
            Task *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newTask;
        }

        cout     << "\nTask added successfully!" << endl;
    }

    // Function to list tasks
    void listTasks()
    {
        Task *temp = head;
        while (temp != nullptr)
        {
            cout     << "Task: " << temp->description << " (Status: " << (temp->status ? "Completed" : "Not Completed") << ")" << endl;
            temp = temp->next;
        }
    }

    // Function to change the status of a task
    void changeTaskStatus()
    {
        string description;
        cout     << "Enter task description: ";
        cin.ignore();
        getline(cin, description);

        Task *temp = head;
        while (temp != nullptr && temp->description != description)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout     << "Task not found." << endl;
            return;
        }

        temp->status = !temp->status; // Toggle task status

        cout     << "\nTask status updated successfully!" << endl;
    }

    // Function to generate reports
    void generateReports()
    {
        int completedTasks = 0;
        int notCompletedTasks = 0;

        Task *temp = head;
        while (temp != nullptr)
        {
            if (temp->status)
            {
                completedTasks++;
            }
            else
            {
                notCompletedTasks++;
            }
            temp = temp->next;
        }

        cout     << "\n===== Reports =====" << endl;
        cout     << "Completed Tasks: " << completedTasks << endl;
        cout     << "Not Completed Tasks: " << notCompletedTasks << endl;
    }

    void saveToFile(const string &filename)
    {
        ofstream outFile(filename);

        if (!outFile)
        {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        Task *temp = head;
        while (temp != nullptr)
        {
            outFile << temp->description << "," << temp->startDate << "," << temp->endDate << "," << temp->status << endl;
            temp = temp->next;
        }

        outFile.close();

        cout     << "\nTasks saved to file successfully!" << endl;
    }

    // Function to load tasks from a file
    void loadFromFile(const string &filename)
    {
        ifstream inFile(filename);

        if (!inFile)
        {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        // Clear existing tasks
        while (head != nullptr)
        {
            Task *temp = head;
            head = head->next;
            delete temp;
        }

        // Read tasks from file
        string line;
        while (getline(inFile, line))
        {
            Task *newTask = new Task;
            stringstream ss(line);
            getline(ss, newTask->description, ',');
            getline(ss, newTask->startDate, ',');
            getline(ss, newTask->endDate, ',');
            ss >> newTask->status;

            newTask->next = nullptr;

            // Add task to the linked list
            if (head == nullptr)
            {
                head = newTask;
            }
            else
            {
                Task *temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newTask;
            }
        }

        inFile.close();

        cout     << "\nTasks loaded from file successfully!" << endl;
    }

    // Function to delete a task
    void deleteTask()
    {
        string description;
        cout     << "Enter task description to delete: ";
        cin.ignore();
        getline(cin, description);

        if (head == nullptr)
        {
            cout     << "Task list is empty." << endl;
            return;
        }

        Task *current = head;
        Task *previous = nullptr;

        // Search for the task to delete
        while (current != nullptr && current->description != description)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout     << "Task not found." << endl;
            return;
        }

        // Remove the task from the linked list
        if (previous == nullptr)
        {
            // Task to be deleted is the head
            head = current->next;
        }
        else
        {
            // Task to be deleted is not the head
            previous->next = current->next;
        }

        delete current; // Free the memory

        cout     << "\nTask deleted successfully!" << endl;
    }
};

int main()
{
    TodoList todoList;

    int choice;
    do
    {
        todoList.displayMenu();
        cout     << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            todoList.addTask();
            break;
        case 2:
            todoList.listTasks();
            break;
        case 3:
            todoList.changeTaskStatus();
            break;
        case 4:
            todoList.deleteTask();
            todoList.generateReports();
            break;
        case 5:
            todoList.generateReports();
            break;
        case 6:
            cout     << "Exiting program." << endl;
            break;
        default:
            cout      << "\nInvalid choice. Please enter a number between 1 and 7." << endl;
        }
    } while (choice != 6);

    return 0;
}