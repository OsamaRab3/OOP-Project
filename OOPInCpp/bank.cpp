#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
class Bank
{
private:
    int id, ps;
    fstream file;
    string name, userData;

public:
    void display();
    Bank()

    {
        userData = "example_data";
        file.open("userData.txt", ios::in | ios::app | ios::out);

        if (!file.is_open())
        {
            cerr << "Error: Unable to open file userData.txt\n";
            // Handle the error, maybe throw an exception or exit the program
        }
    }

    ~Bank()
    {
        file.close();
    }
    void Invalid();
    int menu();
    void run_menu();
    void singUp();
    void new_user();
    void LogIn();

} b;
class B
{
private:
    int *balance;
    string userData;
    fstream file;

public:
    B()
    {
        userData = "example_data";
        file.open("userData.txt", ios::in | ios::app | ios::out);

        if (!file.is_open())
        {
            cerr << "Error: Unable to open file userData.txt\n";
            // Handle the error, maybe throw an exception or exit the program
        }
        balance = new int(100);
    }
    ~B()
    {
        // file.close();
        delete balance;
    }
    int bank_managment();
    void run_bank();
    void deposit();
    void withdraw();
    void Payment();
    int *get();
} bm;
class atm
{
private:
    string userData;
    fstream file;

public:
    atm()
    {
        userData = "example_data";
        file.open("userData.txt", ios::in | ios::app | ios::out);

        if (!file.is_open())
        {
            cerr << "Error: Unable to open file userData.txt\n";
            // Handle the error, maybe throw an exception or exit the program
        }
    }
    ~atm()
    {
        file.close();
    }
    void log_atm();
    int atm_management();
    void run();
} a;

void star()
{
    cout << "===============================================================================\n";
}
int main()
{
    system("cls");
    b.run_menu();

    return 0;
}
//////////////////////////////class Bank//////////////////////////
int Bank::menu()
{
    int choice;
    cout << "\t\t\t control panle \n\n";
    star();
    cout << "1.Bank management \n";
    cout << "2.Atm management \n";
    cout << "3.Exit \n";
    cout << "Enter your choic  ";
    cin >> choice;
    star();
    return choice;
}
void Bank::run_menu()
{
    //  system("cls");
    int c = menu();
    if (c == 1)
    {
        LogIn();
        // bm.run_bank();
        // // break;
    }
    else if (c == 2)
    {
        a.run();
    }
    else if (c == 3)
    {
        exit(0);
    }
    else
    {
        cout << "Invalid choice tray agine \n";
    }
}
void Bank::singUp()
{
    string user_name;
    int ps, pin;

    cout << "sing up in Account \n";
    cout << "User name  ";
    cin >> user_name;
    cout << "\nID \n";
    cin >> pin;

    cout << "\nEnter password\n";
    cin >> ps;

    file << user_name << " " << pin << " " << ps << "\n";
}
void Bank::LogIn()
{
    star();
    cout << "Enter your name ,id ,password\n";
    cin >> name >> id >> ps;
    // b.Invalid();
    string namee;
    int iD, pass;
    bool found = false;
    // Loop through the file to check data
    while (file >> namee >> iD >> pass)
    {
        if (name == namee && id == iD && ps == pass)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
    {
        cout << "\n\t\tLogin successful\n";
        star();
        bm.run_bank();
    }
    else
    {
        cout << "\nError: Incorrect username, ID, or password\n";
    }
}
void Bank::new_user()
{

    // system("cls");
    fstream file("userData.txt", ios::in | ios::app | ios::out);
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file userData.txt\n";
        return;
    }
    cout << "\t\t\tAdd New User\n";
    star();
    cout << "User name  ";

    cin >> b.name;

    cout << "\nUser ID  ";
    cin >> b.id;

    cout << "\nUser Password  ";
    cin >> b.ps;

    file << b.name << " " << b.id << " " << b.ps << "\n";
}
/// //////////////////////// //////////////////////////////////////////////
void B::deposit()
{

    int newblance;
    cout << "enter value\n";
    cin >> newblance;
    //  int* x=&newblance;
    *balance += newblance;
}
void B::withdraw()
{

    int newblance;
    while (true)
    {

        cout << "enter value\n";
        cin >> newblance;
        // int *x=&newblance;
        if (newblance > *balance)
        {
            cout << "Eror your balance is less than value you want to withdraw\n";
        }
        else
        {
            *balance -= newblance;
            break;
        }
    }
}
int *B::get()
{

    return balance;
}
void B::Payment()
{
    int u_id, B_amount,pas;
    string B_name;
    fstream file;
    SYSTEMTIME X{};
    cout << "\t\tPayment Optine \n";
    star();
    cout << "Enter Bill name \n";
    cin >> B_name;
    cout << "Enter User iD \n";
    cin >> u_id;
    cout<<"Enter password\n";
    cin>>pas;
    string name_;
    int id_, ps;
    bool found = false;
    file.open("userData.txt", ios::in  | ios::out);

    if (!file.is_open())
    {
        cerr << "Error: Unable to open file userData.txt\n";
        // Handle the error, maybe throw an exception or exit the program
    }
    while (file >> name_ >> id_ >> ps)
    {
        if (B_name == name_ && u_id == id_&&pas==ps)
        {
            found = true;
            break;
        }
    }
    file.close();

    if (found)
    {
        cout << "Enter Bill amount \n";
        cin >> B_amount;

        if (B_amount <= *balance)
        {
            *balance -= B_amount;
            file << endl
                 << *balance << " " << X.wDay << "/" << X.wMonth << "/" << X.wYear << "\n";
            cout << "Bill by sucessfully\n";
        }
        else
        {
            cout << "ERORR \n";
        }
    }
    else
    {
        cerr << "Invalid Value .....\n";
    }
}

