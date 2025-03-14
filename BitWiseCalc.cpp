// Boulgourjian, Shiraz                  CS130 Section --27623-- Date Completed: 9/12/2024
// First Laboratory Assignment - Bitwise Operation Calculator



#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    char choice = 0;  // Initialize 'choice' outside of the loop

    do {
        int op1 = 0, op2 = 0, res = 0;  // Initialize variables to avoid garbage values
        unsigned long long max_value = 18446744073709551615ULL;

        // Display menu options
        cout << "\nEnter one of the following choices:" << endl;
        cout << "& - AND" << endl;
        cout << "| - OR" << endl;
        cout << "^ - XOR" << endl;
        cout << "~ - NOT" << endl;
        cout << "- - Negate" << endl;
        cout << "< - Left Shift (logical shift only)" << endl;
        cout << "> - Right Shift (logical shift only)" << endl;
        cout << "# - Stop execution" << endl;
        cin >> choice;  // Read the user's choice

        switch (choice) {
        case '&':
        cout <<"\nEnter values for first and second operand: ";
        cin >> op1 >> op2;

            if(op1 < 0 || op2 < 0 || cin.fail())  //we use cin.fail() as a METHOD of cin, this method basicall makes it to where our integers must be a possitive integer, meaning no negatives or letters 
            cout <<"Invalid choice, please try again\n"<<endl;

            else

            res = op1 & op2;

            if(res > max_value )
            cout <<"Input error, enter choice and values again\n"<<endl;

            else

            cout <<"Result: " << res <<" Hexidecimal: " << hex << res <<endl;
            break;

        case '|':
        cout <<"\nEnter values for first and second operand: ";
        cin >> op1 >> op2;

            if(op1 < 0 || op2 < 0 || cin.fail())
            cout <<"\nInvalid choice, please try again" <<endl;

            else

            res = op1 | op2;

            if(res > max_value)
            cout <<"Input error, enter choice and values again\n"<<endl;

            else

            cout <<"Result: " << res <<" Hexidecimal: " << hex << res <<endl;
            break;

        case '^':
        cout <<"\nEnter values for first and second operand: ";
        cin >> op1 >> op2;

            if(op1 < 0 || op2 < 0 || cin.fail())
            cout <<"\nInvalid choice, please try again" <<endl;

            else

            res = op1 ^ op2;

            if(res > max_value)
            cout <<"Input error, enter choice and values again\n"<<endl;

            else

            cout <<"Result: " << res <<" Hexidecimal: " << hex << res <<endl;
            break;
        
        case '~':
        cout << "\nEnter value for operand: ";
        cin >> op1;

            if(op1 < 0 || op2 < 0 || cin.fail())
            cout <<"\nInvalid choice, please try again" <<endl;

            else

            res = ~op1;

            if(res > max_value)
            cout <<"Input error, enter choice and values again\n"<<endl;

            else

            cout <<"Result: " << res <<" Hexidecimal: " << hex << res <<endl;
            break;

        case '-':
        cout << "\nEnter value for operand: ";
        cin >> op1;

            if(op1 < 0 || op2 < 0 || cin.fail())
            cout <<"\nInvalid choice, please try again";

            else

            res = -op1;

            if(res > max_value)
            cout <<"Input error, enter choice and values again\n"<<endl;

            else

            cout <<"Result: " << res <<" Hexidecimal: " << hex << res <<endl;
            break;

        case '<':
        cout <<"\nEnter values for first and second operand: ";
        cin >> op1 >> op2;

            if(op1 < 0 || op2 < 0 || cin.fail())
            cout <<"\nInvalid choice, please try again";

            else

            if (op2 > 63)
            cout << "\nShift value "<< op2 << " exceeds bit size 63" <<endl;

            else

            res = op1 << op2;
            cout <<"Result: " << res <<" Hexidecimal: " << hex << res <<endl;
            break;

        case '>':
        cout <<"\nEnter values for first and second operand: ";

            if(op1 < 0 || op2 < 0 || cin.fail())
            cout <<"\nInvalid choice, please try again";

            else

            if (op2 > 63)
            cout << "\nShift value "<< op2 << " exceeds bit size 63" <<endl;

            else

            res = op1 << op2;
            cout <<"Result" << res <<" Hexidecimal:" << hex << res <<endl;
            break;


        case '#':
        cout <<"\nCalculation Ended"<<endl;
        exit(0);

        } 

    

    } while (choice != '#');  // Loop until user enters '#'

    return 0;


}
