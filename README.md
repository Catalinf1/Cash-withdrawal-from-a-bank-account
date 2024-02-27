# ATM Program
This is a C++ program that simulates an ATM (Automated Teller Machine) system. It allows users to perform basic banking operations, such as checking balance, withdrawing cash, showing user details, and updating mobile number.

## Features
- The program uses a Bank class that represents a bank account with some attributes and methods.

- The program prompts the user to enter their account number and verifies it with the Bank object.
- The program offers different options for the user to choose from, such as checking balance, withdrawing cash, showing user details, updating mobile number, or exiting the program.
- The program uses a switch statement to execute the corresponding actions based on the user’s choice.
- The program validates the user’s input and handles errors gracefully.

##Installation
To run this program, you need to have a C++ compiler installed on your machine. You can use any C++ compiler of your choice, such as GCC, Clang, or Visual Studio. You also need to clone this repository to your local machine using the following command:

`$ git clone https://github.com/Catalinf1/Cash-withdrawal-from-a-bank-account.git # Clone this repository`

##Usage
To compile and run this program, you need to navigate to the project directory and use the following command:

`$ g++ main.cpp -o atm # Compile the program
$ ./atm # Run the program`

The program will ask you to enter your account number and then display the available options. You can enter the number of the option you want to perform and follow the instructions. For example:

**** Welcome to ATM *****

Enter account number: 
Select options:
1. Check balance
2. Cash withdraw
3. Show user details
4. Update mobile number
5. Exit

To exit the program, you can enter 5 or press Ctrl+C.
