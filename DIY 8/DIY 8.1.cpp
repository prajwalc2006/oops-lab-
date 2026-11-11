#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account {
public:
    virtual double calculateInterest() const = 0;
    virtual ~Account() = default;
};
class Savings : public Account {
    double balance;
public:
    explicit Savings(double amount) : balance(amount) {}
    double calculateInterest() const override { return balance * 0.05; }
};
class Current : public Account {
    double balance;
public:
    explicit Current(double amount) : balance(amount) {}
    double calculateInterest() const override { return balance * 0.02; }
};

int main() {
    vector<unique_ptr<Account>> accounts;
    accounts.push_back(make_unique<Savings>(1000));
    accounts.push_back(make_unique<Current>(1000));
    for (const auto& account : accounts)
        cout << "Interest: " << account->calculateInterest() << '\n';
}
