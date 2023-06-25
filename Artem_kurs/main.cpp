#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

struct Deposit {
    string type;
    string client;
    string start_date;
    string end_date;
    int term{};
    float interest_rate{};
};

int getPositiveNumberInput() {
    int number;
    while (true) {
        if (cin >> number && number > 0) {
            break;
        } else {
            cout << "Invalid input. Must be a positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return number;
}
class DepositNode {
public:
    DepositNode(Deposit* deposit, DepositNode* next = nullptr) {
        this->deposit = deposit;
        this->next = next;
    }
    Deposit* deposit;
    DepositNode* next;
};

class DepositStack {
public:
    DepositStack() {
        top = nullptr;
    }

    ~DepositStack() {
        DepositNode *temp;
        while (top != nullptr) {
            temp = top;
            top = top->next;
            delete temp->deposit;
            delete temp;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(Deposit *deposit) {
        DepositNode *newNode = new DepositNode(deposit, top);
        top = newNode;
    }

    Deposit *pop() {
        if (isEmpty()) {
            return nullptr;
        }
        Deposit *deposit = top->deposit;
        DepositNode *temp = top;
        top = top->next;
        delete temp;
        return deposit;
    }

    void printAllDeposits() const {
        int q = 1;
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            DepositNode *current = top;
            while (current != nullptr) {
                Deposit *deposit = current->deposit;
                cout << endl << q << "-deposit " << endl;
                cout << "Deposit type: " << deposit->type << endl;
                cout << "Client name: " << deposit->client << endl;
                cout << "Start date: " << deposit->start_date << endl;
                cout << "End date: " << deposit->end_date << endl;
                cout << "Term: " << deposit->term << endl;
                cout << "Interest rate: " << deposit->interest_rate << endl;
                current = current->next;
                q++;
            }
        }
    }

    bool updateDeposit() const {
        int position;
        cout << "Enter the position of the deposit you want to update: ";
        cin >> position;
        DepositNode *current = top;
        int currentPosition = 1;
        while (current != nullptr && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }
        if (current == nullptr) {
            cout << "Invalid position." << endl;
            return false;
        }
        Deposit *deposit = current->deposit;
        cout << "Enter new deposit type: ";
        cin >> deposit->type;
        cout << "Enter new client name: ";
        cin >> deposit->client;
        cout << "Enter new start date: ";
        cin >> deposit->start_date;
        cout << "Enter new end date: ";
        cin >> deposit->end_date;

        cout << "Enter new term: ";
        deposit->term = getPositiveNumberInput();

        cout << "Enter new interest rate: ";
        deposit->interest_rate = getPositiveNumberInput();
        return true;
    }

    bool removeDeposit() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot remove deposit." << endl;
            return false;
        }
        int position;
        cout << "Enter the position of the deposit you want to remove: ";
        cin >> position;

        if (position < 1 || position > countDeposits()) {
            cout << "Invalid position." << endl;
            return false;
        }
        int confirmation;
        cout << "Are you sure you want to delete the deposit?" << endl;
        cout << "Enter 1 for Yes or 0 for No: ";
        cin >> confirmation;

        if (confirmation != 1) {
            cout << "Deposit removal canceled." << endl;
            return false;
        }

        DepositNode *previous = nullptr;
        DepositNode *current = top;
        int currentPosition = 1;

        while (current != nullptr && currentPosition < position) {
            previous = current;
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            cout << "Invalid position." << endl;
            return false;
        }

        if (previous == nullptr) {
            top = current->next;
        } else {
            previous->next = current->next;
        }

        delete current->deposit;
        delete current;

        cout << "Deposit at position " << position << " has been removed." << endl;
        return true;
    }

    DepositNode *top;

    void printDepositByClient(const string &clientName) const {
        DepositNode *current = top;
        int a = 1;
        bool found = false;
        while (current != nullptr) {
            Deposit *deposit = current->deposit;
            if (deposit->client == clientName) {
                cout << endl << a << "-deposit " << endl;
                cout << "Deposit type: " << deposit->type << endl;
                cout << "Client name: " << deposit->client << endl;
                cout << "Start date: " << deposit->start_date << endl;
                cout << "End date: " << deposit->end_date << endl;
                cout << "Term: " << deposit->term << endl;
                cout << "Interest rate: " << deposit->interest_rate << endl;
                found = true;
                a++;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No deposit found for client: " << clientName << endl;
        }
    }

    void printDepositsByType(const string &depositType) const {
        int z = 1;
        DepositNode *current = top;
        bool found = false;
        while (current != nullptr) {
            Deposit *deposit = current->deposit;
            if (deposit->type == depositType) {
                cout << endl << z << "-deposit " << endl;
                cout << "Deposit type: " << deposit->type << endl;
                cout << "Client name: " << deposit->client << endl;
                cout << "Start date: " << deposit->start_date << endl;
                cout << "End date: " << deposit->end_date << endl;
                cout << "Term: " << deposit->term << endl;
                cout << "Interest rate: " << deposit->interest_rate << endl;
                found = true;
                z++;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No deposits found for type: " << depositType << endl;
        }
    }

    int countDeposits() const {
        int count = 0;
        DepositNode *current = top;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    };
void sortinsertDepositByTerm(DepositStack &stack) {

    DepositNode *current = stack.top;
    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    DepositNode *current1;
    DepositNode *current2 = nullptr;
    bool flag;
    do {
        flag = false;
        current1 = stack.top;
        while (current1->next != current2) {
            if (current1->deposit->term < current1->next->deposit->term) {
                Deposit *temp = current1->deposit;
                current1->deposit = current1->next->deposit;
                current1->next->deposit = temp;
                flag = true;
            }
            current1 = current1->next;
        }
        current2 = current1;
    } while (flag);
    cout << "Deposit added successfully." << endl;
}

    void sortDepositsByInterestRate(DepositStack &stack) {
        DepositNode *current = stack.top;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        DepositNode *current1;
        DepositNode *current2 = nullptr;
        bool flag;
        do {
            flag = false;
            current1 = stack.top;
            while (current1->next != current2) {
                if (current1->deposit->interest_rate < current1->next->deposit->interest_rate) {
                    Deposit *temp = current1->deposit;
                    current1->deposit = current1->next->deposit;
                    current1->next->deposit = temp;
                    flag = true;
                }
                current1 = current1->next;
            }
            current2 = current1;
        } while (flag);
    }

void saveDepositsToFile(DepositStack& stack) {
    ofstream outputFile("deposits.txt");
    if (!outputFile) {
        cout << "Error: could not open file." << endl;
        outputFile.close();
        return;
    }
    DepositNode *current = stack.top;
    while (current != nullptr) {
        Deposit *deposit = current->deposit;
        outputFile << deposit->type << "," << deposit->client << "," << deposit->start_date << "," << deposit->end_date
                   << "," << deposit->term << "," << deposit->interest_rate << endl;
        current = current->next;
    }
    cout << "Data is successfully save to file." << endl;
    outputFile.close();
}
void loadDepositsFromFile(DepositStack& stack) {
    ifstream inputFile("deposits.txt");
    if (!inputFile) {
        cout << "Error: could not open file." << endl;
        inputFile.close();
        return;
    }
    string line;
    while (getline(inputFile, line)) {
        Deposit* deposit = new Deposit();
        stringstream ss(line);
        getline(ss, deposit->type, ',');
        getline(ss, deposit->client, ',');
        getline(ss, deposit->start_date, ',');
        getline(ss, deposit->end_date, ',');
        string termString, interestRateString;
        getline(ss, termString, ',');
        getline(ss, interestRateString, ',');
        deposit->term = stoi(termString);
        deposit->interest_rate = stof(interestRateString);
        stack.push(deposit);
    }
    cout << "Data uploaded successfully." << endl;
    inputFile.close();
}
int main() {
    DepositStack stack;

    loadDepositsFromFile(stack);

    while (true) {

        cout << endl << "===== Deposit Management System =====" << endl;
        cout << "1. Add a new deposit" << endl;
        cout << "2. Remove deposit" << endl;
        cout << "3. Update an existing deposit" << endl;
        cout << "4. Print all deposits" << endl;
        cout << "5. Save deposits to file" << endl;
        cout << "6. Sort the deposits" << endl;
        cout << "7. Find deposit by client name" << endl;
        cout << "8. Number of deposit" << endl;
        cout << "9. Find deposit by type of deposit" << endl;
        cout << "10.Sort deposit by term" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter your choice (1-5): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {

                Deposit* deposit = new Deposit();
                cout << "Enter deposit type: ";
                cin >> deposit->type;
                cout << "Enter client name: ";
                cin >> deposit->client;
                cout << "Enter start date: ";
                cin >> deposit->start_date;
                cout << "Enter end date: ";
                cin >> deposit->end_date;

                cout << "Enter term: ";
                deposit->term = getPositiveNumberInput();

                cout << "Enter interest rate: ";
                deposit->interest_rate = getPositiveNumberInput();

                stack.push(deposit);
                break;
            }
            case 2: {
                bool success = stack.removeDeposit();
                if (!success) {
                    cout << "Failed to remove deposit." << endl;
                }
                break;
            }
            case 3: {

                bool success = stack.updateDeposit();
                if (!success) {
                    cout << "Failed to update deposit." << endl;
                }
                break;
            }
            case 4: {
                stack.printAllDeposits();
                break;
            }
            case 5: {

                saveDepositsToFile(stack);
                break;
            }
            case 6: {
                sortDepositsByInterestRate(stack);
                cout << "Deposits sorted by interest rate." << endl;
                stack.printAllDeposits();
                break;
            }
            case 7: {
                string clientName;
                cout << "Enter client name: ";
                cin >> clientName;
                stack.printDepositByClient(clientName);
                break;
            }
            case 8: {
                int numDeposits = stack.countDeposits();
                cout << "Number of deposits: " << numDeposits << endl;
                break;
            }
            case 9: {
                string depositType;
                cout << "Enter deposit type: ";
                cin >> depositType;
                stack.printDepositsByType(depositType);
                break;
            }
            case 10: {
                Deposit* deposit = new Deposit();
                cout << "Enter deposit type: ";
                cin >> deposit->type;
                cout << "Enter client name: ";
                cin >> deposit->client;
                cout << "Enter start date: ";
                cin >> deposit->start_date;
                cout << "Enter end date: ";
                cin >> deposit->end_date;

                cout << "Enter term: ";
                deposit->term = getPositiveNumberInput();
                cout << "Enter interest rate: ";
                deposit->interest_rate = getPositiveNumberInput();

                stack.push(deposit);

                sortinsertDepositByTerm(stack);

                stack.printAllDeposits();
                cout << "Data successfully add." << endl;
                break;
            }
            case 0: {
                cout << "Exiting program." << endl;
                return 0;
            }

            default: {
                cout << "Invalid choice." << endl;
                break;
            }
        }
    }
}

