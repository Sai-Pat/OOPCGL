#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class PersonalRecord {
public:
    string name;
    string dob;  // Date of Birth in YYYY-MM-DD format
    long phone;

    PersonalRecord(string n, string d, long p) : name(n), dob(d), phone(p) {}
};

// Display the personal record
void display(PersonalRecord record) {
    cout << "Name: " << record.name << endl;
    cout << "Date of Birth: " << record.dob << endl;
    cout << "Phone: " << record.phone << endl;
}

// Compare by name (ascending order)
bool compareByName(PersonalRecord a, PersonalRecord b) {
    return a.name < b.name;
}

// Compare by phone (ascending order)
bool compareByPhone(PersonalRecord a, PersonalRecord b) {
    return a.phone < b.phone;
}

// Compare by date of birth (ascending order)
bool compareByDOB(PersonalRecord a, PersonalRecord b) {
    return a.dob < b.dob;
}

// Search for a record by name
PersonalRecord* searchByName(vector<PersonalRecord>& records, string searchName) {
    for (int i = 0; i < records.size(); i++) {
        if (records[i].name == searchName) {
            return &records[i];
        }
    }
    return nullptr;
}

// Search for a record by phone
PersonalRecord* searchByPhone(vector<PersonalRecord>& records, long searchPhone) {
    for (int i = 0; i < records.size(); i++) {
        if (records[i].phone == searchPhone) {
            return &records[i];
        }
    }
    return nullptr;
}

// Search for a record by DOB
PersonalRecord* searchByDOB(vector<PersonalRecord>& records, string searchDOB) {
    for (int i = 0; i < records.size(); i++) {
        if (records[i].dob == searchDOB) {
            return &records[i];
        }
    }
    return nullptr;
}

int main() {
    vector<PersonalRecord> records;

    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter New Record\n";
        cout << "2. Sort by Name\n";
        cout << "3. Sort by Phone\n";
        cout << "4. Sort by DOB\n";
        cout << "5. Search by Name\n";
        cout << "6. Search by Phone\n";
        cout << "7. Search by DOB\n";
        cout << "8. Display All Records\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Enter New Record
                string name, dob;
                long phone;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Date of Birth (YYYY-MM-DD): ";
                cin >> dob;
                cout << "Enter Phone Number: ";
                cin >> phone;

                PersonalRecord newRecord(name, dob, phone);
                records.push_back(newRecord);
                break;
            }
            case 2: {
                // Sort by Name
                sort(records.begin(), records.end(), compareByName);
                cout << "\nSorted by Name:\n";
                for (int i = 0; i < records.size(); ++i) {
                    display(records[i]);
                }
                break;
            }
            case 3: {
                // Sort by Phone
                sort(records.begin(), records.end(), compareByPhone);
                cout << "\nSorted by Phone:\n";
                for (int i = 0; i < records.size(); ++i) {
                    display(records[i]);
                }
                break;
            }
            case 4: {
                // Sort by DOB
                sort(records.begin(), records.end(), compareByDOB);
                cout << "\nSorted by Date of Birth:\n";
                for (int i = 0; i < records.size(); ++i) {
                    display(records[i]);
                }
                break;
            }
            case 5: {
                // Search by Name
                string searchName;
                cout << "Enter Name to search: ";
                cin >> searchName;
                PersonalRecord* foundRecord = searchByName(records, searchName);
                if (foundRecord) {
                    cout << "\nRecord found:\n";
                    display(*foundRecord);
                } else {
                    cout << "\nRecord not found.\n";
                }
                break;
            }
            case 6: {
                // Search by Phone
                long searchPhone;
                cout << "Enter Phone number to search: ";
                cin >> searchPhone;
                PersonalRecord* foundRecord = searchByPhone(records, searchPhone);
                if (foundRecord) {
                    cout << "\nRecord found:\n";
                    display(*foundRecord);
                } else {
                    cout << "\nRecord not found.\n";
                }
                break;
            }
            case 7: {
                // Search by DOB
                string searchDOB;
                cout << "Enter Date of Birth (YYYY-MM-DD) to search: ";
                cin >> searchDOB;
                PersonalRecord* foundRecord = searchByDOB(records, searchDOB);
                if (foundRecord) {
                    cout << "\nRecord found:\n";
                    display(*foundRecord);
                } else {
                    cout << "\nRecord not found.\n";
                }
                break;
            }
            case 8: {
                // Display All Records
                cout << "\nAll Records:\n";
                for (int i = 0; i < records.size(); ++i) {
                    display(records[i]);
                }
                break;
            }
            case 9:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }

    } while (choice != 9);

    return 0;
}
