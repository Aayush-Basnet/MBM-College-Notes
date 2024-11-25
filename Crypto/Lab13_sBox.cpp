#include <iostream>
#include <bitset>
#include <string>
using namespace std;

const int S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};

bitset<4> S1Substitution(bitset<6> input){
    int row = (input[5] << 1) + input[0];                                     
    int col = (input[4] << 3) + (input[3] << 2) + (input[2] << 1) + input[1]; 
    int output = S1[row][col];                                                
    return bitset<4>(output);                                                 
}
int main(){
    do{
        string inputStr;
        cout << "Enter a 6-bit binary input: ";
        cin >> inputStr;
		if (inputStr.length() != 6){
            cout << "Input must be 6 bits long." << endl;
            return 1;
        }
       
        bitset<6> input(inputStr);
   
        bitset<4> output = S1Substitution(input);
        
        cout << "Input:  " << input << endl;
        cout << "Output: " << output << endl;
        char choice;
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
            break;
    } while (true);
    return 0;
}
