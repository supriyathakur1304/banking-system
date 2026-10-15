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
    BankAccount(int accno, string name, double bal)
    {
        accountNumber = accno;
        accountHolderName = name;
        balance = bal;
    }
    double get_balance()
    {
        return balance;
    }
   virtual void deposit(double amount)
    {
        balance = balance + amount;
    }
    virtual void withdraw(double amount)
    {
        if (amount >balance)
        {
            cout << "Insufficient withdraw" << endl;
        }
        else
        {
            balance=balance-amount;
        }
    }
   
    void displayAccountInfo()
    {
        cout << "---Account Info---" << endl;
        cout << "Account No: " << endl;
        cout << "Holder Name : " << endl;
        cout << "Balance : " << endl;
    }
    virtual void calculateInterest()
    {
   
    }
};
class SavingsAccount : public BankAccount
{
private:
    int interestRate;

public:
    
    SavingsAccount(int accno, string name, double bal, int rate) : BankAccount(accno, name, bal)
    {
        interestRate = rate;
    }
    
    void calculateInterest()override
    {
        cout << get_balance() * interestRate / 100 << endl;
    }
    void deposit(double amount)override
    {
        cout<<"Saving Account Deposit"<<endl;
        BankAccount::deposit(amount);

    }
    void withdraw(double amount)override{
        cout<<"Saving Account Withdraw"<<endl;
        BankAccount::withdraw(amount);
    }

   
};
class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
   
    CheckingAccount(int accno, string name, double bal, double limit) : BankAccount(accno, name, bal)
    {
        overdraftLimit = limit;
    }
    
    void checkOverdraft(double amount)
    {
        if (amount>get_balance()+overdraftLimit)
        {
            cout << "Account Overdraft Exceeded"<<endl;
        }
        
    }
};
class FixedDepositAccount : public BankAccount
{
private:
    int term;

public:
  
    FixedDepositAccount(int accno, string name, int bal, int t) : BankAccount(accno, name, bal)
    {
        term = t;
    }

    void calculateInterest() override
    {
     
        cout << get_balance() * term * 12 / 1200 << endl;
    }
    void deposit(double amount) override
    {
        cout << "FixedDeposit Account Deposit" << endl;
        BankAccount::deposit(amount);
    }
    void withdraw(double amount) override
    {
        cout << "FixedDeposit Account Withdraw" << endl;
        BankAccount::withdraw(amount);
    }
};
int main()
{
    int choice;
    SavingsAccount savings(101, "Supriya", 2000, 10);
    CheckingAccount checking(102, "Rashi", 2000, 1000);
    FixedDepositAccount fixeddeposit(103, "Pragya", 4000, 2);

    do
    {
        
        cout << "1. Savings Account" << endl;
        cout << "2. Checking Account" << endl;
        cout << "3. FixedDeposit Account" << endl;
        cout<<"0. Exit"<<endl;

        cout << "Enter your choice : " ;
        cin >> choice;

        if (choice == 1)
        {
            cout<<"1. Deposit"<<endl;
            cout<<"2. Withdraw"<<endl;
            cout<<"3. Interest Rate"<<endl;
           
            int choice;
            cout<<"Enter your choice : ";
            cin>>choice;

            if(choice==1){
                double money;
                cout<<"Enter your money: ";
                cin>>money;
                savings.deposit(money);
            }
            else if(choice==2){
                double money;
                cout<<"Enter your money: ";
                cin>>money;
                savings.withdraw(money);
            }
            else if(choice==3){
                savings.calculateInterest();
            }
         
        }
        else if (choice == 2)
        {
            double amount;
            cout<<"Enter your amount: ";
            cin>>amount;

            checking.checkOverdraft(amount);
        }
        else if (choice == 3)
        {
            cout<<"1. Deposit"<<endl;
            cout<<"2. withdraw"<<endl;
            cout<<"3. Interest Rate"<<endl;

            int choice;
            cout<<"Enter your choice : ";
            cin>>choice;
            if(choice==1){
                double money;
                cout<<"Enter your money: ";
                cin >> money;
                fixeddeposit.deposit(money);
            }
            else if (choice == 2)
            {
                double money;
                cout << "Enter your money: " ;
                cin>>money;
                fixeddeposit.withdraw(money);
            }
            else if (choice == 3)
            {
                fixeddeposit.calculateInterest();
            }
            
        }
        else if(choice==0){
            cout<<"Exit"<<endl;
        }
        else{
            cout<<"Invalid input"<<endl;
        }


    } while (choice != 0);
    return 0;
}