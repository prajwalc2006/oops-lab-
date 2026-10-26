#include <iostream>

#include <string>

using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    void open(const string& name, double initial) {
        owner = name;
        balance = (initial > 0) ? initial : 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }

    string getOwner() const {
        return owner;
    }
};

int main() {
    BankAccount a;
    a.open("Asha", 1000);
    a.deposit(500);

    if (!a.withdraw(2000)) {
        cout << "withdraw denied (insufficient)\n";
    }

    a.withdraw(300);
    cout << a.getOwner() << " balance=" << a.getBalance() << endl;
    return 0;
}