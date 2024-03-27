#pragma once

#include "task.hpp"

void Menu();

void addTask(Tasks & tasks);

void markAsProgress(Tasks & tasks);

void markAsCompleted(Tasks & tasks);

void removeTask(Tasks & tasks);