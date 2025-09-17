#include <bits/stdc++.h>
using namespace std;

enum class ExpenseType {
    EQUAL,
    EXACT,
    PERCENT
};

class Expense {
    string expenceId;
    string paidBy;
    double totalAmount;
    ExpenseType expenseType;
    vector<string> involvedUsers;

public:
    Expense(const string& id, const string& paidBy, double amount, ExpenseType type, const vector<string>& users){
        this->expenceId = id;
        this->paidBy = paidBy;
        this->totalAmount = amount;
        this->expenseType = type;
        this->involvedUsers = users;
    }

    // void calculateAndDisplaySplit() {
    //     cout << "Expense ID: " << expenceId << "\n";
    //     cout << "Paid by: " << paidBy << "\n";
    //     cout << "Total Amount: " << totalAmount << "\n";
    //     cout << "Involved Users: ";
    //     for (const auto& user : involvedUsers) {
    //         cout << user << " ";
    //     }
    //     cout << "\n";

    //     if (expenseType == ExpenseType::EQUAL) {
    //         double splitAmount = totalAmount / involvedUsers.size();
    //         cout << "Each user owes: " << splitAmount << "\n";
    //     } else if (expenseType == ExpenseType::EXACT) {
    //         // For simplicity, assuming exact amounts are provided in a fixed manner
    //         cout << "Exact amounts need to be specified separately.\n";
    //     } else if (expenseType == ExpenseType::PERCENT) {
    //         // For simplicity, assuming percentages are provided in a fixed manner
    //         cout << "Percentages need to be specified separately.\n";
    //     }
    // }
};