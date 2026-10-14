#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    int balance;

public:
    BankAccount()
    {
        accountNumber = 0;
        accountHolderName = "";
        balance = 0;
    }
    BankAccount(int accno, string name, int bal)
    {
        int accountNumber = accno;
        string accountHolderName = name;
        double balance = bal;
    }
    ~BankAccount()
    {
    }

    void set_accountNumber(int accno)
    {
        accountNumber = accno;
    }
    void set_accountHolderName(string name)
    {
        accountHolderName = name;
    }
    void set_balance(double bal)
    {
        balance = bal;
    }
    int get_accountNumber()
    {
        return accountNumber;
    }
    string get_accountHolderName()
    {
        return accountHolderName;
    }
    int get_balance()
    {
        return balance;
    }
    void desposit(double bal)
    {
        balance = balance + bal;
    }
    void withdraw(double amount)
    {
        if (amount < balance)
        {
            cout << "Withdrawal successful!" << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
    virtual double calculatorInterest()
    {
        return 0;
    }
    void displayAccountInfo()
    {
        cout << "---Account Info---" << endl;
        cout << "Account No: " << endl;
        cout << "Holder Name : " << endl;
        cout << "Balance : " << endl;
    }
};
class SavingsAccount : public BankAccount
{
private:
    int interestRate;

public:
    SavingsAccount() : BankAccount()
    {
        interestRate = 0;
    }
    SavingsAccount(int accno, string name, int bal, int rate) : BankAccount(accno, name, bal)
    {
        interestRate = rate;
    }
    void set_interestRate(int rate)
    {
        interestRate = rate;
    }
    int get_interestRate()
    {
        return interestRate;
    }
    void calculateInterest(double amount)
    {
        cout << get_balance() * interestRate / 100 << endl;
    }
    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate : " << endl;
    }
};
class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount() : BankAccount()
    {
        overdraftLimit = 0;
    }
    CheckingAccount(int accno, string name, double bal, double limit) : BankAccount(accno, name, bal)
    {
        overdraftLimit = limit;
    }
    void set_overdraftLimit(double limit)
    {
        overdraftLimit = limit;
    }
    int get_overdraftLimit()
    {
        return overdraftLimit;
    }
    void checkOverdraft(double amount)
    {
        if (get_balance() < amount)
        {
            cout << "overdraft exceeds";
        }
        else
        {
            cout << "overdraft not exceed";
        }
    }
    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit : " << endl;
    }
};
class FixedDepositAccount : public BankAccount
{
private:
    int term;

public:
    FixedDepositAccount() : BankAccount()
    {
        term = 0;
    }
    FixedDepositAccount(int accno, string name, int bal, int t) : BankAccount(accno, name, bal)
    {
        term = t;
    }
    void set_term(int t)
    {
        term = t;
    }
    int get_term()
    {
        return term;
    }
    void calculateInterest()
    {
        int rate;
        cout << get_balance() * rate * term / 100 << endl;
    }
    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Term : " << endl;
    }
};
int main()
{
    int choice;
    do
    {
        cout << "1. Savings Account" << endl;
        cout << "2. Checking Account" << endl;
        cout << "3. Fixed Deposit Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : " << endl;
        cin >> choice;

        if (choice == 1)
        {
        int accno;string name;double bal;int rate;
        cout<<"Account name : "<<endl;

        }
        else if(choice==2){

        }
        else if(choice==3){
            
        }

    } while (choice != 4);
    return 0;
}