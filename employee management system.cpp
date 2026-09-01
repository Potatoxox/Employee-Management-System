#include <iostream>
#include <string>
#include <iomanip> // Added for clean directory column alignment
using namespace std;

// ================= ANSI COLORS & CONTROLS =================
#define CYAN   "\033[36m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define RED    "\033[31m"
#define RESET  "\033[0m"

void clearScreen() {
    cout << "\033[2J\033[H";
    cout.flush();
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.get(); 
}

// ================= EMPLOYEE CLASS =================
class Employee {
private:
    int id;
    string name;
    int age;
    string gender;
    string department;
    string designation; 
    string role;        
    double baseSalary;

    // Task Module
    string taskTitle;
    string taskDeadline;
    string taskStatus; 
    string submissionNote;

    // Leave Module
    int leaveDays;
    string leaveReason;
    string leaveStatus;     
    string managerLeaveNote; 

public:
    Employee() {
        id = 0; name = ""; age = 0; gender = ""; department = ""; designation = ""; role = ""; baseSalary = 0;
        taskTitle = "No task assigned"; taskDeadline = "None"; taskStatus = "None"; submissionNote = "";
        leaveDays = 0; leaveReason = ""; leaveStatus = "None"; managerLeaveNote = "";
    }

    void setData(int i, string n, int a, string g, string d, string des, string r, double s) {
        id = i; name = n; age = a; gender = g; department = d; designation = des; role = r; baseSalary = s;
    }

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setDepartment(string d) { department = d; }
    void setDesignation(string des) { designation = des; }
    void setSalary(double s) { baseSalary = s; }

    void setTask(string title, string deadline) {
        taskTitle = title;
        taskDeadline = deadline;
        taskStatus = "Pending";
    }
    void submitTask(string note) {
        submissionNote = note;
        taskStatus = "Submitted";
    }

    void requestLeave(int days, string reason) {
        leaveDays = days;
        leaveReason = reason;
        leaveStatus = "Pending Approval";
        managerLeaveNote = ""; 
    }
    void processLeave(string statusDecision, string managerNote) {
        leaveStatus = statusDecision;
        managerLeaveNote = managerNote;
    }

    int getId() { return id; }
    string getName() { return name; }
    string getRole() { return role; }
    double getSalary() { return baseSalary; }
    string getTaskStatus() { return taskStatus; }
    string getLeaveStatus() { return leaveStatus; }
    int getLeaveDays() { return leaveDays; }
    string getLeaveReason() { return leaveReason; }

    void displayFullProfile() {
        cout << "\n======================================================\n";
        cout << "  ID:          " << id << "\n";
        cout << "  Name:        " << name << "\n";
        cout << "  Age:         " << age << "  |  Gender: " << gender << "\n";
        cout << "  Department:  " << department << "  |  Position: " << designation << "\n";
        cout << "  System Permission Level: " << role << "\n";
        cout << "  Base Salary: " << GREEN << "$" << baseSalary << RESET << "\n";
        cout << "------------------------------------------------------\n";
        cout << "  ASSIGNED WORK TASK: " << taskTitle << "\n";
        cout << "  DEADLINE:           " << taskDeadline << "\n";
        cout << "  TASK STATUS:        ";
        if (taskStatus == "Pending") cout << YELLOW << taskStatus << RESET << "\n";
        else if (taskStatus == "Submitted") cout << GREEN << taskStatus << RESET << "\n";
        else cout << taskStatus << "\n";
        
        if (taskStatus == "Submitted") {
            cout << "  Staff Completion Note: " << submissionNote << "\n";
        }
        cout << "------------------------------------------------------\n";
        cout << "  LEAVE REQUEST STATUS: ";
        if (leaveStatus == "Pending Approval") cout << YELLOW << leaveStatus << RESET << " (" << leaveDays << " Days)\n";
        else if (leaveStatus == "Approved") cout << GREEN << leaveStatus << RESET << " (" << leaveDays << " Days)\n";
        else if (leaveStatus == "Rejected") cout << RED << leaveStatus << RESET << " (" << leaveDays << " Days)\n";
        else cout << "No Active Requests\n";

        if (leaveStatus == "Approved" || leaveStatus == "Rejected") {
            cout << "  Manager's Return Decision Note: " << CYAN << managerLeaveNote << RESET << "\n";
        }
        cout << "======================================================\n";
    }

