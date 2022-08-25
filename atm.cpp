//ATM Management System
#include <iostream>
#include <string>
using namespace std;
void showMenu();
class Account{
    private:
        string  accTitle, transAccTitle;
        string accType;
        int accNumber, transAccNo;
        int depositAmount = 0;
        int withdrawAmount = 0;
        int transferAmount = 0;
    protected:
        int balance;
    public:
        //Default Constructor
        Account(){
            accTitle = " ";
            accType = " ";
            accNumber = 0;
            depositAmount = 0;
            withdrawAmount = 0;
        };
        //Parametrized Constructor
        Account (string aTitle, string atype, int an, int da, int wa, int b){
            aTitle = accTitle;
            atype = accType;
            an = accNumber;
            da = depositAmount;
            wa = withdrawAmount;
            b = balance;
        }
        //Function to set the person's data
        void setData()
        {
            cout << "Enter Account Title: " << endl;
            getline(cin, accTitle);
            cout << "Enter Account No: " << endl;
            cin >> accNumber;   
        }  
        void setAccType(){
            cout << "Enter Account Type (Savings/Current): ";
            cin >> accType;
        }
        string getAccType(){
            return accType;
        }
        void setBalance(){
            cout << "Enter Balance: ";
            cin >> balance;
        }
        int getBalance(){
            return balance;
        }
        //Function to display the required data
        void showData()
        {
            cout << "Account Number: " << accNumber << endl;
            cout << "Account Type: " << accType << endl;
            cout << "Balance: " << balance << endl;
         } 
        //Function to deposit money in ATM
        void deposit()
        {
            cout << "\nEnter amount to be Deposited:\n";
            cin >> depositAmount;
            cout << "Rs" << depositAmount << " has been deposited successfully." << endl;
        }
        //Function to withdraw money from ATM
        void withdraw()
        {
            cout << "\nEnter amount to be Withdrawn:\n";
            cin >> withdrawAmount;
            cout << "Transaction Successful" << endl;
            cout << "Thankyou for using!" << endl;
        }
        void transfer()
        {
            cout << "\nEnter Account No. : \n";
            cin >> transAccNo;
            cout << "Enter Account Title: " << endl;
            cin >> transAccTitle;
            cout << "Enter amount to be transferred: " << endl;
            cin >> transferAmount;
            cout << "Rs" << transferAmount << " has been transferred successfully." << endl;
        }
        //Function to show the balance amount
        void showBalance()
        {
            if (depositAmount > 0){
                balance = balance + depositAmount;
            }
            else if(withdrawAmount > 0)            
            {
                balance = balance - withdrawAmount;
            }
            else
            {
                balance = balance - transferAmount;
            }
        cout << "Available Balance is: " << balance << endl;
        }
        //Operator Overloading
        bool operator == (const Account& obj ) const{
            return ( "savings" == obj.accType);
        }
};
//Inheritance
class SavingsAccount : public Account{
    public:
    void setValue(int bal){
        balance = bal;
    }
    //Function OverRiding
    void showBalance(){
        int newBalance;
        newBalance = ((balance*5)/100) + balance;
        cout << "Available Balance is: Rs" << newBalance << endl;
        cout << "This includes your monthly return amount of 5'%'on your balance." << endl;
    }
    //Function to calculate monthly return amount
    void calculateMonthlyReturn(){
        float monthlyReturn;
        monthlyReturn = (balance*0.05);
        cout << "Your monthly return for this month is Rs"<< monthlyReturn << " on the balance of Rs" << balance << endl;
    }
};
//Function to display menu
void showMenu(){
    cout << "\n             Enter Your Choice        \n" << endl;
    cout << "      1. Show Account Data " << endl;
    cout << "      2. Deposit Money" << endl;
    cout << "      3. Withdraw Money" << endl;
    cout << "      4. Transfer Money" << endl;
    cout << "      5. Check Balance"  << endl;
    cout << "      6. Check Monthly Return Amount" << endl;
    cout << "      7. Cancel\n" << endl;
}
// Driver Code
int main(){
    cout << "\n\n\n******************  WELCOME  ******************\n" << endl;
    // Object of the class
    Account a1;
    SavingsAccount sa1;
    a1.setData();
    a1.setAccType();
    a1.setBalance();
    int option, pin;
    // Infinite loop to choose option every time
    while (1)
    {
        showMenu();
        cout << "Enter Option:  ";
        cin >> option;
        cout << "Enter PIN:  " ;
        cin >> pin;
        if ( a1.getAccType() == "savings"){
            switch (option)
            {
                case 1:
                    a1.showData(); break;
                case 2:
                    a1.deposit(); break;
                case 3:
                    a1.withdraw(); break;
                case 4:
                    a1.transfer(); break;
                case 5:
                    int bal;
                    bal = a1.getBalance();
                    sa1.setValue(bal);
                    sa1.showBalance();      
                break;
                case 6:
                    bal = a1.getBalance();
                    sa1.setValue(bal);
                    sa1.calculateMonthlyReturn(); 
                break;
                case 7: 
                    exit(1); break;
                default:
                    cout << "\nInvalid Choice \n";
            }
        }        
        else 
        {
            switch (option)
            {
            case 1:
                a1.showData(); break;
            case 2:
                a1.deposit(); break;
            case 3:
                 a1.withdraw(); break;
            case 4:
                a1.transfer(); break;
            case 5:
                 a1.showBalance(); break;      
            case 6:
                 cout << "You have a CURRENT account which has no monthly return rate." << endl; break;
            case 7:
                exit(1); break;
            default:
                cout << "\nInvalid Choice \n";
            }
        }
    }
    return 0;
} 