/*
 main.cpp
 Antlitz_Patricia_HW01_GuessNumber
 */

/**
 Created by Patricia Antlitz on 1/28/23.
 Comp III - UML
 Spring 2023
 
 Purpose: This is a guessing game developed in C++. The purpose of this game is to allow the player to guess numbers. The player will pick two numbers between 1-1000 as a range for the guess game. The user will also be prompt to enter the amount of rounds desired for the game. The program will then randomly select a number in this range so the user can make a guess. It will then give the player hints until the rounds are over or the player guesses the correct number.
 
 Sources of Help: I did now use any sources for this, but I have developed a similar game in java which can be found at
 https://github.com/patybn3/Guess_What_Number_JAVA/blob/main/GuessWhatNumber_PatriciaAntlitz.java
 
 *Problems encountered with be available in the README documentation
 
 Time Spent: Around 6 hours
 **/

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

//libraries used
#include <iostream>         //  I/O
#include <cstdlib>          //  for the random number
#include <ctime>            //  random number seed
using namespace std;

//Function Prototypes
void printMenu();
void generateData(int& playerScore, int& computerScore, int& roundNum, int& minNum, int& maxNum);
void playAgain(int userSelection, int& playerCore, int& computerScore, int& roundNum, int& minNum, int& maxNum);
void playGame(int randomNumber, int& roundNum, int& minNum, int& maxNum, int& playerScore, int& computerScore);

//I prefer to keep the main function as small as I can, only with the extremely necessary calls
int main(int argc, const char * argv[])
{
    /*
     this are the values that will be passed as reference to the following methods:
     generateData(...) -> gets the user inputs for the range of numbers and the number of rounds. It generated the random number and called the following function:
     playGame(...) -> has the game logic
     playAgain(...) -> calls generateData(...) if the player wants to play again, or quits the game
     */
    int playerScore = 0;
    int computerScore = 0;
    //range numbers
    int minNum = 0;
    int maxNum = 0;
    //number of rounds
    int roundNum = 0;
    
    printMenu();
    /*
     the reason why I put the code that would normally go here (not up to my standards, but the usual) is because this method
     is called more than once somewhere else in the code.
     This method is the one taking the user's input for the rounds, and range of numbers. It also generated the random number
     */
    generateData(playerScore, computerScore, roundNum, minNum, maxNum);
    
    return 0;
}

//instructions method
void printMenu()
{
    cout << "-----------------------------Guess What Number------------------------------" << endl;
    cout << "Description:" << endl;
    cout << "This is a guessing number game in which you (the player) will be prompted " << endl <<
    "to pick the numbers of rounds you would like to play, and the range of " << endl <<
    "numbers to guess." << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl << "Rules:" << endl;
    cout << "-\tThe number of rounds must be between 2 and 10, being 2 the minimum number " << endl <<
    " \tof rounds that can be played, and 10 the maximum." << endl;
    //the program will not allow the user to select a range smaller than the number of rounds. I am the computer player, kind of, and I plan to win!
    cout << "-\tThe minimum number you can select for a range is 1, and the maximum is 1000." << endl <<
    "-\tYour range of numbers must have at least 12 numbers in it." << endl;
    cout << "Good Luck!" << endl;
}

//Function declarations. The following two functions are called inside of the generateData(...) method.
/*
 allow the user to pick the number of rounds, less than 10 rounds, more than 2.
 parameter roundNum is coming from the method generateData(...) which initiates is as a variable, and reads its value from the
 keyboard.
 */
void setRoundsNum(int &roundNum)
{
    //reading from roundNum
    while(cin)
    {
        //validate inputs to follow requirements. Is round number greater or equal to 2 and less or equal to 10?
        if(roundNum < 2 || roundNum > 10)
        {
            cerr << "Error! Please enter a number between 2 and 10 as the number of rounds: ";
            //will get a round number from the user again
            //passing by reference will allow roundNum to be updated with the new entry
            cin >> roundNum;
        }
        else
        {
            break;
        }
    }
}

/*
 allow the player to pick a minimum number for the range starting at 1
 allow the player to pick a max number up to 1000 *even though the instructions say "less than 1000"
 **I will allow the player to enter less or equal to 1000. I find it strange to ask them to enter 999 as the highest number.**
 */
void getRangeNums(int &minNum, int &maxNum)
{
    //this method is being called inside of generateData(...), the minNum and maxNum parameters are keyboard intakes, that is why this while loop is checking cin as condition
    while(cin)
    {
        //validate inputs to follow requirements. Is the min number greater or equal to 1?
        if(minNum < 1)
        {
            //if not, the user will be informed they must enter a number >= to 1
            cerr << "Error! Your minimum number must be greater or equal to 1: ";
            cin >> minNum;
        }
        //validate inputs to follow requirements. Is the max number less or equal to 1000?
        else if(maxNum > 1000)
        {
            //if not, the user will be informed they must enter a number <= 1000
            cerr << "Error! Your maximum number must be less or equal to 1000: ";
            cin >> maxNum;
        }
        
        //once we get the right range, we can calculate the difference between the two ranges to check if its less than 12
        int totalRange = maxNum - minNum;
        //if the range between the min number and the max number is less than 12, ask the user to enter the range again
        if(totalRange < 11)
        {
            /*
             ideally, I would cap the range based on the amount of rounds selected (ex.: if the player selected 2-4 rounds,
             the minimum range number would be 6, if the player selected 5-10 the range would be 12. I don't think it's
             necessary for me to go there for this specific assignment.
             */
            cerr << endl << "Error! The range of numbers cannot be less than 12." << endl;
            cout << endl << "Enter the minimum number for the range: ";
            cin >> minNum;
            cout << "Enter the maximum number for the range: ";
            cin >> maxNum;
        }
        else
        {
            //we are out of this loop
            break;
        }
    }
}

