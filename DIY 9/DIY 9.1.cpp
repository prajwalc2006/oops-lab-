#include <iostream>
#include <stdexcept>
using namespace std;

class InsufficientFunds : public runtime_error {
public:
    InsufficientFunds() : runtime_error("Withdrawal exceeds account balance.") {}
};
class BankAccount {
    double balance;
public:
    explicit BankAccount(double initialBalance) : balance(initialBalance) {}
    void withdraw(double amount) {
        if (amount <= 0) throw invalid_argument("Withdrawal must be positive.");
        if (amount > balance) throw InsufficientFunds();
        balance -= amount;
    }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount account(500);
    try {
        account.withdraw(600);
    } catch (const InsufficientFunds& error) {
        cerr << error.what() << '\n';
    }
    cout << "Balance: " << account.getBalance() << '\n';
}
