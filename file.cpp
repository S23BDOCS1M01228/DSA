#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Friend {
private:
    string name;
    double balance;

public:
    Friend(string n) : name(n), balance(0.0) {}

    string getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    void addToBalance(double amount) {
        balance += amount;
    }
};

class BillSplitter {
private:
    vector<Friend> friends;

public:
    BillSplitter(int numFriends) {
        friends.reserve(numFriends);
        for (int i = 0; i < numFriends; ++i) {
            string name;
            cout << "Enter name of friend " << i + 1 << ": ";
            cin >> name;
            friends.emplace_back(name);
        }
    }

    void calculateBalance(const string& payer, const string& payee, double totalBill) {
        int numFriends = friends.size();
        double amountPerFriend = totalBill / numFriends;

        for (auto& friendObj : friends) {
            if (friendObj.getName() == payer) {
                friendObj.addToBalance(-totalBill);
            } else if (friendObj.getName() != payee) {
                friendObj.addToBalance(amountPerFriend);
            }
        }
    }

    void displayReport() {
        for (const auto& friendObj : friends) {
            cout << "Friend: " << friendObj.getName() << endl;
            if (friendObj.getBalance() > 0) {
                cout << "Needs to collect: " << friendObj.getBalance() << endl;
            } else if (friendObj.getBalance() < 0) {
                cout << "Needs to pay: " << -friendObj.getBalance() << endl;
            } else {
                cout << "No balance" << endl;
            }
        }
    }
};

int main() {
    int numFriends;
    cout << "Enter the number of friends: ";
    cin >> numFriends;

    BillSplitter billSplitter(numFriends);

    string payer, payee;
    double totalBill;
    cout << "Enter name of the payer: ";
    cin >> payer;
    cout << "Enter name of the payee: ";
    cin >> payee;
    cout << "Enter total amount of the bill: ";
    cin >> totalBill;

    billSplitter.calculateBalance(payer, payee, totalBill);
    billSplitter.displayReport();

    return 0;
}