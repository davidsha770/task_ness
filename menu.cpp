#include "menu.hpp"
#include <iostream>
#include <limits>
#include "task.hpp"

void Menu() 
{
    Tasks tasks;

        int choice;
        do {
            std::cout << "\nTask Management Menu:\n";
            std::cout << "1. Add Task\n";
            std::cout << "2. Mark Task as In Progress\n";
            std::cout << "3. Mark Task as Completed\n";
            std::cout << "4. Print Tasks\n";
            std::cout << "5. Remove Task\n";
            std::cout << "6. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

                        switch (choice) {
                case 1: {
                    addTask(tasks);
                    break;
                }
                case 2: {
                    markAsProgress(tasks);
                    break;
                }
                case 3: {
                    markAsCompleted(tasks);
                    break;
                }
                case 4:
                    tasks.printTasks();
                    break;
                case 5: {
                    removeTask(tasks);
                    break;
                }
                case 6:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 6);
}

void addTask(Tasks & tasks)
{
    std::string taskDescription;
    size_t year, month, day;
    std::cout << "Enter task description: ";
    std::cin.ignore();
    std::getline(std::cin, taskDescription);
    std::cout << "Enter due date (YYYY MM DD): ";
    while (!(std::cin >> year >> month >> day) || std::cin.peek() != '\n'
    || month < 1 || month > 12 || day < 1 || day > 31) {
        std::cout << "Invalid input. Please enter a valid date (YYYY MM DD): ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Clear the input buffer in case of additional characters
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    tasks.addTask(Task(taskDescription, Date(year, month, day)));
}

void markAsProgress(Tasks & tasks)
{
    size_t taskIndex;
    std::cout << "Enter task number to mark as in progress: ";
    std::cin >> taskIndex;
    tasks.inProgress(taskIndex - 1); // Adjusting for 1-based indexing
}

void markAsCompleted(Tasks & tasks)
{
    size_t taskIndex;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> taskIndex;
    tasks.completed(taskIndex - 1); // Adjusting for 1-based indexing
}

void removeTask(Tasks & tasks)
{
    size_t taskIndex;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskIndex;
    tasks.removeTask(taskIndex - 1); // Adjusting for 1-based indexing
}