#include <iostream>
#include <string>
using namespace std;

struct athlete{
string last_name;
string country;
int birthday_date;
int result;
int height;
int weight;
};

void enter_value(athlete *s,int num_athletes){
    for (int i = 0; i < num_athletes; i++) {
        cout << "Enter last name of athlete #" << i + 1 << ":"<< endl;
        cin >> s[i].last_name;
        cout << "Enter the country of athlete #" << i + 1 << ":"<< endl;
        cin >> s[i].country;
        cout << "Enter the birthday of athlete #" << i + 1 << " (year):"<< endl;
        cin >> s[i].birthday_date;
        cout << "Enter result of athlete #" << i + 1 << ":" << endl;
        cin >> s[i].result;
        cout << "Enter the height of athlete #" << i + 1 << " (in cm):" << endl;
        cin >> s[i].height;
        cout << "Enter the weight of athlete #" << i + 1 << " (in kg):" << endl;
        cin >> s[i].weight;
    }
}

void calc_avg(athlete *s,int num_athletes,string &country, double &avg_weight, double &avg_height){
    int num_of_athlete_country=0;
    int sum_weight=0;
    int sum_height=0;
for(int i=0; i<num_athletes; i++){
if(s[i].country == country) {
    num_of_athlete_country++;
    sum_height += s[i].height;
    sum_weight += s[i].weight;
}
if(num_of_athlete_country > 0){
    avg_height = static_cast<double>(sum_height) / num_of_athlete_country;
    avg_weight = static_cast<double>(sum_weight) / num_of_athlete_country;
}
    else{
        cout << "There are no athletes from " << country << " in the list." << endl;
    }
}
}

void find_best(athlete *s, int num_athletes, string country) {
    int best_result = 0;
    string best_athlete;
    for (int i = 0; i < num_athletes; i++) {
        if (s[i].country == country && s[i].result > best_result) {
            best_result = s[i].result;
            best_athlete = s[i].last_name;
        }
    }
    if (best_result > 0) {
        cout << "The best athlete from " << country << " is " << best_athlete << ", with a result of " << best_result << endl;
    } else {
        cout << "There are no athletes from " << country << " in the list." << endl;
    }
}

void find_athletes(athlete *s, int num_athletes, int age, int result){
    cout << "List of athletes aged " << age << " or above with result not worse than " << result << ":" << endl;
    for (int i = 0; i < num_athletes; i++) {
        if (s[i].birthday_date <= (2023 - age) && s[i].result >= result) {
            cout << s[i].last_name << ", " << s[i].country << ", " << s[i].birthday_date << ", " << s[i].result << endl;
        }
    }

}
int main() {

    int num_athletes;
    cout << "Enter the number of athletes: " << endl;
    cin >> num_athletes;
    athlete *athletes = new athlete[num_athletes];
    enter_value(athletes, num_athletes);

    string country;
    cout << "Enter the name of the country to calculate average height and weight: " << endl;
    cin >> country;

    double avg_height, avg_weight;
    calc_avg(athletes, num_athletes, country, avg_weight, avg_height);
    cout << "The average height of athletes from " << country << " is: " << avg_height << " cm" << endl;
    cout << "The average weight of athletes from " << country << " is: " << avg_weight << " kg" << endl;

    find_best(athletes, num_athletes, country);

    int age, result;
    cout << "Enter the minimum age of athletes to display: " << endl;
    cin >> age;
    cout << "Enter the minimum result of athletes to display: " << endl;
    cin >> result;

    find_athletes(athletes, num_athletes, age, result);

    delete[] athletes;

    return 0;
}
