#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<locale>  // For case-insensitive comparison
using namespace std;

class student {
public:
    long t;
    string dob;
    string nam;
};

// Function to convert string to lowercase for case-insensitive comparison
string toLowerCase(const string &s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Display function
void display(student &s) {
    cout << "Name: " << s.nam << endl;
    cout << "Date of Birth: " << s.dob << endl;
    cout << "Telephone Number: " << s.t << endl;
}

// Search function by Name
bool searchByName(const student &s, const string &searchTerm) {
    return toLowerCase(s.nam) == toLowerCase(searchTerm);
}

// Search function by Date of Birth
bool searchByDOB(const student &s, const string &searchTerm) {
    return s.dob == searchTerm;
}

// Search function by Telephone Number
bool searchByPhoneNumber(const student &s, const long &searchTerm) {
    return s.t == searchTerm;
}

int main() {
    string search;
    vector<student> s;
    int n;

    student s1;
    cout << "Enter Number of Students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter Name: ";
        cin >> s1.nam;
        cout << "Enter Date of Birth (YYYY-MM-DD): ";
        cin >> s1.dob;
        cout << "Enter Telephone Number: ";
        cin >> s1.t;
        s.push_back(s1);
    }

    int ch;
    cout << "\nChoose an operation:\n";
    cout << "1. Sort by Name\n";
    cout << "2. Sort by Phone Number\n";
    cout << "3. Sort by DOB\n";
    cout << "4. Search by Name\n";
    cout << "5. Search by Date of Birth\n";
    cout << "6. Search by Phone Number\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
    cin >> ch;

    switch (ch) {
        case 1:
            sort(s.begin(), s.end(), [](student &a, student &b) {
                return a.nam < b.nam;  // Sort by name in ascending order
            });
            cout << "Sorted by Name:\n";
            for (int i = 0; i < s.size(); ++i) {
                display(s[i]);  // Display sorted data
            }
            break;
        case 2:
            sort(s.begin(), s.end(), [](student &a, student &b) {
                return a.t < b.t;  // Sort by telephone number in ascending order
            });
            cout << "Sorted by Telephone Number:\n";
            for (int i = 0; i < s.size(); ++i) {
                display(s[i]);  // Display sorted data
            }
            break;
        case 3:
            sort(s.begin(), s.end(), [](student &a, student &b) {
                return a.dob < b.dob;  // Sort by Date of Birth in ascending order
            });
            cout << "Sorted by Date of Birth:\n";
            for (int i = 0; i < s.size(); ++i) {
                display(s[i]);  // Display sorted data
            }
            break;
        case 4:
            cout << "Enter Name to Be Searched: ";
            cin >> search;

            // Search by Name
            vector<student>::iterator it_name = find_if(s.begin(), s.end(), [&](const student &stu) {
                return searchByName(stu, search);
            });

            if (it_name != s.end()) {
                cout << "Record Found:\n";
                display(*it_name);
            } else {
                cout << "Record Not Found!\n";
            }
            break;
        case 5:
            cout << "Enter Date of Birth (YYYY-MM-DD) to Be Searched: ";
            cin >> search;

            // Search by Date of Birth
            vector<student>::iterator it_dob = find_if(s.begin(), s.end(), [&](const student &stu) {
                return searchByDOB(stu, search);
            });

            if (it_dob != s.end()) {
                cout << "Record Found:\n";
                display(*it_dob);
            } else {
                cout << "Record Not Found!\n";
            }
            break;
        case 6:
            long phoneSearch;
            cout << "Enter Phone Number to Be Searched: ";
            cin >> phoneSearch;

            // Search by Phone Number
            vector<student>::iterator it_phone = find_if(s.begin(), s.end(), [&](const student &stu) {
                return searchByPhoneNumber(stu, phoneSearch);
            });

            if (it_phone != s.end()) {
                cout << "Record Found:\n";
                display(*it_phone);
            } else {
                cout << "Record Not Found!\n";
            }
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Exiting...\n";
            break;
    }

    return 0;
}
