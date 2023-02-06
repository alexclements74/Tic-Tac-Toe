//Alex Clements
//April 18th, 2019
//Purpose: To make a fully function tic tac toe game
//Program: Dev C++ 5.11
//Data dictionary: playing = char used to determine whether the game is running or not, winsAI = the number of wins the player has against the AI, lossesAI =  the number of losses the player has against the AI, tiesAI =  the number of ties against the AI
//				   wins1 = the number of wins player 1 has, losses 1 =  the number of losses player 1 has, ties = the number of ties in the two player game, wins2 = the number of wins player 2 has, losses2 = number of losses player 2 has
//				   continueGame = what version the player wants to play and if they want to stop playing, board = array that holds the values for each spot on the board, gameStatus = char used to determine whether the specific version of the game is running
//				   value = what the user wants to play (X or O), otherValue = what the user doesn't want to play, userChoice = X or O, used in determining winner, notUserChoice = X or O, used in determining winner

//Getting libraries
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

string board[3][3]={{"","",""},{"","",""},{"","",""}};
int outputBoard();

//Starting program
int main()
{
	//Used in randomization
	srand(time(0));
	
	//Declaring variables
	char playing=true;
	int winsAI=0,lossesAI=0,tiesAI=0,wins1=0,losses1=0,ties=0,wins2=0,losses2=0;
	
	//Outputting greeting message to user 
	cout<<"Welcome to Tic Tac Toe! ";
	cout<<endl<<"In order to play, you will type the number that is displayed with what you are inputting. \n(Vertical, Horizontal) (1 1),(2 2),(3 3), etc. ";
	
	//While loop that goes for as long as the user is playing
	while(playing)
	{
	
	//Declaring variables
	string continueGame="1";
	string board[3][3]={{"","",""},{"","",""},{"","",""}};
	char gameStatus=true;
	string value,otherValue;
	string userChoice,notUserChoice;
    	int valuesInputted=0,pos1,pos2,i,randPos1,randPos2;
	
	//Asking user what type of game they want to play or if they want to stop and taking in that answer
	cout<<endl<<"\nWould you like to do a one player, two player game or stop? (1/2/Stop) --> ";
	cin>>continueGame;	
	
	//While loop that goes until the user wants to stop playing the one person game
	while(continueGame=="1")
	{
		//Outputting board
		outputBoard();
		
		//Asking for user input of the X/O and taking in value
		cout<<endl<<"Are you X or O? (X/O) --> ";
		cin>>value;
		
		//Setting the choice as the value put in by user
		userChoice=value;
		
		//If the user chose X, sets what they didn't choose to O
		if(userChoice=="X")
		{
			notUserChoice="O";
		}
		
		//If the user chose O, sets what they didn't choose to X
		else if(userChoice=="O")
		{
			notUserChoice="X";
		}
	
		//Setting the 'otherValue' variable as the value that isn't what Player 1 has for the swap later
		if(value=="X")
		{
			otherValue="O";
		}
		
		else if(value=="O")
		{
			otherValue="X";	
		}
		
		//While loop that runs for as long as the user keeps putting input onto the board
		while(gameStatus)
		{
			
			
			//Asking user for where they want to go and taking in input
			cout<<endl<<"Where would you like to place an "<<value<<"? Remember, it's Vertical/Horizontal (Ex: 1 1 would be top left). ";
			cin>>pos1>>pos2;
			
			//While loop that goes if the position that the user selects is taken
			while(board[pos1-1][pos2-1]!="")
			{
				//Asking user for where they want to go again and taking in input
				cout<<endl<<"Something is already placed there. \nWhere would you like to place an "<<value<<"? (Ex: 1 1) ";
				cin>>pos1>>pos2;
			}	
			
			//Setting the position on the board with the value of the user's play
			board[pos1-1][pos2-1]=value;
			
			//Swaps the values so the AI places what the user doesn't
			swap(value, otherValue);
			
			//Adds 1 to the variable that holds how many things have been placed on the board
			valuesInputted++;
			
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"\t"<<board[0][0]<<"\t|\t"<<board[0][1]<<"\t|\t"<<board[0][2];
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"_________________________________________________";
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"\t"<<board[1][0]<<"\t|\t"<<board[1][1]<<"\t|\t"<<board[1][2];
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"_________________________________________________";
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"\t"<<board[2][0]<<"\t|\t"<<board[2][1]<<"\t|\t"<<board[2][2];
			cout<<endl<<"\t\t|\t\t|\t"<<endl;

			
			//Generating a random number between 1-3 for the position of the AI's placement
			randPos1=rand()%3+1;
			randPos2=rand()%3+1;
			
			//While loop that goes if the position that the AI generates is taken
			while(board[randPos1-1][randPos2-1]!="")
			{
				//Randomly generating numbers again
				randPos1=rand()%3+1;
				randPos2=rand()%3+1;
			}	
			
			//Setting the position on the board with the value of the AI's play
			board[randPos1-1][randPos2-1]=value;
			
			//Swaps the values so the user places what the AI doesn't
			swap(value, otherValue);
			
			//Adds 1 to the variable that holds how many things have been placed on the board
			valuesInputted++;
			
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"\t"<<board[0][0]<<"\t|\t"<<board[0][1]<<"\t|\t"<<board[0][2];
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"_________________________________________________";
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"\t"<<board[1][0]<<"\t|\t"<<board[1][1]<<"\t|\t"<<board[1][2];
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"_________________________________________________";
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"\t"<<board[2][0]<<"\t|\t"<<board[2][1]<<"\t|\t"<<board[2][2];
			cout<<endl<<"\t\t|\t\t|\t"<<endl;
			

			//For loop that checks each line vertically and horizontally using the if statments 
			for(i=0;i<3;i++)
			{
				//Each if statement checks a different way that the user or AI can win the game, tells the user, adds 1 to the appropriate counter, and changes 'gameStatus' and 'continueGame' to get out of the loops
				if(board[i][0]==userChoice&&board[i][1]==userChoice&&board[i][2]==userChoice&&gameStatus)
				{
					cout<<endl<<"You have won! ";
					winsAI++;
					gameStatus=false;
					continueGame="whatever";
			
				}
				
				else if(board[i][0]==notUserChoice&&board[i][1]==notUserChoice&&board[i][2]==notUserChoice&&gameStatus)
				{
					cout<<endl<<"The AI has won!";
					lossesAI++;
					gameStatus=false;
					continueGame="whatever";
			
				}
				
				else if(board[0][i]==userChoice&&board[1][i]==userChoice&&board[2][i]==userChoice&&gameStatus)
				{
					cout<<endl<<"You have won! ";
					winsAI++;
					gameStatus=false;
					continueGame="whatever";
				
				}
				
				else if(board[0][i]==notUserChoice&&board[1][i]==notUserChoice&&board[2][i]==notUserChoice&&gameStatus)
				{
					cout<<endl<<"The AI has won! ";
					lossesAI++;
					gameStatus=false;
					continueGame="whatever";
				
				}
			}
			
			//Each if statement checks a different way that the user or AI can win the game, tells the user, adds 1 to the appropriate counter, and changes 'gameStatus' and 'continueGame' to get out of the loops
			if(board[0][0]==userChoice&&board[1][1]==userChoice&&board[2][2]==userChoice&&gameStatus)
			{
				cout<<endl<<"You have won! ";
				winsAI++;
				gameStatus=false;
				continueGame="whatever";
			
			}
				
			else if(board[0][0]==notUserChoice&&board[1][1]==notUserChoice&&board[2][2]==notUserChoice&&gameStatus)
			{
				cout<<endl<<"The AI has won! ";
				lossesAI++;
				gameStatus=false;
				continueGame="whatever";
			
			}
				
			else if(board[2][0]==userChoice&&board[1][1]==userChoice&&board[0][2]==userChoice&&gameStatus)
			{
				cout<<endl<<"You have won! ";
				winsAI++;
				gameStatus=false;
				continueGame="whatever";
						
			}
			
			else if(board[2][0]==notUserChoice&&board[1][1]==notUserChoice&&board[0][2]==notUserChoice&&gameStatus)
			{
				cout<<endl<<"The AI has won! ";
				lossesAI++;
				gameStatus=false;
				continueGame="whatever";
		
			}
			//If the board has been filled and someone hasn't won
			else if(valuesInputted>=9&&continueGame!="whatever")
			{
				cout<<endl<<"It is a tie. ";
				ties++;
				gameStatus=false;
				continueGame="whatever"; 
			}	
				
			
		}
				
	}

	//While loop that runs until the user doesn't want to play a two player game
	while(continueGame=="2")
	{
		//Outputting board
		outputBoard();
	
		//Asking for user input of the X/O and taking in value
		cout<<endl<<"Is Player 1 X or O? (X/O) --> ";
		cin>>value;	
	
		//Setting the userChoice variable to what the user wants to play
		userChoice=value;
	
		//If the user chose X, sets what they didn't choose to O
		if(userChoice=="X")
		{
			notUserChoice="O";
		}
		
		//If the user chose O, sets what they didn't choose to X
		else if(userChoice=="O")
		{
			notUserChoice="X";
		}
	
		//Setting the 'otherValue' variable as the value that isn't what Player 1 has for the swap later
		if(value=="X")
		{
			otherValue="O";
		}
		
		else if(value=="O")
		{
			otherValue="X";	
		}
		
		//While loop that goes for as long as the players are inputting values
		while(gameStatus)
		{
			//Asking players for input and taking in where they want to place the value
			cout<<endl<<"Where would you like to place an "<<value<<"? Remember, it's Vertical/Horizontal (Ex: 1 1 would be top left). ";
			cin>>pos1>>pos2;
				
			//While loop that goes if the position that the AI generates is taken
			while(board[pos1-1][pos2-1]!="")
			{
				cout<<endl<<"Something is already placed there. \nWhere would you like to place an "<<value<<"? (Ex: 1 1) ";
				cin>>pos1>>pos2;
			}	
			
			//Setting the position on the board with the value of the player's play
			board[pos1-1][pos2-1]=value;
					
			//Swaps the values so player 1 places what player 2 doesn't	
			swap(value, otherValue);
			
			//Adds 1 to the variable that holds how many things have been placed on the board
			valuesInputted++;
			
			//Outputting board
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"\t"<<board[0][0]<<"\t|\t"<<board[0][1]<<"\t|\t"<<board[0][2];
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"_________________________________________________";
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"\t"<<board[1][0]<<"\t|\t"<<board[1][1]<<"\t|\t"<<board[1][2];
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"_________________________________________________";
			cout<<endl<<"\t\t|\t\t|\t";
			cout<<endl<<"\t"<<board[2][0]<<"\t|\t"<<board[2][1]<<"\t|\t"<<board[2][2];
			cout<<endl<<"\t\t|\t\t|\t"<<endl;
			
			//For loop that helps for checking winning scenarios
			for(i=0;i<3;i++)
			{
				//Each if statement checks a different way that the user or AI can win the game, tells the user, adds 1 to the appropriate counter, and changes 'gameStatus' and 'continueGame' to get out of the loops
				if(board[i][0]==userChoice&&board[i][1]==userChoice&&board[i][2]==userChoice&&gameStatus)
				{
					cout<<endl<<"Player one has won! ";
					wins1++;
					losses2++;
					gameStatus=false;
					continueGame="whatever";
			
				}
				
				else if(board[i][0]==notUserChoice&&board[i][1]==notUserChoice&&board[i][2]==notUserChoice&&gameStatus)
				{
					cout<<endl<<"Player two has won! ";
					wins2++;
					losses1++;
					gameStatus=false;
					continueGame="whatever";
			
				}
				
				else if(board[0][i]==userChoice&&board[1][i]==userChoice&&board[2][i]==userChoice&&gameStatus)
				{
					cout<<endl<<"Player one has won! ";
					wins1++;
					losses2++;
					gameStatus=false;
					continueGame="whatever";
				
				}
				
				else if(board[0][i]==notUserChoice&&board[1][i]==notUserChoice&&board[2][i]==notUserChoice&&gameStatus)
				{
					cout<<endl<<"Player two has won! ";
					wins2++;
					losses1++;
					gameStatus=false;
					continueGame="whatever";
				
				}
			}
			
			//Each if statement checks a different way that the user or AI can win the game, tells the user, adds 1 to the appropriate counter, and changes 'gameStatus' and 'continueGame' to get out of the loops
			if(board[0][0]==userChoice&&board[1][1]==userChoice&&board[2][2]==userChoice&&gameStatus)
			{
				cout<<endl<<"Player one has won! ";
				wins1++;
				losses2++;
				gameStatus=false;
				continueGame="whatever";
			
			}
				
			else if(board[0][0]==notUserChoice&&board[1][1]==notUserChoice&&board[2][2]==notUserChoice&&gameStatus)
			{
				cout<<endl<<"Player two has won! ";
				wins2++;
				losses1++;
				gameStatus=false;
				continueGame="whatever";
			
			}
				
			else if(board[2][0]==userChoice&&board[1][1]==userChoice&&board[0][2]==userChoice&&gameStatus)
			{
				cout<<endl<<"Player one has won! ";
				wins1++;
				losses2++;
				gameStatus=false;
				continueGame="whatever";
						
			}
			
			else if(board[2][0]==notUserChoice&&board[1][1]==notUserChoice&&board[0][2]==notUserChoice&&gameStatus)
			{
				cout<<endl<<"Player two has won! ";
				wins2++;
				losses1++;
				gameStatus=false;
				continueGame="whatever";
		
			}
			
			if(valuesInputted==9&&continueGame!="whatever"&&gameStatus)
			{
				cout<<endl<<"It is a tie. ";
				ties++;
				gameStatus=false;
				continueGame="whatever"; 
			}
		}
		
		
	}
	
	//If the user wants to stop playing the game
	if(continueGame=="Stop")
	{
		//Exits playing loop and ends program
		playing=false;
	}
	
	}
	
	//Outputting ending results of the game
	cout<<endl<<"Thanks for playing.";
	cout<<endl<<"In the one player games, you finished with "<<winsAI<<" wins, "<<lossesAI<<" losses and "<<tiesAI<<" ties.";
	cout<<endl<<"In the two player games, player 1 finished with "<<wins1<<" wins, "<<losses1<<" losses and "<<ties<<" ties.";
	cout<<endl<<"Player 2 finished with "<<wins2<<" wins, "<<losses2<<" losses and "<<ties<<" ties. ";
}

int outputBoard()
{
		cout<<endl<<"\t\t|\t\t|\t";
		cout<<endl<<"\t"<<board[0][0]<<"\t|\t"<<board[0][1]<<"\t|\t"<<board[0][2];
		cout<<endl<<"\t\t|\t\t|\t";
		cout<<endl<<"_________________________________________________";
		cout<<endl<<"\t\t|\t\t|\t";
		cout<<endl<<"\t"<<board[1][0]<<"\t|\t"<<board[1][1]<<"\t|\t"<<board[1][2];
		cout<<endl<<"\t\t|\t\t|\t";
		cout<<endl<<"_________________________________________________";
		cout<<endl<<"\t\t|\t\t|\t";
		cout<<endl<<"\t"<<board[2][0]<<"\t|\t"<<board[2][1]<<"\t|\t"<<board[2][2];
		cout<<endl<<"\t\t|\t\t|\t"<<endl;
}
