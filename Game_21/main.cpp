#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int chislo();
void proschet(int Z, int Y);
void random();
void chislo_bot();

int random_player = 0;  // Random player
int player_Score = 0; // Player's score
int bot_Score = 0; // Bot game score
int random_bot = 0; // Random bot

void chislo_bot()
{
    if (random_bot == 0)
        cout << "[Last enemy cart]: 7.\n";
    else if (random_bot == 1)
        cout << "[Last enemy cart]: 8.\n";
    else if (random_bot == 2)
        cout << "[Last enemy cart]: 9.\n";
    else if (random_bot == 3)
        cout << "[Last enemy cart]: 10.\n";
    else if (random_bot == 4)
        cout << "[Last enemy cart]: jack.\n";
    else if (random_bot == 5)
        cout << "[Last enemy cart]: queen.\n";
    else if (random_bot == 6)
        cout << "[Last enemy cart]: king.\n";
    else if (random_bot == 7)
        cout << "[Last enemy cart]: ace.\n";
}


int chislo()
{
    if (random_player == 0)
        cout << "[Dropped card]: You've got a 7.\n";
    else if (random_player == 1)
        cout << "[Dropped card]: You've got a 8.\n";
    else if (random_player == 2)
        cout << "[Dropped card]: You've got a 9.\n";
    else if (random_player == 3)
        cout << "[Dropped card]: You've got a 10.\n";
    else if (random_player == 4)
        cout << "[Dropped card]: You've got a jack.'2-points.'\n";
    else if (random_player == 5)
        cout << "[Dropped card]: You've got a queen.'3-points.'\n";
    else if (random_player == 6)
        cout << "[Dropped card]: You've got a king.'4-points.'\n";
    else if (random_player == 7)
        cout << "[Dropped card]: You've got an ace.'11-points.'\n";
    return 0;
}

void proschet(int Z, int Y)
{
    cout << "\nYou've thrown out the card\n" << endl;
    if (Z < Y && Y <= 21)
        cout << "You lose.\n";
    if (Z > Y&& Z <= 21)
        cout << "You've won.\n";
    else if (Z == 0 || Y == 0)
        cout << "[Did you find the error 0x0003]";
    else if (Z > 21)
        cout << "You lose.";
    else if (Y > 21)
        cout << "You've won.";
    chislo_bot();
    cout << "Game over.\n"; // Z - player_score Y - bot_score
}


void random()
{
    switch (random_player) //
    {
        case 0:
        {
            player_Score = 7;
            break;
        }
        case 1:
        {
            player_Score = 8;
            break;
        }
        case 2:
        {
            player_Score = 9;
            break;
        }
        case 3:
        {
            player_Score = 10;
            break;
        }
        case 4:
        {
            player_Score = 2;
            break;
        }
        case 5:
        {
            player_Score = 3;
            break;
        }
        case 6:
        {
            player_Score = 4;
            break;
        }
        case 7:
        {
            player_Score = 11;
            break;
        }
        default:
        {
            cout << "If you see this line, then you have found a bug in the game. 0x0002";
        }
    }
    switch (random_bot)
    {
        case 0:
        {
            bot_Score = 7;
            break;
        }
        case 1:
        {
            bot_Score = 8;
            break;
        }
        case 2:
        {
            bot_Score = 9;
            break;
        }
        case 3:
        {
            bot_Score = 10;
            break;
        }
        case 4:
        {
            bot_Score = 2;
            break;
        }
        case 5:
        {
            bot_Score = 3;
            break;
        }
        case 6:
        {
            bot_Score = 4;
            break;
        }
        case 7:
        {
            bot_Score = 11;
            break;
        }
        default:
        {
            cout << "If you see this line, then you have found a bug in the game 0x0001";
        }
    }
}

int main()
{
    srand(time(0));
    int N; // When in the main menu
    int E; // When I chose menu 2
    int G2; // Continuation of the game 1
    int G3; // Continuation of the game 2
    int sum1_player = 0; // Sum of 1 games
    int sum1_bot = 0;
    int sum2_player = 0; // Sum of 2 games
    int sum2_bot = 0;
    int GFINAL;
    cout << "Game 21 card \n1.Start the game\n";
    cin >> N;
    if (N == 1)
    {
        cout << "You've started the game, we're dealing cards...\n";
        random_player = rand() % 8;
        random_bot = rand() % 8;
        random();
        chislo();
        cout << "Enter the action:\n1.Take another map\n2.Throw out the card: \nAttention: you can take cards only 3 times!\n";
        cin >> G2;
    }
    else if (N > 2)
        cout << "You can't enter more than 2.";
    if (G2 == 1)
    {
        sum1_player = player_Score;
        sum1_bot = bot_Score;
        random_player = rand() % 8;
        random_bot = rand() % 8;
        random();
        chislo();
        cout << "Enter the action:\n1.Take another map\n2.Throw out the card: \nAttention: you can take cards only 3 times!\n";
        cin >> G3;
    }
    else if (G2 == 2)
    {
        proschet(player_Score, bot_Score);
    }
    if (G3 == 1)
    {
        sum2_player = player_Score + sum1_player;
        sum2_bot = bot_Score + sum1_bot;
        random_player = rand() % 8;
        random_bot = rand() % 8;
        random();
        chislo();
        cout << "Enter the action:\n1.Throw out the card.";
        cin >> GFINAL;
    }
    else if (G3 == 2)
        proschet(sum1_player, sum1_bot);
    if (E == 1)
    {
        cout << "Main menu\n1.Start the game";
        cin >> N;
    }
    if (GFINAL == 1)
        proschet(sum2_player, sum2_bot);
    system("Pause");
    return 0;
}