    void displayPublicRow() {
        // Clean column formatting using left alignment and setw
        cout << "  ID: [" << setw(3) << id << "]  | " 
             << left << setw(18) << name << " | "
             << "Dept: " << setw(5) << department << " | "
             << "Position: " << designation << "\n";
    }
};

// ================= GLOBAL DATABASE =================
Employee database[100];
int totalEmployees = 0;

int findEmployee(int id) {
    for (int i = 0; i < totalEmployees; i++) {
        if (database[i].getId() == id) return i;
    }
    return -1;
}

// ================= RELEVANT COMPACT ASCII BANNERS =================
void printMainGatewayBanner() {
    cout << CYAN;
    cout << "  __________________________________________________\n";
    cout << " |  ___ __  __ ___   ___  ___  ___ _____  _   _     |\n";
    cout << " | | __|  \\/  | __| | _ \\/ _ \\| _ \\_   _|/_\\ | |    |\n";
    cout << " | | _|| |\\/| \\__ \\ |  _/ (_) |   / | | / _ \\| |__  |\n";
    cout << " | |___|_|  |_|___/ |_|  \\___/|_|_\\ |_|/_/ \\_\\____| |\n";
    cout << " |         == EMPLOYEE MANAGEMENT SYSTEM ==         |\n";
    cout << " |__________________________________________________|\n" << RESET << "\n";
}

void printHrBanner() {
    cout << RED;
    cout << "  [!] --- HR CONTROL CENTER ---\n";
    cout << "   _  _ ___   __  __ ___ _  _ _  _ \n";
    cout << "  | || | _ \\ |  \\/  | __| \\| | | | |\n";
    cout << "  | __ |   / | |\\/| | _|| .` | |_| |\n";
    cout << "  |_||_|_|_\\ |_|  |_|___|_|\\_|\\___/ \n" << RESET << "\n";
}

void printManagerBanner() {
    cout << YELLOW;
    cout << "  [*] --- MANAGEMENT TRACKING BOARD ---\n";
    cout << "   __  __   _   _  _  _   ___ ___ ___ \n";
    cout << "  |  \\/  | /_\\ | \\| |/_\\ / __| __| _ \\\n";
    cout << "  | |\\/| |/ _ \\| .` / _ \\ (_ | _||   /\n";
    cout << "  |_|  |_/_/ \\_\\_|\\_/_/ \\_\\___|___|_|_\\\n" << RESET << "\n";
}

void printEmployeeBanner() {
    cout << GREEN;
    cout << "  [@] --- STAFF WORKSTATION HUB ---\n";
    cout << "   ___ __  __ ___ _    _____   _____ ___ \n";
    cout << "  | __|  \\/  | _ \\ |  / _ \\ \\ / / __| __|\n";
    cout << "  | _|| |\\/| |  _/ |__| (_) \\ V /| _|| _| \n";
    cout << "  |___|_|  |_|_|  |____\\___/ |_| |___|___|\n" << RESET << "\n";
}

// ================= UTILITIES =================
void displayActiveDirectory() {
    cout << "\n------------------- SYSTEM ROSTER DIRECTORY -------------------\n";
    for (int i = 0; i < totalEmployees; i++) { 
        database[i].displayPublicRow(); 
    }
    cout << "----------------------------------------------------------------\n\n";
}

// ================= HR FUNCTIONS =================
void addEmployee() {
    int id, age, roleChoice; string name, gender, dept, des, role; double salary;
    cout << "\n--- REGISTER NEW EMPLOYEE PROFILE ---\n";
    cout << "Enter Employee ID Code: "; cin >> id;
    if(findEmployee(id) != -1) {
        cout << RED << "Error: This ID is already registered!\n" << RESET; 
        cin.ignore(); return;
    }
    cout << "Enter Full Name: "; cin.ignore(); getline(cin, name);
    cout << "Enter Age: "; cin >> age;
    cout << "Enter Gender: "; cin >> gender;
    cout << "Enter Department: "; cin >> dept;
    cout << "Enter Position Designation (e.g., Junior Dev): "; cin.ignore(); getline(cin, des);
    
    cout << "\nSelect System Permission Clearance Level:\n";
    cout << " 1. HR Administrative Access\n";
    cout << " 2. Manager Access\n";
    cout << " 3. Regular Staff Employee Access\n";
    cout << " Choice: "; cin >> roleChoice;
    cin.ignore();

    if (roleChoice == 1) role = "HR";
    else if (roleChoice == 2) role = "Manager";
    else role = "Employee";

    cout << "Enter Base Allocation Salary: "; cin >> salary;
    cin.ignore(); 

    database[totalEmployees].setData(id, name, age, gender, dept, des, role, salary);
    totalEmployees++;
    cout << GREEN << "\nSuccess: " << name << " added to system core database registry!\n" << RESET;
}

