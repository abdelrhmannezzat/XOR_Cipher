/*
FCAI - Programming 1 - 2022 - Assignment 2
Program name: XOR Cipher
Purpose: Encryption and Decryption of messages using XOR Cipher
Author and ID and Group: abdelrhman mohamed ezzat 20210208 Group A
 */
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>
using namespace std;
bool program = true;
int hex_to_dec(string hexaText){ // Function to convert hexadecimal to decimal
    int base = 1;
    int dec = 0;
    for (int i = 1;i >= 0;i--){
        // loop over m and check value of each character and add it to its decimal equivalent
        if(hexaText[i] >= '0' && hexaText[i] <= '9'){
            dec += (hexaText[i] - 48) * base;
            base *= 16;
        }
        else if (hexaText[i] >= 'a' && hexaText[i] <= 'f'){
            dec += (hexaText[i] - 87) * base;
            base *= 16;
        }
    }
    return dec;
}
void cipher(string textToEncrypt,char secretLetter){
    // Function to encrypt the message,m is the string which the user entered and p is the secret letter
    string encryptedText = "";
    for (int i = 0;i < textToEncrypt.size();i++){
        char add = textToEncrypt[i] ^ secretLetter;
        encryptedText += add; // XOR each character with the secret letter
    }

    cout << "Ciphered text: " << encryptedText << endl;
    cout << "Ciphered in hexa: ";
    for (int i = 0;i < encryptedText.size();i++){
        if (int(encryptedText[i]) <= 15){
            cout << 0 << hex << int(encryptedText[i]);
            // If the number is less than or equal 15 then it will take one number only in hexa
            // So, I added zero at the beginning
        }
        else{
            cout << hex << int(encryptedText[i]);// Print the hexadecimal equivalent to the ciphered text
        }
    }
    cout << "\n";
}
void decipher(string textToDecrypt,char secretLetter,int operation){
    /*
     Function to decrypt the message,m is either in hexa or text, p is the secret letter
     and w to choose either you want to enter a hexadecimal value or text
     */
    string decryptedText = "";
    if (operation == 1){
        for (int i = 0;i < textToDecrypt.size();i++){
            decryptedText += (textToDecrypt[i] ^ secretLetter);
            // XOR each letter of the encrypted text to get the decrypted text
        }
    }
    else if (operation == 2){
        for (int i = 0;i < textToDecrypt.size();i += 2){
            string part = textToDecrypt.substr(i,2);
            // slice the string so that you can take each two hexadecimal characters as one number
            int dec = hex_to_dec(part);
            decryptedText += (char)(secretLetter ^ dec);
            // XOR the decimal(ASCII) value of encrypted text to get decrypted text
        }
    }
    cout << decryptedText << endl;
}
int main()
{   // program loop
    while(program){
        cout << "What do you want to do:\n";
        cout << "1: Cipher code\n";
        cout << "2: Decipher code\n";
        cout << "3: End\n";
        int num;cin >> num; // Choose what you want to do.

        if (num == 1){
            char secretLetter;cout << "Enter the secret key: ";
            cin >> secretLetter; // Enter the secret key which will be used in XOR cipher later.
            cout << "\nEnter the message you want to encrypt:";
            string text;
            cin.ignore();
            getline(cin,text,'\n');
            cout  << "\n";
            cipher(text,secretLetter);
        }
        else if(num == 2){
            char secretLetter;cout << "Enter the secret key: ";
            cin >> secretLetter; // Enter the secret key which will be used in XOR decipher later.
            int w;
            cout << "1: Decipher message using text\n";
            cout << "2: Decipher message using hexa\n";
            cin >> w;
            cout << "\nEnter the message you want to decrypt:";
            string text;
            cin.ignore();
            getline(cin,text,'\n');
            decipher(text,secretLetter,w);
        }
        else if (num == 3){
            cout << "\nThe program ends.";
            break;
        }
        else{ // defensive to make sure that the user entered a valid number
            cout << "\n Please enter a valid number";
        }
    }

    return 0;
}
