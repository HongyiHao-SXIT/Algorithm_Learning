#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    friend void Input(Student stu[]);
    friend void Statistic(Student stu[]);
    friend void Lookup(Student stu[]);
    friend void Modify(Student stu[]);
    friend void Delete(Student stu[]);
    friend void Output(Student stu[]);
    friend void Insert(Student stu[]);
    friend void Sort(Student stu[]);
    friend void Write(Student stu[], int n);
    friend int Read(Student stu[]);

private:
    int id;
    char name[20];
    char className[20];
    float elec, cpp, english, math, media, sport, politics;
    float average;
    int rank;
} stu[100];

void Write(Student stu[], int n) {
    ofstream file("score.txt");
    if (!file) {
        cout << "Error: Cannot open score.txt for writing!" << endl;
        exit(1);
    }
    file << n << endl;
    for (int i = 0; i < n; i++) {
        file << stu[i].className << "\t" << stu[i].id << "\t" << stu[i].name << "\t"
             << stu[i].elec << "\t" << stu[i].cpp << "\t" << stu[i].media << "\t"
             << stu[i].english << "\t" << stu[i].math << "\t" << stu[i].sport << "\t"
             << stu[i].politics << "\t" << stu[i].average << endl;
    }
    file.close();
}

int Read(Student stu[]) {
    ifstream file("score.txt");
    if (!file) {
        cout << "Error: Cannot open score.txt for reading!" << endl;
        exit(1);
    }
    int count;
    file >> count;
    for (int i = 0; i < count; i++) {
        file >> stu[i].className >> stu[i].id >> stu[i].name
             >> stu[i].elec >> stu[i].cpp >> stu[i].media
             >> stu[i].english >> stu[i].math >> stu[i].sport
             >> stu[i].politics >> stu[i].average;
    }
    file.close();
    return count;
}

float InputScore(const string& subject) {
    float score;
    while (true) {
        cout << "Enter score for " << subject << " (1-100): ";
        cin >> score;
        if (score >= 1 && score <= 100) break;
        cout << "Invalid input. Please enter a score between 1 and 100." << endl;
    }
    return score;
}

void Input(Student stu[]) {
    system("cls");
    int i = 0;
    char cont = 'y';
    cout << "\n======>> Enter Student Records <<======\n";
    while (tolower(cont) == 'y') {
        cout << "Enter Class Name: ";
        cin >> stu[i].className;

        while (true) {
            bool duplicate = false;
            cout << "Enter Student ID: ";
            cin >> stu[i].id;
            for (int j = 0; j < i; j++) {
                if (stu[i].id == stu[j].id) {
                    cout << "This ID already exists. Please enter a unique ID." << endl;
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) break;
        }

        cout << "Enter Student Name: ";
        cin >> stu[i].name;

        stu[i].elec = InputScore("Electronics");
        stu[i].cpp = InputScore("C++ Programming");
        stu[i].media = InputScore("Multimedia Technology");
        stu[i].english = InputScore("College English");
        stu[i].math = InputScore("Advanced Mathematics");
        stu[i].sport = InputScore("Physical Education");
        stu[i].politics = InputScore("Political Science");

        stu[i].average = (stu[i].elec + stu[i].cpp + stu[i].media +
                          stu[i].english + stu[i].math + stu[i].sport + stu[i].politics) / 7;

        cout << "Average Score: " << stu[i].average << endl;

        cout << "Continue entering? (y/n): ";
        cin >> cont;
        i++;
    }
    Write(stu, i);
}

void Statistic(Student stu[]) {
    system("cls");
    int n = Read(stu);
    cout << "\n======>> Student Statistics <<======\n";
    cout << "-------------------------------------------------\n";
    cout << "Class\tID\tName\tAverage Score\n";
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << stu[i].className << "\t" << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].average << endl;
    }
    cout << "-------------------------------------------------\n";
    system("pause");
}

void Lookup(Student stu[]) {
    system("cls");
    int n = Read(stu);
    int targetId;
    cout << "\n======>> Lookup Student Record <<======\n";
    cout << "Enter Student ID to search: ";
    cin >> targetId;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (stu[i].id == targetId) {
            found = true;
            cout << "--------------------------------------\n";
            cout << "Class: " << stu[i].className << endl;
            cout << "ID: " << stu[i].id << endl;
            cout << "Name: " << stu[i].name << endl;
            cout << "Electronics: " << stu[i].elec << endl;
            cout << "C++ Programming: " << stu[i].cpp << endl;
            cout << "Multimedia: " << stu[i].media << endl;
            cout << "College English: " << stu[i].english << endl;
            cout << "Advanced Math: " << stu[i].math << endl;
            cout << "Physical Education: " << stu[i].sport << endl;
            cout << "Political Science: " << stu[i].politics << endl;
            cout << "Average Score: " << stu[i].average << endl;
            cout << "--------------------------------------\n";
            break;
        }
    }

    if (!found) {
        cout << "Student record not found!" << endl;
    }
    system("pause");
}

void Sort(Student stu[]) {
    system("cls");
    int n = Read(stu);
    cout << "\n======>> Sorting by Average Score <<======\n";
    sort(stu, stu + n, [](Student a, Student b) {
        return a.average > b.average;
    });

    cout << "-------------------------------------------\n";
    cout << "Rank\tID\tName\tAverage Score\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].average << endl;
    }
    cout << "-------------------------------------------\n";
    Write(stu, n);
    system("pause");
}

void Output(Student stu[]) {
    system("cls");
    int n = Read(stu);
    cout << "\n======>> All Student Records <<======\n";
    cout << "-------------------------------------------------------------\n";
    cout << "Class\tID\tName\tElec\tC++\tMedia\tEng\tMath\tSport\tPolitics\tAvg\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << stu[i].className << "\t" << stu[i].id << "\t" << stu[i].name << "\t"
             << stu[i].elec << "\t" << stu[i].cpp << "\t" << stu[i].media << "\t"
             << stu[i].english << "\t" << stu[i].math << "\t" << stu[i].sport << "\t"
             << stu[i].politics << "\t" << stu[i].average << endl;
    }
    cout << "-------------------------------------------------------------\n";
    system("pause");
}

// Menu
int main() {
    int choice;
    do {
        system("cls");
        cout << "\n======>> Student Management System <<======\n";
        cout << "1. Input Student Records\n";
        cout << "2. View Statistics\n";
        cout << "3. Lookup Student\n";
        cout << "4. Sort Students\n";
        cout << "5. Display All Records\n";
        cout << "0. Exit\n";
        cout << "============================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: Input(stu); break;
            case 2: Statistic(stu); break;
            case 3: Lookup(stu); break;
            case 4: Sort(stu); break;
            case 5: Output(stu); break;
            case 0: cout << "Exiting the system. Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl; system("pause");
        }
    } while (choice != 0);

    return 0;
}
