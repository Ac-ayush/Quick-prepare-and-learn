
#include <bits/stdc++.h>
#include "SplitSystem.cpp"
using namespace std;

int main()
{
    SplitwiseSystem splitwise;
    // *************Register Users*************//
    User *user1 = splitwise.registerUser("John", "john@email.com");
    User *user2 = splitwise.registerUser("Alice", "alice@email.com");
    User *user3 = splitwise.registerUser("Bob", "bob@email.com");

    cout << "Initital users: " << endl;
    splitwise.displayUsers();

    // *************Add expenses *************//

    // Equal Split Expense
    vector<string> participants = {user1->getUserId(), user2->getUserId(), user3->getUserId()};
    Expense *dinner = splitwise.addExpense("Dinner", user1->getUserId(), 300.0, participants, ExpenseType::EQUAL);

    // Custom split (EXACT)
    vector<string> movieParticipants = {user1->getUserId(), user2->getUserId()};
    Expense *movie = splitwise.addExpense("Movie", user2->getUserId(), 100.0,
                                          movieParticipants, ExpenseType::EXACT);
    map<string, double> movieShares = {
        {user1->getUserId(), 60.0},
        {user2->getUserId(), 40.0}
    };
    splitwise.setExpenseShares(movie->getExpenseId(), movieShares);


    // *************Display expenses *************//
    // Display expenses
    cout << "\nAll expenses:" << endl;
    splitwise.displayExpenses();
    
    // Show balances
    cout << "\nBalances after expenses:" << endl;
    splitwise.showAllBalances();
    
    // Show individual expenses
    cout << "\nJohn's expenses:" << endl;
    splitwise.displayUserExpenses(user1->getUserId());



    return 0;
}
