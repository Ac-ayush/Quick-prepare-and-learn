#include <bits/stdc++.h>
using namespace std;

enum class ExpenseType
{
    EQUAL,
    EXACT,
    PERCENT
};

class Expense
{
    string expenceId;
    string paidBy;
    string description;
    double totalAmount;
    ExpenseType expenseType;
    vector<string> involvedUsers;
    map<string, double> shares; // userId-> shared amount for this expense

public:
    Expense(const string &id, const string &description, const string &paidBy, double amount, ExpenseType type, const vector<string> &users)
    {
        this->expenceId = id;
        this->paidBy = paidBy;
        this->totalAmount = amount;
        this->expenseType = type;
        this->involvedUsers = users;
        this->description = description;

        if (expenseType == ExpenseType::EQUAL)
        {
            calculateEqualShares();
        }
    }

    string getExpenseId() { return expenceId; }

    string getPaidBy() { return paidBy; }

    auto getShares() { return shares; }

    vector<string> getParticipants()
    {
        return involvedUsers;
    }

    void setShares(map<string, double> &share)
    {
        this->shares = share;
    }

    void calculateEqualShares()
    {
        double splitAmount = totalAmount / involvedUsers.size();

        for (auto &user : involvedUsers)
        {
            shares[user] = splitAmount;
        }
    }

    void displayInfo()
    {
        cout << "Expense ID: " << expenceId << "\n";
        cout << "Paid by: " << paidBy << "\n";
        cout << "description: " << description << "\n";
        std::cout << "Expense Type: ";
        switch (expenseType)
        {
        case ExpenseType::EQUAL:
            std::cout << "Equal";
            break;
        case ExpenseType::EXACT:
            std::cout << "Exact";
            break;
        case ExpenseType::PERCENT:
            std::cout << "Percent";
            break;
        }
        cout << "Total Amount: " << totalAmount << "\n";
        cout << "Involved Users: ";
        for (const auto &user : involvedUsers)
        {
            cout << user << " ";
        }
        cout << "\n";
        cout << "Shares: ";
        for (auto &share : shares)
        {
            cout << share.first << ": $" << fixed << setprecision(2) << share.second << endl;
        }
    }
};