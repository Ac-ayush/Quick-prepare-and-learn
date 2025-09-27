#include <bits/stdc++.h>
#include "services/BookingService.cpp"
using namespace std;

int main()
{
    // ✅ Singleton usage
    BookingService *bookService = BookingService::getInstance();
    bookService->initialize();
    bookService->startBookingSession();

    return 0;
}