#include <bits/stdc++.h>
#include "User.cpp"
#include "Expense.cpp"
using namespace std;

class SplitwiseSystem
{

    vector<User *> users;
    vector<Expense *> expenses;
    int userIdCounter;
    int expenseIdCounter;

public:
    SplitwiseSystem()
    {
        userIdCounter = 1;
        expenseIdCounter = 1;
    }

    // Register User
    User *registerUser(string name, string email)
    {
        auto userId = generateUserId();
        User *user = new User(userId, name, email);
        users.push_back(user);
        return user;
    }

    Expense *addExpense(string description, string paidBy, double amount, vector<string> &involvedUsers, ExpenseType type = ExpenseType::EQUAL)
    {
        if (!findUser(paidBy))
            return nullptr;

        string expenseId = generateExpenseId();
        Expense *expense = new Expense(expenseId, description, paidBy, amount, type, involvedUsers);
        expenses.push_back(expense);

        if (type == ExpenseType::EQUAL)
        {
            settleExpense(expenseId);
        }

        return expense;
    }

    void settleExpense(string expenseId)
    {
        Expense *expense = findExpense(expenseId);
        if (!expense)
            return;

        const string &paidBy = expense->getPaidBy();
        const auto &shares = expense->getShares();

        for (const auto &share : shares)
        {
            if (share.first != paidBy)
            {
                // Update balances for both users
                User *payer = findUser(paidBy);
                User *participant = findUser(share.first);

                if (payer && participant)
                {
                    payer->updateBalance(share.first, share.second);
                    participant->updateBalance(paidBy, -share.second);
                }
            }
        }
    }

    void showAllBalances() const
    {
        cout << "\nAll Balances:" << endl;
        for (const auto &user : users)
        {
            user->displayBalances();
        }
    }

    bool setExpenseShares(string expenseId, map<std::string, double> &shares)
    {
        Expense *expense = findExpense(expenseId);
        if (!expense)
            return false;

        expense->setShares(shares);
        settleExpense(expenseId);
        return true;
    }

    void displayUserExpenses(const std::string &userId) const
    {
        User *user = findUser(userId);
        if (!user)
            return;

        std::cout << "\nExpenses for " << user->getName() << ":" << std::endl;
        for (const auto &expense : expenses)
        {
            if (expense->getPaidBy() == userId ||
                std::find(expense->getParticipants().begin(),
                          expense->getParticipants().end(),
                          userId) != expense->getParticipants().end())
            {
                expense->displayInfo();
                std::cout << "------------------------" << std::endl;
            }
        }
    }

    void displayExpenses() const
    {
        cout << "\nAll Expenses:" << endl;
        for (const auto &expense : expenses)
        {
            expense->displayInfo();
            cout << "------------------------" << endl;
        }
    }
    
    //*************************************************Helpers*************************************************//

    string generateUserId()
    {
        return "U" + to_string(userIdCounter++);
    }

    string generateExpenseId()
    {
        return "E" + to_string(expenseIdCounter++);
    }

    User *findUser(const std::string &userId) const
    {
        auto it = find_if(users.begin(), users.end(),
                          [userId](User *user)
                          { return user->getUserId() == userId; });
        return it != users.end() ? *it : nullptr;
    }
    Expense *findExpense(const std::string &expenseId) const
    {
        auto it = std::find_if(expenses.begin(), expenses.end(),
                               [expenseId](Expense *expense)
                               { return expense->getExpenseId() == expenseId; });
        return it != expenses.end() ? *it : nullptr;
    }

    void displayUsers() const
    {
        std::cout << "\nRegistered Users:" << std::endl;
        for (const auto &user : users)
        {
            user->displayInfo();
            std::cout << "------------------------" << std::endl;
        }
    }
};