#include <bits/stdc++.h>
#include "BookingService.cpp"
using namespace std;

int main() {
    // ✅ Singleton usage
    BookingService* bookService = BookingService::getInstance();
    bookService->initialize();
    bookService->startBookingSession();

    return 0;
}