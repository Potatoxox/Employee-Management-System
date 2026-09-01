# Role-Based Employee Management System

**C++ Console Application**

## Project Overview

This project is a simple Employee Management System made in C++ using Object-Oriented Programming. It works like a small office system where employees have different roles: HR, Manager, and Regular Employee. Each role has different permissions:

- **HR** can add, update, and delete employees.
- **Manager** can assign tasks and manage leave requests.
- **Employees** can view their profile, submit tasks, and apply for leave.

The system helps manage employees and their work in an organized way using OOP concepts.

## Objectives

- Use OOP concepts in a real program.
- Create a role-based system (HR, Manager, Employee).
- Manage employee records.
- Assign and track tasks.
- Handle leave requests.
- Understand how classes and objects work in real systems.

## Problem Statement

In real companies, employee records and tasks are often managed manually, which can cause mistakes and confusion. This project solves that problem by making a simple digital system where everything is managed through a program in a structured way.

## Functional Requirements

The system can:

- Add new employees.
- Update employee details.
- Delete employee records.
- Show an employee list (directory).
- Assign tasks to employees.
- Submit task completion.
- Request leave.
- Approve or reject leave.
- Show salary details.

## OOP Concepts Used

### 1. Encapsulation

All employee data is kept inside the `Employee` class and accessed using functions such as getters and setters.

### 2. Classes and Objects

The whole system is built using one main class, `Employee`, and multiple objects are stored in an array called `database`.

### 3. Abstraction

Users only see the menus (HR, Manager, and Employee); they do not see the internal working of the system.

### 4. Data Hiding

Important data such as salary, task status, and leave status is private inside the class.

### 5. Constructor

A default constructor sets all values to safe default values when an object is created.

### 6. Role-Based Access

Access depends on the role stored for each employee (HR, Manager, or Employee).

## System Design

The system is built around one main class:

```text
Employee
├── Personal Info (id, name, age, gender)
├── Job Info (department, designation, role, salary)
├── Task System (task, deadline, status)
└── Leave System (days, reason, status)
```

The system works using three portals:

- **HR Portal** — Manage employees.
- **Manager Portal** — Assign tasks and handle leave.
- **Employee Portal** — View profile, submit work, and apply for leave.

## Class Description

### `Employee`

**Purpose:** Stores all employee data and handles the task and leave system.

**Attributes:**

- `id`
- `name`
- `age`
- `gender`
- `department`
- `designation`
- `role`
- `salary`
- Task details
- Leave details

**Functions:**

- `setData()` — Set employee information.
- `setTask()` — Assign a task.
- `submitTask()` — Submit completed work.
- `requestLeave()` — Request leave.
- `processLeave()` — Approve or reject leave.
- `displayFullProfile()` — Show full employee information.
- `displayPublicRow()` — Show a short directory view.

## Program Flow

1. The program starts and shows the main menu.
2. The user selects the HR, Manager, or Employee portal.
3. The user enters an ID for authentication.
4. The system checks the role.
5. The appropriate menu opens.
6. The user performs actions such as adding employees, assigning tasks, or managing leave.
7. Data updates in system memory.
8. The user logs out or exits.

## Screenshots

The source document includes screenshots for the following screens:

- Main Menu Screen
- HR Panel
- Manager Panel
- Employee Panel
- Task Assignment Screen
- Leave Request
- Employee Directory

## Future Improvements

- Add a database instead of arrays.
- Add a login password system.
- Create a GUI version.
- Improve UI design.
- Add a better reporting system.

## Conclusion

This project helped in understanding how Object-Oriented Programming is used in real systems. It shows how employees can be managed using classes, how roles control access, and how tasks and leave can be handled in a structured way.

Overall, it was good practice for understanding real-world system design in C++.

## Project Information

- **Submitted to:** Miss Kishmala Tariq
- **Subject:** Object Oriented Programming
- **Date:** 4 June 2026
- **Submitted by:** Ibrahim Haroon
- **Department:** Department of Software Engineering
- **University:** University of Lahore
