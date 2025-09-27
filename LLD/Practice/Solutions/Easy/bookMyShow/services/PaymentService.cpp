#ifndef PAYMENTSERVICE_H
#define PAYMENTSERVICE_H

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class PaymentService
{
public:
    bool processPayment(double amount)
    {
        cout << "💳 Processing payment of ₹" << amount << "...";

        // Simulate success
        return true;
    }
};

#endif // PAYMENTSERVICE_H