//the purpose of this function is to get the user's inputs for the numbers used to generate the game
//this method also calls other methods in order to provide them with the values required by their parameters
void generateData(int &playerScore, int &computerScore, int &roundNum, int &minNum, int &maxNum)
{
    //number picked by the program
    int randomNumber = 0;
    
    cout << endl << "Enter the number of rounds: ";
    cin >> roundNum;
    cout << "Enter the minimum number for the range: ";
    cin >> minNum;
    cout << "Enter the maximum number for the range: ";
    cin >> maxNum;
    
    //sets the number of rounds
    setRoundsNum(roundNum);
    //sets the range of the numbers
    getRangeNums(minNum, maxNum);
    
    //random number seed
    srand(static_cast<unsigned>(time(NULL)));
    //generate a random number from minimum to max range
    randomNumber = minNum + (rand() % maxNum);
    //this call is here in case you want to see what number was generated by the program:
    //cout << "Random number generated: " << randomNumber << endl;
    
    //this is the methods that will check if the user's entry match the random number
    playGame(randomNumber, roundNum, minNum, maxNum,playerScore, computerScore);
    
}

//player guess the number x amount of times (rounds times)
//this method will update the values of playerScore, computerScore
void playGame(int randomNumber, int &roundNum, int &minNum, int &maxNum, int &playerScore, int &computerScore)
{
    //user keyboard entry
    int userSelection;
    //used for the loop
    
    cout << "\n\n---------------------------------------START---------------------------------------" << endl;
    cout << endl << "Player = " << playerScore << "\t X \tComputer = " << computerScore << endl << endl;
    
    //according to the requirements, roundNum will be greater than 0, so this loop will always run
    while(roundNum > 0)
    {
        cout << "Guess a number: " << endl;
        cin >> userSelection;
        
        //in case the user enters a number outside of the range
        if(userSelection < minNum || userSelection > maxNum)
        {
            cerr << endl << "Error! You must select a number within your selected range." << endl << endl;
            //this selection counts towards the rounds, so I am adding 1 to the round total, so the player does not loose a turn
            roundNum += 1;
        }
        else
        {
            //if the user guesses the correct number:
            if(userSelection == randomNumber)
            {
                //players wins, record score, ask if they want to play again, or quit.
                cout << endl << "WINNER!" << endl << "You guessed correctly!" << endl;
                playerScore++;
                //prints the score
                cout << endl << "Player = " << playerScore << "\t X \tComputer = " << computerScore << endl << endl;
                //I placed this to proof there is not bug
                cout << "Mystery number: " << randomNumber << endl;
                
                cout << "Press 1 to play again or 0 to quit the game: " << endl;
                cin >> userSelection;
                //this method will either quit the game, or call the function generateData(...) to reset the values and call this method again
                playAgain(userSelection, playerScore, computerScore, roundNum, minNum, maxNum);
            }
            //requirement: if guess is greater than the random number, give a hint
            else if(userSelection > randomNumber)
            {
                //hint: the random number is smaller
                cout << endl << "Incorrect Guess." << endl << "HINT: The mystery number is smaller than " << userSelection << endl << endl;
            }
            //requirement: if guess if smaller than the random number
            else if(userSelection < randomNumber)
            {
                cout << endl << "Incorrect Guess." << endl << "HINT: The mystery number is greater than " << userSelection << endl << endl;
            }
        }
        //decrease to down to 0 to stop loop
        roundNum--;
        
        //when it does reach 0, and the player didn't win, the game will announce the computer as the winner
        if(roundNum == 0 && userSelection != randomNumber)
        {
            cout << endl << "GAME OVER! You guessed incorrectly!" << endl;
            cout << "Computer Wins." << endl;
            //increase computer's score
            computerScore++;
            //prints scores
            cout << endl << "Player = " << playerScore << "\t X \tComputer = " << computerScore << endl << endl;
            //will let the player know what the random number was
            cout << "Mystery number: " << randomNumber << endl;
            //player can play again
            cout << endl << "Press 1 to play again or 0 to quit the game: " << endl;
            cin >> userSelection;
            
            playAgain(userSelection, playerScore, computerScore, roundNum, minNum, maxNum);
        }
    }
}

//either starts a new game, or quits the program
void playAgain(int userSelection, int &playerScore, int &computerScore, int& roundNum, int& minNum, int& maxNum)
{
    while(cin)
    {
        //if the user selects 1, a new game will start
        if(userSelection == 1)
        {
            generateData(playerScore, computerScore, roundNum, minNum, maxNum);
        }
        else if(userSelection == 0) //if the user selects 0
        {
            if(playerScore > computerScore) //the program will check if the user is the winner to print the final scores
            {
                cout << endl << "You are the winner with " << playerScore << " point(s)!" << endl;
            }
            else if(playerScore == computerScore) //if its a tie
            {
                cout << endl << "Its a tie!" << endl;
                cout << endl << "Player = " << playerScore << "\t X \tComputer = " << computerScore << endl << endl;
            }
            else //or if the computer is the winner
            {
                cout << endl << "The computer is the winner with " << computerScore << " point(s)!" << endl;
            }
            cout << "Goodbye!" << endl << endl;
            //ends the program
            exit(0);
        }
        else
        {
            //any other entry will tell the user to enter again
            cerr << "Incorrect answer. Please enter 1 to play again, or 0 to quit the game." << endl;
            cin >> userSelection;
        }
    }
}
