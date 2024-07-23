#include <iostream>      //libraries

#include <fstream>

#include <ctime>

#include <cmath>

#include <iomanip>

#include <string>

#include <windows.h>

#include <conio.h>

using namespace std;
void redraw() { //using functions
    int x = 0, i = 0, j = 0, l = 0;
    int lines = 0;
    string companies;
    string symbol[38];
    string name[38];
    string arr[38][3];
    string price[38];
    float integer[38];
    float cprice[38];
    float high[38];
    float low[38];
    float total[38];
    ifstream file1;
    system("Color 0");
    cout << "\033[1;33m" << "*************************************************************************************** " << "KARACHI STOCK MARKET (LIVE)" << " *********************************************************************************************" << endl;
    cout << "\033[1;35m" << "SHOW UPDATES(ENTER)" << "\t" << "SHOW PORTFOLIO(P)" << "\t" << "ADD STOCK(A)" << "\t" << "REMOVE STOCK(R)" << "\t"
    "\t" << "ADD MONEY(M)" << "\t" << "EXIT(E)" << endl;
    cout << left << setw(30) << "\033[1;34m" << "SYMBOL";
    cout << "\033[1;34m" << setw(55) << "COMPANY NAME" << setw(45) << "PREVIOUS PRICE" << setw(25) << "CURRENT PRICE" << setw(25) << "HIGH" << setw(25) << "LOW" << "\033[1;37m" << endl;
    file1.open("companies.txt");
    while (!file1.eof()) { //reading file till end of file
        getline(file1, companies);
        for (int x = 0; companies[x] != '\0'; x++) { //seperating commas
            if (companies[x] == ',') {
                j++;
                continue;
            } else {
                arr[i][j] = arr[i][j] + companies[x];
            }
        }
        i++;
        j = 0;
    }
    for (int i = 0; i < 38; i++) { //assigning 2d arrays to paralel arrays
        price[i] = arr[i][2];
    }
    for (int i = 1; i < 38; i++) {
        float num_price = stof(price[i]);
        integer[i] = num_price;
    }
    for (int i = 0; i < 38; i++) {
        symbol[i] = arr[i][0];
        name[i] = arr[i][1];
    }
    for (int k = 1; k < 38; k++) { //loop for cout
        cprice[k] = rand() % 15 * (0.5);
        if (cprice[k] < 3) {
            cprice[k] = cprice[k] + integer[k] + 1;
        } else {
            cprice[k] = integer[k] - cprice[k];
        }
        if (cprice[k] > integer[k]) {
            high[k] = cprice[k];
            low[k] = integer[k];
            system("Color 0");
            cout << left << setw(30) << symbol[k];
            cout << setw(55) << name[k] << setw(45) << integer[k] << setw(10) << "\033[1;92m" << setw(10) << cprice[k] << setw(10) << "\x18" << "\033[1;37m" << setw(25) << high[k] << setw(25) << low[k] << endl;
        } else if (cprice[k] < integer[k]) {
            low[k] = cprice[k];
            high[k] = integer[k];
            system("Color 0");
            cout << left << setw(30) << symbol[k];
            cout << setw(55) << name[k] << setw(45) << integer[k] << setw(10) << "\033[1;91m" << setw(10) << cprice[k] << setw(10) << "\x19" << "\033[1;37m" << setw(25) << high[k] << setw(25) << low[k] << endl;
        }
    }
    cout << endl << endl << "Total Shares Traded Today : " << rand() % 90000000000 << endl;
    int adv;
    adv = rand() % 37;
    int dec;
    dec = rand() % 37;
    cout << "Top Advancer : " << "\033[1;92m" << symbol[adv] << endl << "\033[1;37m"; //logic for adv and dec
    cout << "Top Decliner : " << "\033[1;91m" << symbol[dec] << endl << "\033[1;37m";
}
void portfolio(float & current, string & symbolize, int & bstock1) { //functions
    string name;
    char repeat;
    float cmoney;
    int shares;
    string sym;
    ofstream file2;
    file2.open("portfolio.txt"); //making portfolio
    cout << "Enter Your Name : ";
    getline(cin, name);
    file2 << name;
    system("cls");
    cout << "\033[1;33m" << "PORTFOLIO OWNER: " << name << " (LIVE)" << endl;
    cout << "\033[1;35m" << "LIVE MARKET(ENTER)" << "\t" << "ADD STOCK(A)" << "\t" << "REMOVE STOCK(R)" << "\t"
    "\t" << "ADD MONEY(M)" << "\t" << "WITHDRAW MONEY(W)" << "\t" << "EXIT(E)" << endl;
    cout << "\033[1;34m" << left << setw(30) << "SYMBOL";
    cout << "\033[1;34m" << setw(25) << "SHARES" << setw(45) << "CURRENT PRICE" << setw(45) << "HIGH" << setw(25) << "LOW" << "\033[1;37m" << endl;
    cout << setw(32) << symbolize << setw(29) << bstock1 << setw(39) << "167.94" << setw(45) << "174.11" << setw(35) << "167.94" << endl;
    cout << "Current Money : " << current + 10000 << endl; //arrangement
}
void addmoney(float & current) {
    float cmoney;
    float integer[38];
    float cprice[38];
    int bstock;
    string symbolize;
    cout << "How Much Money You Want To Add : ";
    cin >> cmoney;
    current = current + cmoney;
    portfolio(current, symbolize, bstock);
}
void withdraw(float & current) {
    float minus;
    int bstock;
    string symbolize;
    cout << "How Much You Want To Withdraw : ";
    cin >> minus;
    current = current - minus;
    if (current > 0) {
        portfolio(current, symbolize, bstock);
    } else {
        system("cls"); //input validation
        cout << "YOU ARE POOR____SORRY____NOT ENOUGH BALANCE" << endl;
        portfolio(current, symbolize, bstock);
    }
}
void addstock() {
    string symbolize;
    float current;
    ifstream file3;
    file3.open("sym.txt");
    while (!file3.eof()) {
        getline(file3, symbolize);
        cout << symbolize << endl;
    }
    int bstock1;
    string bstock;
    cin >> bstock;
    symbolize = bstock;
    cout << "How many : ";
    cin >> bstock1;
    portfolio(current, symbolize, bstock1);
}
void removestock() {
    string symbolize;
    float current;
    int bstock1;
    int bstock2, bstock3;
    cout << "Which Stock You Want To Remove : ";
    cin >> bstock2;
    cout << "How many : ";
    cin >> bstock3;
    portfolio(current, symbolize, bstock1);
}
int main() {
    srand(static_cast < float > (time(0)));
    char ch; //input validation and controling output
    int bstock1;
    char decision;
    float current;
    string symbolize;
    string sym;
    int shares;
    redraw();
    while (ch != 1) {
        ch = getch();
        if (ch == 13) {
            system("cls");
            redraw();
        } else if (ch == 'e') {
            system("cls");
            return 0;
        } else if (ch == 'p') {
            system("cls");
            portfolio(current, symbolize, bstock1);
        } else if (ch == 'a') {
            system("cls");
            addstock();
        } else if (ch == 'r') {
            system("cls");
            removestock();
        } else if (ch == 'm') {
            system("cls");
            addmoney(current);
        } else if (ch == 'w') {
            system("cls");
            withdraw(current);
        } else {
            system("cls");
            cout << "INVALID INPUT _____ DO YOU WANT TO RUN IT AGAIN (y/n) : " << endl;
            decision = getch();
            if (decision == 'y') {
                system("cls");
                redraw();
            }
        }

    }
}