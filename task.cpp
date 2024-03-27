#include "task.hpp"
#include <iostream>

Date::Date(size_t year, size_t month, size_t day)
: m_year{year}
, m_month{month}
, m_day{day}
{
}

void Date::print() const
{
    std::cout<<"the date of execution is: "<<m_year<<'/'<<m_month<<'/'<<m_day<<'\n';
}

Task::Task(std::string task, Date const& date)
: m_status{not_started}
, m_task{task}
, m_date{date}
{
}

void Task::print() const
{
    std::cout<<"the task is: "<<m_task<<"\nthe status is: ";
    switch(m_status) {
    case(0):
        std::cout<<"not started\n";
        break;
    case(1):
        std::cout<<"in progress\n";
        break;
    default:
        std::cout<<"completed\n";
    }
    m_date.print();
}

void Task::inProgress()
{
    m_status = in_progress;
}

void Task::Completed()
{
    m_status = completed;
}

void Tasks::addTask(Task const& task)
{
    m_listTasks.push_back(task);
}

void Tasks::completed(size_t number)
{
    if (number < m_listTasks.size())
    {
        m_listTasks[number].Completed();
        std::cout<<"Task marked as completed.\n";
    } else {
        std::cout<<"Invalid task number. Please provide a valid task number.\n";
    }
}

void Tasks::inProgress(size_t number)
{
    if (number < m_listTasks.size())
    {
        m_listTasks[number].inProgress();
        std::cout<<"Task marked as in progress.\n";
    } else {
        std::cout<<"Invalid task number. Please provide a valid task number.\n";
    }
}

void Tasks::printTasks() const
{
    auto it = m_listTasks.begin();
    int count = 1;
    if (m_listTasks.size() == 0) {
        std::cout<<"No tasks to display.\n";
    }
    while (it != m_listTasks.end()) {
        std::cout<<'\n'<<count<<". ";
        it->print();
        it++, count++;
    }
}

void Tasks::removeTask(size_t number)
{
    if (number < m_listTasks.size()) {
        m_listTasks.erase(m_listTasks.begin()+number);
        std::cout<<"Task removed.\n";
    } else {
        std::cout<<"Invalid task number. Please provide a valid task number.\n";
    }
}