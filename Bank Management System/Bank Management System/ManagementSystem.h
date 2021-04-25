#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "boolean.h"
#include "time_date.h"

#define MAX_NAME 80
#define MAX_PHONE_NUMBER 8

#pragma region BANK ACCOUNT MANAGEMENT SYSTEM
void MainMenu();
// Create new account
void CreateNewAccount();
// Update information of existing account 
void UpdateAccountInfo();
// For transactions
void Transaction();
// Check detail of existing account
void CheckAccountDetails();
// Remove existing account 
void RemoveAccount();
// View customer list
void ViewCustomers();
// Using this function to reset everything back to normal
void Reset();
#pragma endregion
#pragma region USER RELATED FUNCTIONS
// Get user input and convert it into an int
char* GetUserInput();
// Check if there are any special characters in the name
boolean CheckName(char name[]);
// Check the length of the string
int CheckStringLength(char* str);
// Confirm input from user
boolean Confirmation(char* str1, char* str2);
#pragma endregion
#pragma region TIME RELATED FUNCTIONS
// Check if the date is a valid day
boolean CheckValidDate(int dd, int mm, int yyyy);
// Calculate the age of customer
int CalculateAge(int dd, int mm, int yyyy);
// Get int value of the month
int GetMonth(char mm[]);
#pragma endregion