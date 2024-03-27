#pragma once

#include <string>
#include <vector>

enum status {not_started, in_progress, completed};

class Date
{
public:
    Date(size_t year, size_t month, size_t day);
    ~Date() = default;
    void print()const;

private:
    size_t m_year;
    size_t m_month;
    size_t m_day;
};

class Task
{
public:
    Task(std::string task, Date const& date);
    ~Task() = default;
    void print()const;
    void inProgress();
    void Completed();

private:
    status m_status;
    std::string m_task;
    Date m_date;
};

class Tasks
{
public:
    Tasks() = default;
    ~Tasks() = default;
    void addTask(Task const& task);
    void printTasks() const;
    void inProgress(size_t number);
    void completed(size_t number);
    void removeTask(size_t number);

private:
    std::vector<Task> m_listTasks;
};
