#include <bits/stdc++.h>
using namespace std;

struct Student {
    string lastname;
    string firstname;
    double gpa;
};

int main() {
    int n;
    cin >> n;

    map<string, double> grade = {
        {"A+", 4.0},
        {"A", 3.75},
        {"B+", 3.5},
        {"B", 3.0},
        {"C+", 2.5},
        {"C", 2.0},
        {"D+", 1.5},
        {"D", 1.0},
        {"F", 0.0}
    };

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        int m;

        cin >> students[i].lastname
            >> students[i].firstname
            >> m;

        double sum = 0;
        int credits = 0;

        for (int j = 0; j < m; j++) {
            string mark;
            int c;

            cin >> mark >> c;

            sum += grade[mark] * c;
            credits += c;
        }

        students[i].gpa = sum / credits;
    }

    sort(students.begin(), students.end(), [](Student a, Student b) {
        if (a.gpa != b.gpa)
            return a.gpa < b.gpa;

        if (a.lastname != b.lastname)
            return a.lastname < b.lastname;

        return a.firstname < b.firstname;
    });

    cout << fixed << setprecision(3);

    for (Student s : students) {
        cout << s.lastname << ' '
             << s.firstname << ' '
             << s.gpa << '\n';
    }
}