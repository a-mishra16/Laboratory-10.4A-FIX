/*
* Program: Laboratory 10-4A.cpp
* Author: Aanika Mishra
* Date: 11-13-2024
* Description: Program reads in a card number as an integer,
* puts it in an array and determines if it is valid or not
*/




#include <iostream>




using namespace std;
bool isCardValid(int digits[], int size);




int main()
{
    int nums[9];
    int card_num;
    int count = 0;
    bool done = false;


    while (!done)
    {
        cout << "Please insert 8-digit card number or Q to Quit: ";
        cin >> card_num;


        if (cin.fail())
        {
            done = true;
            break;
        }


        for (int i = 0; i < 8; i++)
        {
            nums[8 - i] = card_num % 10;
            card_num /= 10;
            count++;
        }




        if (isCardValid(nums, count) == true)
        {
            cout << "Card is Valid." << endl;
        }
        else
        {
            cout << "Card is Invalid." << endl;
        }
    }









}




bool isCardValid(int digits[], int size)
{
    int sum1 = 0;
    int sum2 = 0;
    int dub;




    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            sum1 += digits[size - i];
        }
        else
        {
            dub = digits[size - i] * 2;
            sum2 += (dub % 10) + (dub / 10);
        }
    }
    if ((sum1 + sum2) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}