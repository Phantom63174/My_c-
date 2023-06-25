#include <iostream>
#include <string>
#define N 10

using namespace std;

struct Sportsman {
    string name;
    string last_name;
    string surname;
    string country;
    string name_trainer;
    int birthday{};
    double result{};
} sport[N];

void input_sportsmen_data(Sportsman* s) {
    cout << "Enter the name: " << endl;
    cin >> s->name;
    cout << "Enter the last name: " << endl;
    cin >> s->last_name;
    cout << "Enter the surname: " << endl;
    cin >> s->surname;
    cout << "Enter the country: " << endl;
    cin >> s->country;
    cout << "Enter the name of trainer: " << endl;
    cin >> s->name_trainer;
    cout << "Enter the birthday: " << endl;
    cin >> s->birthday;
    cout << "Enter the result: " << endl;
    cin >> s->result;
}

int main() {
    int i = 1, d = 1,f=1;
    do {
        input_sportsmen_data(&sport[i]);
        cout << "Enter 1 if you want to continue, enter 0 if you want to stop entering data:" << endl;
        cin >> d;
        i++;
    } while (d == 1);
    do {
        string trainer;
        cout << "Enter the name of trainer to sort sportsmen: " << endl;
        cin >> trainer;

        int youngest = sport[1].birthday;

        for (Sportsman *s = &sport[1]; s < &sport[i]; s++) {
            if (s->name_trainer == trainer) {
                if (youngest > s->birthday) {
                    youngest = s->birthday;
                }
            }
        }

        for (Sportsman *s = &sport[1]; s < &sport[i]; s++) {
            if(s->name_trainer == trainer) {
                if (youngest == s->birthday) {
                    cout << "Youngest sportsman with trainer " << s->name_trainer << ": " << s->name << " "
                         << s->last_name
                         << " " << s->surname << ", born in " << s->birthday << endl;
                }
            }
        }
        cout << "Enter 1 if you want to continue, enter 0 if you want to stop program:" << endl;
        cin >> f;
    }while(f==1);
    return 0;
}

