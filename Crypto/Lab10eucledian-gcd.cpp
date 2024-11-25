#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    
    do
    {
        int a, b;
        cout << "Enter the value of a: ";
        cin >> a;
        cout << "Enter the value of b: ";
        cin >> b;
        cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;

        cout << "Do you want to continue? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
            break;
        cin.ignore();
    } while (true);
    cout << "\nLab No.6\nName: Sabin Sapkota\nRoll no: 12 \n";
    return 0;
}
