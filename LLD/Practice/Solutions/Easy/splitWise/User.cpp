#include <bits/stdc++.h>

using namespace std;
class User
{
    string userId;
    string name;
    string email;
    map<string, double> balanceSheet; // map of userId to balance

public:
    User(string id, string name, string email)
    {
        this->userId = id;
        this->email = email;
        this->name = name;
    }

    string getUserId()
    {
        return userId;
    }

    string getName() { return name; }

    double getBalanceWithUser(const string &userId) const
    {
        auto it = balanceSheet.find(userId);
        if (it != balanceSheet.end())
        {
            return it->second;
        }
        return 0.0;
    }

    void updateBalance(const string &userId, double amount)
    {
        balanceSheet[userId] += amount;
    }

    void displayBalances() const
    {
        cout << "Balance sheet for " << name << " (" << userId << "):\n";
        for (const auto &entry : balanceSheet)
        {
            cout << "  With " << entry.first << ": " << entry.second << "\n";
        }
    }

    void displayInfo()
    {
        cout << "User Name: " << name << " | " << "userId: " << userId << "):\n";
    }
};