void updateEmployee() {
    displayActiveDirectory();
    int id;
    cout << "Enter Target Employee ID to edit from the list above: "; cin >> id;
    cin.ignore();

    int idx = findEmployee(id);
    if (idx == -1) {
        cout << RED << "Error: Employee ID selection does not exist!\n" << RESET;
        return;
    }

    int subChoice;
    do {
        clearScreen(); // Keeps the edit panel beautifully clean
        printHrBanner();
        cout << "Modifying profile data fields for: " << CYAN << database[idx].getName() << RESET << " (ID: " << id << ")\n\n";
        cout << "1. Edit Full Name\n";
        cout << "2. Edit Age\n";
        cout << "3. Edit Department\n";
        cout << "4. Edit Corporate Position Designation\n";
        cout << "5. Edit Base Salary\n";
        cout << "0. Save & Finish Editing\n";
        cout << "Select field to update: "; cin >> subChoice;
        cin.ignore();

        switch(subChoice) {
            case 1: {
                string newName; cout << "Enter New Name: "; getline(cin, newName);
                database[idx].setName(newName);
                cout << GREEN << "Name updated!\n" << RESET; pauseScreen(); break;
            }
            case 2: {
                int newAge; cout << "Enter New Age: "; cin >> newAge; cin.ignore();
                database[idx].setAge(newAge);
                cout << GREEN << "Age updated!\n" << RESET; pauseScreen(); break;
            }
            case 3: {
                string newDept; cout << "Enter New Department: "; cin >> newDept; cin.ignore();
                database[idx].setDepartment(newDept);
                cout << GREEN << "Department updated!\n" << RESET; pauseScreen(); break;
            }
            case 4: {
                string newDes; cout << "Enter New Position Designation: "; getline(cin, newDes);
                database[idx].setDesignation(newDes);
                cout << GREEN << "Position updated!\n" << RESET; pauseScreen(); break;
            }
            case 5: {
                double newSalary; cout << "Enter New Base Salary: "; cin >> newSalary; cin.ignore();
                database[idx].setSalary(newSalary);
                cout << GREEN << "Salary updated!\n" << RESET; pauseScreen(); break;
            }
        }
    } while (subChoice != 0);
    
    cout << GREEN << "\nChanges safely compiled back into memory registry!\n" << RESET;
}

void deleteEmployee() {
    displayActiveDirectory();
    int id; 
    cout << "Enter ID to permanently purge from records: "; cin >> id;
    cin.ignore();
    int index = findEmployee(id);
    if (index == -1) { cout << RED << "Error: ID not found!\n" << RESET; return; }
    for (int i = index; i < totalEmployees - 1; i++) { database[i] = database[i + 1]; }
    totalEmployees--;
    cout << RED << "Success: Record deleted.\n" << RESET;
}

void globalPayroll() {
    double total = 0;
    cout << "\n--- GLOBAL RUNTIME PAYROLL RATE ---\n";
    for (int i = 0; i < totalEmployees; i++) {
        total += database[i].getSalary();
        cout << "  Staff: " << left << setw(15) << database[i].getName() << " \t| Pay Distribution: $" << database[i].getSalary() << "\n";
    }
    cout << YELLOW << "-------------------------------------------------------------\n";
    cout << "Total Operational Budget Outflow: $" << total << "\n" << RESET;
}

