Homework 1 - HW01
Professor: Dr. Sirong Lin
Student: Patricia Antlitz
Student ID: 02026785
COMP-2010 - Computing III - UMASS Lowell

Guess What Number Game.

This program generates a guessing game in which the player will guess which secret number was selected by the program.

Technology used:
C++

Source used:
No external source used, but a similar project was previously developed by me using Java.
The project can be found at: https://github.com/patybn3/Guess_What_Number_JAVA
I did not use the code as a source though.

Requirements and User Stories:

- The player should be able to enter a minimum and a maximum number to use as a range. The minimum number must be equal or greater than 1, and less than 1000.
- The player should be able to select how many rounds the game will have, as long as it is less or equal to 10 rounds.
- The program should validate the inputs are within the correct ranges.
- This number should not be allowed to be changed once the game starts.
- The program should generate a random number within the minimum and maximum ranges, which will be used as the number to be guessed.
- The player should be able to guess the amount of times selected for the rounds.
- The game should give the player hints; if the secret number is greater or lower than the guesses number.
- If the player is not able to guess the correct number, the program should print what the number was.
- if the player guesses correctly, the game will congratulate the player.
- The player should be offered to play again.

Features added by me (not required):

- The program will also have a minimum rounds the player is allowed to play (2).
- The maximum number for the range will be less or EQUAL to 1000.
- The program forces the player to select at least 12 numbers as the range.
- The program will print a "menu" with instructions.
- Validates if guessed number is within the given range
- Accumulates scores. Player X Computer.
- Picks the winner.
- Uses pass-by-reference to update values
- I kept as much code as I could in separate methods (I don't like busy main functions')
- the program will take a round number, and the minimum and maximum numbers (all three number) BEFORE it checks if the entries are valid. This is not a bug.

Inputs/Intakes:

- You can assume that only integers will be entered through the keyboard.
(this means that this program is not checking for entries that are not a number. Pressing other keys on the keyboard will break the program.)

Pseudo Code:

//declare libraries
//use namespace for std
//declare function prototypes at the top of the program
//will initially need the following variables: minimum number, maximum number, random number, number of rounds.
//create a method to get the number of rounds
//check if the number entered is in between 2 and 10
//if not, let the user know they must enter a number between 2-10
//let the user select a minimum number and maximum number as a range according to the requirements
//ask the user to enter at least 12 numbers in the range
//if not, let the user know they need to pick enough numbers
//make program select a random number within the selected range
//once the game starts, check if the number guessed is within the range given
//if the number matches, the user gains a point
//store the point in a variable to increase it
//allow the user to guess "round number" of times.
//if the user is out of guesses and the number does not match, the computer gets a point
//give the player a hint every time a guess is incorrect, letting them know if the number is higher or lower than the number guessed
//allow the player to play again

Methods:

main() -> contains the following variables:
    roundNum, minNum, maxNum, playerScore, computerScore, all initiated as 0
    calls the following methods:
    printMenu()
    generateDate(uses all mentioned variables as arguments for its parameters)
    
printMenu() -> outputs instructions

generateData(int &playerScore, int &computerScore, int &roundNum, int &minNum, int &maxNum) -> gets user's entries, generates a random number, calls the function that starts the game (playGame(...)). 
    Parameters:
    playerScore -> only used to be passed to playGame(...)
    computerScore -> only used to be passed to playGame(...)
    roundNum -> gets the value from the user.
    minNum -> gets the value from the user.
    maxNum -> gets the value from the user.
    randomNum -> generates a random number.
    calls
    setRoundsNum(roundNum)
    getRangeNums(minNum, maxNum)
    playGame(uses all mentioned variables as arguments for its parameters)
    
setRoundsNum(...) -> gets the number entered by the user from generateData(...) and uses to validate the entry

getRangeNums(...) -> gets the numbers entered by the user for the range, uses it to validate entries

playGame(int randomNumber, int &roundNum, int &minNum, int &maxNum, int &playerScore, int &computerScore) ->
get the user's entries to play the game

playAgain(...) -> allows the user to play the game again


Test the code:
- entered less than 2 or more than 10 for round to get an error and be prompted to enter again
- entered less than 1 or more than 1000 to get an error and be prompted to enter again
- entered a number outside of the selected range as a guess to get an error and be prompted to enter again
- pressed different numbers to continue the game (besides 0 and 1)


Academic Integrity Agreement:
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 01/28/2023
Name: Patricia Antlitz
*/