int B::bank_managment()
{
    int choice;
    cout << "\t\t\t\tBank mangemnt system\n";
    star();
    cout << "1  New User\n";
    cout << "2  Already User\n";
    cout << "3  Deposit Optine\n";
    cout << "4  Withdraw Optine\n";
    cout << "5  Transfar Optine\n";
    cout << "6  Payment Optione\n";
    cout << "7  Go Back\n";
    cout << "Enter your choice  ";
    cin >> choice;
    star();
    return choice;
}
void B::run_bank()
{
    while (true)
    {
        // system("cls");
        int c = bank_managment();
        if (c == 1)
        {
            b.new_user();
        }
        else if (c == 2)
        {
            b.LogIn();
        }
        else if (c == 3)
        {
            deposit();
            int *x = get();
            cout << "new balance is: " << *x << endl;
        }
        else if (c == 4)
        {
            withdraw();
            int *x = get();
            cout << "new balance is: " << *x << endl;
        }
        else if (c == 5)
        {
            break;
        }
        else if (c == 6)
        {
            Payment();
            int *x = get();
            cout << "new balance is: " << *x << endl;
        }
        else if (c == 7)
        {
            b.run_menu();
            break;
        }
        else
            cout << "Invalid choice. Try again.\n";
    }
}
/////////////////////////class atm ////////////////////////
///
int atm::atm_management()
{
    int choice;
    cout << "\t\t\tAtm managemnt system \n";
    star();
    cout << "1.User log in \n";

    cout << "2.Go back  ";
    cin >> choice;

    return choice;
}
void atm::run()
{

    while (true)
    {
        //  system("cls");
        int c1, c = atm_management();
        if (c == 1)
        {
            log_atm();
            cout << "1.withdraw amount \n";
            cout << "2.Account diatels\n";
            cout << "3.Go back  ";
            cin >> c1;
            if (c1 == 1)
            {
                bm.withdraw();
                int *x = bm.get();
                cout << "Your new balance is " << *x << endl;
            }
            else if (c1 == 2)
            {
                string name;
                int id, password;
                fstream file("userData.txt", ios::in | ios::app | ios::out);
                if (!file.is_open())
                {
                    cerr << "Error: Unable to open file userData.txt\n";
                    return;
                }
                file >> name >> id >> password;

                cout << "user name is: " << name << " your ID is: " << id << " your password is: " << password << endl;
                star();
            }
            else if (c1 == 3)
            {
                b.run_menu();
                break;
            }
            else
            {
                cout << "Invalis choice trayn agine \n";
            }
        }
        else if (c == 2)
        {
            star();
            b.run_menu();
        }
        // getch();
    }
}

void atm::log_atm()
{
    star();
    string name;
    int id, ps;
    cout << "Enter your name ,id ,password\n";
    cin >> name >> id >> ps;

    fstream file("userData.txt", ios::in | ios::app | ios::out);
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file userData.txt\n";
        return;
    }
    string namee;
    int iD, pass;
    bool found = false;
    // Loop through the file to check data
    while (file >> namee >> iD >> pass)
    {
        if (name == namee && id == iD && ps == pass)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "\n\t\tLogin successful\n";
        star();
    }
    file.close();
}