// ================= MANAGER FUNCTIONS =================
void assignTask() {
    displayActiveDirectory();
    int id; string title, deadline;
    cout << "Enter Target Employee ID to assign work: "; cin >> id;
    int i = findEmployee(id);
    if (i == -1) { cout << RED << "Error: Employee not found!\n" << RESET; cin.ignore(); return; }
    cout << "Enter Task Work Description: "; cin.ignore(); getline(cin, title);
    cout << "Enter Deadline Day/Date: "; getline(cin, deadline);
    database[i].setTask(title, deadline);
    cout << GREEN << "\nSuccess: Task pushed to Employee workstation!\n" << RESET;
}

void reviewTasks() {
    cout << "\n--- SUBMITTED WORK LOGS FOR REVIEW ---\n";
    int count = 0;
    for (int i = 0; i < totalEmployees; i++) {
        if (database[i].getTaskStatus() == "Submitted") {
            cout << "  ID: " << database[i].getId() << " | Name: " << database[i].getName() << " -> [Submitted Line item]\n";
            count++;
        }
    }
    if (count == 0) cout << "No employees have pending task submissions right now.\n";
}

void reviewLeaveRequests() {
    cout << "\n--- PENDING LEAVE APPLICATIONS DIRECTORY ---\n";
    int count = 0;
    for (int i = 0; i < totalEmployees; i++) {
        if (database[i].getLeaveStatus() == "Pending Approval") {
            cout << "  ID: [" << database[i].getId() << "] | Name: " << database[i].getName() 
                 << " | Requested: " << database[i].getLeaveDays() << " Days\n";
            cout << "  Stated Reason: \"" << database[i].getLeaveReason() << "\"\n\n";
            count++;
        }
    }

    if (count == 0) {
        cout << "No active pending leave requests are awaiting processing.\n";
        return;
    }

    int targetId;
    cout << "Enter Employee ID to handle decision (or 0 to skip): "; cin >> targetId;
    cin.ignore();
    if (targetId == 0) return;

    int idx = findEmployee(targetId);
    if (idx == -1 || database[idx].getLeaveStatus() != "Pending Approval") {
        cout << RED << "Invalid selection processing entry.\n" << RESET;
        return;
    }

    int decision;
    string managerNote, finalStatus;
    cout << "Select Action Decision: (1 = Approve, 2 = Reject): "; cin >> decision;
    cin.ignore();

    cout << "Enter Decision Justification Note: ";
    getline(cin, managerNote);

    if (decision == 1) {
        finalStatus = "Approved";
        cout << GREEN << "\nLeave Request status set to Approved.\n" << RESET;
    } else {
        finalStatus = "Rejected";
        cout << RED << "\nLeave Request status set to Rejected.\n" << RESET;
    }

    database[idx].processLeave(finalStatus, managerNote);
}

// ================= THOUGHTFUL PORTAL MENU LOOPS =================
void hrMenu() {
    int choice;
    do {
        clearScreen(); // Clear screen only right before drawing the menu layout
        printHrBanner();
        cout << "1. Add New Employee Profile\n";
        cout << "2. Edit/Update Employee Data Fields\n"; 
        cout << "3. Remove Employee Profile from Core\n";
        cout << "4. Verify Active Budget Payroll Run\n";
        cout << "0. Log Out to Master Gateway Gate\n";
        cout << "Select Administrative Operation: "; cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: addEmployee(); pauseScreen(); break;
            case 2: updateEmployee(); pauseScreen(); break; 
            case 3: deleteEmployee(); pauseScreen(); break;
            case 4: globalPayroll(); pauseScreen(); break;
            case 0: break; 
            default: cout << RED << "Invalid Selection!\n" << RESET; pauseScreen(); break;
        }
    } while (choice != 0);
}

void managerMenu() {
    int choice;
    do {
        clearScreen(); // Clear screen only right before drawing the menu layout
        printManagerBanner();
        cout << "1. Assign Functional Project Task to Staff\n";
        cout << "2. View Pending Tasks Submitted by Workers\n";
        cout << "3. Process Pending Leave Requests Panels\n"; 
        cout << "4. View Global Office Directory List\n";
        cout << "0. Log Out to Master Gateway Gate\n";
        cout << "Select Management Operation: "; cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: assignTask(); pauseScreen(); break;
            case 2: reviewTasks(); pauseScreen(); break;
            case 3: reviewLeaveRequests(); pauseScreen(); break;
            case 4: displayActiveDirectory(); pauseScreen(); break;
            case 0: break; 
            default: cout << RED << "Invalid Choice!\n" << RESET; pauseScreen(); break;
        }
    } while (choice != 0);
}

