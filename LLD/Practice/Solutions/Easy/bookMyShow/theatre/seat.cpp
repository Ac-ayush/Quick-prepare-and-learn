#include <bits/stdc++.h>
#include <seatCategory.cpp>
using namespace std;

class Seat
{
    int seatId;
    int row;
    SeatCategory* seatCategory;

public:
    int getSeatId(){
        return seatId;
    }

    void setSeatId(int seatId){
        this->seatId = seatId;
    }

    int getRow(){
        return row;
    }

    void setRow(int row){
        this->row = row;
    }

    SeatCategory* getSeatCategory(){
        return seatCategory;
    }

    void setSeatCategory(SeatCategory* seatCategory){
        this->seatCategory = seatCategory;
    }
};