void employeeMenu(int idx) {
    int choice;
    do {
        clearScreen(); // Clear screen only right before drawing the menu layout
        printEmployeeBanner();
        cout << "Welcome back to your workspace station, " << CYAN << database[idx].getName() << RESET << "!\n\n";
        cout << "1. View My Personal Profile, Tasks & Leaves Info\n";
        cout << "2. Submit Work Progress Notes to Team Manager\n";
        cout << "3. Submit a New Leave Application Request\n"; 
        cout << "4. View Team Public Office Directory\n";
        cout << "0. Log Out to Master Gateway Gate\n";
        cout << "Select Operational Node: "; cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                database[idx].displayFullProfile();
                pauseScreen();
                break;
            case 2:
                if (database[idx].getTaskStatus() == "None") {
                    cout << YELLOW << "\nYou do not have any active tasks assigned!\n" << RESET;
                } else {
                    string note;
                    cout << "\nType execution completion summary for your Manager: ";
                    getline(cin, note);
                    database[idx].submitTask(note);
                    cout << GREEN << "Success: Task marked complete and logs updated!\n" << RESET;
                }
                pauseScreen();
                break;
            case 3:
                if (database[idx].getLeaveStatus() == "Pending Approval") {
                    cout << YELLOW << "\nYou already have a pending leave request waiting in line!\n" << RESET;
                } else {
                    int days; string reason;
                    cout << "\nEnter how many total days off you need: "; cin >> days;
                    cin.ignore();
                    cout << "Enter reason justification summary: "; getline(cin, reason);
                    database[idx].requestLeave(days, reason);
                    cout << GREEN << "Success: Leave application uploaded up to management desk!\n" << RESET;
                }
                pauseScreen();
                break;
            case 4:
                displayActiveDirectory();
                pauseScreen();
                break;
            case 0:
                break;
            default:
                cout << RED << "Invalid Action selection choice!\n" << RESET;
                pauseScreen();
                break;
        }
    } while (choice != 0);
}

// ================= MAIN GATEWAY INTERFACE =================
int main() {
    database[0].setData(101, "Alice Smith", 30, "Female", "HR", "Director", "HR", 5000);
    database[1].setData(202, "Bob Jones", 35, "Male", "IT", "Team Lead", "Manager", 6000);
    database[2].setData(303, "Charlie Brown", 28, "Male", "IT", "Junior Dev", "Employee", 3000);
    totalEmployees = 3;

    int gateSelection;

    while (true) {
        clearScreen();
        printMainGatewayBanner();
        cout << "Select Desktop Access Node Gateway:\n";
        cout << " 1. Human Resources Portal\n";
        cout << " 2. Management Level Portal\n";
        cout << " 3. Regular Staff Workstation Hub\n";
        cout << " 0. Completely Shut Down Application Core\n";
        cout << " Selection: "; cin >> gateSelection;
        cin.ignore(); 

        if (gateSelection == 0) {
            clearScreen();
            cout << RED << "System Core Engine successfully shut down. Goodbye!\n" << RESET;
            break;
        }
        if (gateSelection < 1 || gateSelection > 3) {
            cout << RED << "Invalid Selection! Please pass a legal gateway point tier.\n" << RESET;
            pauseScreen(); continue;
        }

        int userId;
        cout << "Enter Unique Account ID Code: "; cin >> userId;
        cin.ignore(); 

        int idx = findEmployee(userId);

        if (idx == -1) {
            cout << RED << "Authentication Failed: Specified ID code does not exist.\n" << RESET;
            pauseScreen(); continue;
        }

        string systemRole = database[idx].getRole();

        if (gateSelection == 1 && systemRole == "HR") {
            hrMenu();
        } 
        else if (gateSelection == 2 && systemRole == "Manager") {
            managerMenu();
        } 
        else if (gateSelection == 3 && systemRole == "Employee") {
            employeeMenu(idx);
        } 
        else {
            cout << RED << "Access Denied: Clearance level on your account does not match this portal desk!\n" << RESET;
            pauseScreen();
        }
    }
    return 0;
}
