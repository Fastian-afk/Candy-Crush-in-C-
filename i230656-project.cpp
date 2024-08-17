//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : (c) Reserved
// Description : 
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath>        // for basic math functions such as cos, sin, sqrt
#include <GL/glut.h> // Include the necessary header file for OpenGL
#include<ctime>
#include<cstdlib>

 
using namespace std;




// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {       
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
void LoadGameState(int numRows, int numColumns, int gems[][100], int score);
void SaveGameState(int numRows, int numColumns, int gems[][100], int score);
bool CheckIfAllGemsCleared(int numRows, int numColumns, int gems[][100]);
void NextLevel(int numRows, int numColumns, int gems[][100]); 
void Hint(int numRows, int numColumns, int gems[][100], bool highlightedGems[][100]);
void DrawPlayPauseButton();
void DrawGamePaused();
void DrawProgressBar(int progressBarWidth, int progressBarHeight, int progress);
void DrawGameBoard();
void CheckMatches(int numRows, int numColumns, int gems[][100]);
void DrawPlayerInfo(string playerName, int score, int level);
/*void SwapGems(int startRow, int startColumn, int endRow, int endColumn);*/
void DrawMenu();
/*void Menu(int value);
void StartGame();
void ExitGame();
void DrawGameOver();*/

int gems[100][100];
void GameDisplay()
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0 /* Red Component */, 0,						 // 148.0/255/Green Component/,
				 0.0 /* Blue Component */, 0 /* Alpha component */); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT);								 // Update the colors
	/*// Fire Gun
	DrawSquare( 400 , 20 ,40,colors[RED]);
	//Mushroom
	DrawSquare( 250 , 250 ,20,colors[GREEN]);
	//Display Score
	DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Spider
	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] );
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)*/
	int score = 0;
	int progressBarWidth = 200;
	int progressBarHeight = 20;
	int progress = 0; // Example progress value, you can replace this with your actual progress
	DrawProgressBar(progressBarWidth, progressBarHeight, progress);

	/*string playerName = playerName; // Example player name, replace with actual player name
	int score = 0; // Example score, replace with actual score
	int level = 5; // Example level, replace with actual level
	DrawPlayerInfo(playerName, score, level);*/
	
	int numRows = 8;								  // Number of rows in the game board
	int numColumns = 8;								  // Number of columns in the game board
	bool highlightedGems[100][100] = {};			  // Initialize highlighted gems array
	Hint(numRows, numColumns, gems, highlightedGems); // Call the Hint function

	if (CheckIfAllGemsCleared(numRows, numColumns, gems))
	{
		NextLevel(numRows, numColumns, gems);
	}

	
		DrawString(50, 800, "Score=0", colors[MISTY_ROSE]);
		int screenWidth = glutGet(GLUT_WINDOW_WIDTH);
		int screenHeight = glutGet(GLUT_WINDOW_HEIGHT);
		int gridSize = 8;
		int gemSize = 20;
		int gap = 5;
		int gridWidth = gridSize * (gemSize + gap);
		int gridHeight = gridSize * (gemSize + gap);
		int xOffset = (screenWidth - gridWidth) / 2;
		int yOffset = (screenHeight - gridHeight) / 2;
                int startRow;
                int startColumn;
                int endRow;
                int endColumn;
		string playerName;
		/*cout<<"Enter your name: ";
		cin>>playerName;*/
		int level = 1;
		int x, y;
                int value;
                
		DrawGameBoard();
		/*DrawMenu();
               Menu(value);
               StartGame();
               ExitGame();*/
		/*SwapGems(startRow, startColumn, endRow, endColumn);*/
		DrawPlayerInfo(playerName, score, level);
		/*DrawMenu();*/
		
		/*DrawPlayPauseButton();*/
		
		CheckMatches(gridSize, gridSize, gems); // Check for matches
		
		/*DrawGamePaused();*/
		
		/*LoadGameState(numRows, numColumns, gems, score);*/
		
               /*SaveGameState(numRows, numColumns, gems, score);*/
		
	       /*DrawGameOver();*/
		
	
	glutSwapBuffers(); // do not modify this line..
}


/*void StartGame() {
    cout << "Starting the game..." << endl;
    
    DrawGameBoard();
    
    
}

void ExitGame() {
    cout << "Exiting the game..." << endl;
    exit(0);
}*/	

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		
          cout << "Left arrow key pressed" << endl;
          
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
			cout << "Right arrow key pressed" << endl;

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
			cout << "Up arrow key pressed" << endl;

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
			cout << "Down arrow key pressed" << endl;

	}
	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	
	if (key == 's' || key == 'S') //Key for starting game
			{
		//do something if b is pressed
		cout << "s pressed" << endl;
	int numRows = 8;						           // Number of rows in the game board
	int numColumns = 8;							   // Number of columns in the game board
	bool highlightedGems[100][100] = {};	
		Hint(numRows, numColumns, gems, highlightedGems);
		

	}
	
	if (key == 'p' || key == 'P') //Key for exiting game
			{
		//do something if b is pressed
		cout << "p pressed" << endl;
		void DrawGamePaused();
		

	}
	
	
	
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	/*cout << x << " " << y << endl;
	glutPostRedisplay();*/
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
//	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y) {
	
	// Check which mouse button is pressed or released
    if (button == GLUT_LEFT_BUTTON) {
        // Dealing with the left button
        if (state == GLUT_DOWN) {
            // Left button pressed
            cout << "Left button pressed at position: (" << x << ", " << y << ")" << endl;
        } else if (state == GLUT_UP) {
            // Left button released
            cout << "Left button released at position: (" << x << ", " << y << ")" << endl;
        }
    } else if (button == GLUT_RIGHT_BUTTON) {
        // Dealing with the right button
        if (state == GLUT_DOWN) {
            // Right button pressed
            cout << "Right button pressed at position: (" << x << ", " << y << ")" << endl;
        } else if (state == GLUT_UP) {
            // Right button released
            cout << "Right button released at position: (" << x << ", " << y << ")" << endl;
        }
    }
	/*glutPostRedisplay();*/
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code 
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
/*void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}*/

    

void DrawGameBoard() {
    int gridSize = 15;
    int gemSize = 20;
    int gap = 5;
    int centerX = 500; // Middle x-coordinate
    int centerY = 500; // Middle y-coordinate

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            int x = centerX - (gridSize / 2) * (gemSize + gap) + j * (gemSize + gap);
            int y = centerY - (gridSize / 2) * (gemSize + gap) + i * (gemSize + gap);

            // Randomly select a gem type
            int gemType = rand() % 5;

            switch (gemType) {
                case 0: //  Draw a Round Rect
                    DrawRoundRect(x, y, gemSize, gemSize, colors[RED], 10);
                    break;
                case 1: // Draw a Square
                    DrawSquare(x, y, gemSize, colors[GREEN]);
                    break;
                case 2: // Draw a Triangle
                    DrawTriangle(x, y, x + gemSize, y, x + gemSize / 2, y + gemSize, colors[BLUE]);
                    break;
                case 3: // Draw a Line
                    DrawLine(x, y, x + gemSize, y, 2, colors[YELLOW]);
                    break;
                case 4: // Draw a Circle
                    DrawCircle(x + gemSize / 2, y + gemSize / 2, gemSize / 2, colors[PURPLE]);
                    break;
            }
        }
    }
}

/*void DrawMenu() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw menu options
    DrawString(400, 700, "Menu", colors[MISTY_ROSE]);
    DrawString(400, 600, "1. Start Game", colors[MISTY_ROSE]);
    DrawString(400, 550, "2. Exit Game", colors[MISTY_ROSE]);

    glutSwapBuffers();
}

void Menu(int option) {
    switch (option) {
        case 1:
            StartGame(); // Call the StartGame function when option 1 is selected
            break;
        case 2:
            exit(0); // Exit the game when option 2 is selected
            break;
        default:
            // Handle invalid options
            break;
    }
}*/



void CheckMatches(int numRows, int numColumns, int gems[][100]) {

    const int EMPTY = -1;
    int score = 0;

    // Check horizontal matches
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns - 2; ++j) {
            if (gems[i][j] != EMPTY && gems[i][j] == gems[i][j + 1] && gems[i][j] == gems[i][j + 2]) {
                // Update score
                score += 100;
                // Remove matched gems
                gems[i][j] = gems[i][j + 1] = gems[i][j + 2] = EMPTY;
            }
        }
    }

    // Check vertical matches
    for (int i = 0; i < numRows - 2; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            if (gems[i][j] != EMPTY && gems[i][j] == gems[i + 1][j] && gems[i][j] == gems[i + 2][j]) {
                // Update score
                score += 100;
                // Remove matched gems
                gems[i][j] = gems[i + 1][j] = gems[i + 2][j] = EMPTY;
            }
        }
    }

    // Update score
    cout << "Score: " << score << endl;
}
/*int matchedGems[6];
int temp;

void SwapGems(int x, int y) {
    // Check if there are two adjacent matched gems
    if (matchedGems[0] != -1 && matchedGems[1] != -1 && matchedGems[2] != -1 &&
        matchedGems[3] != -1 && matchedGems[4] != -1 && matchedGems[5] != -1) {
        // Check if the clicked position corresponds to one of the two adjacent matched gems
        if ((x == matchedGems[0] && y == matchedGems[1]) ||
            (x == matchedGems[2] && y == matchedGems[3])) {
            // Swap the two adjacent gems
            int temp = gems[matchedGems[0]][matchedGems[1]];
            gems[matchedGems[0]][matchedGems[1]] = gems[matchedGems[4]][matchedGems[5]];
            gems[matchedGems[4]][matchedGems[5]] = temp;
            // Clear the matched gems array
            for (int i = 0; i < 6; ++i) {
                matchedGems[i] = -1;
            }
            // Redraw the game board
            glutPostRedisplay();
        }
    }
}*/

/*int option;

void MenuConditions(int option) {
    switch (option) {
        case 1:
            // Start game
            StartGame();
            break;
        case 2:
            // Go to settings
            GoToSettings();
            break;
        case 3:
            // Exit game
            ExitGame();
            break;
        default:
            // Handle invalid option
            break;
    }
}*/



/*void DrawMenu() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw menu options
    DrawString(400, 700, "Menu", colors[MISTY_ROSE]);
    DrawString(400, 600, "1. Start Game", colors[MISTY_ROSE]);
    DrawString(400, 550, "2. Settings", colors[MISTY_ROSE]);
    DrawString(400, 500, "3. Exit", colors[MISTY_ROSE]);
    MenuConditions(option);
    glutSwapBuffers();
}*/

void DrawGamePaused() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
	
    // Draw paused message
    DrawString(400, 400, "Game Paused", colors[MISTY_ROSE]);

    glutSwapBuffers();
}
/*
void DrawGameOver() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    int score;
    // Draw game over message
    DrawString(400, 400, "Game Over", colors[MISTY_ROSE]);
    DrawString(400, 300, "Score: " + to_string(score), colors[MISTY_ROSE]);
    DrawString(400, 250, "Press F1 to restart", colors[MISTY_ROSE]);

    glutSwapBuffers();
}*/

void DrawProgressBar(int width, int height, int progress) {
    // Draw progress bar outline
    glColor3f(1.0, 1.0, 1.0); // White color
    glLineWidth(2); // Set line width
    glBegin(GL_LINE_LOOP);
    glVertex2f(10, 10);
    glVertex2f(10 + width, 10);
    glVertex2f(10 + width, 10 + height);
    glVertex2f(10, 10 + height);
    glEnd();

    // Fill progress bar
    glColor3f(0.0, 1.0, 0.0); // Green color
    glBegin(GL_POLYGON);
    glVertex2f(10, 10);
    glVertex2f(10 + (width * progress / 100), 10);
    glVertex2f(10 + (width * progress / 100), 10 + height);
    glVertex2f(10, 10 + height);
    glEnd();
} 

void DrawPlayerInfo(string playerName, int score, int level) {
    // Draw player information
    DrawString(10, 780, "Name: " + playerName, colors[MISTY_ROSE]);
    DrawString(10, 760, "Score: " + to_string(score), colors[MISTY_ROSE]);
    DrawString(10, 740, "Level: " + to_string(level), colors[MISTY_ROSE]);
}

void DrawPlayPauseButton() {
    // Draw play/pause button
    DrawString(10, 720, "Press F2 to Pause/Resume", colors[MISTY_ROSE]);
}

void Hint(int numRows, int numColumns, int gems[][100], bool highlightedGems[][100]) {
    // Implement logic to highlight gems that can form a chain
    // For simplicity, let's just highlight the first matching gem found
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            // Check if current gem can form a chain horizontally
            if (j < numColumns - 2 && gems[i][j] == gems[i][j + 1] && gems[i][j] == gems[i][j + 2]) {
                // Highlight the gems that form the chain
                highlightedGems[i][j] = highlightedGems[i][j + 1] = highlightedGems[i][j + 2] = true;
                return; // Stop searching after finding the first match
            }
            // Check if current gem can form a chain vertically
            if (i < numRows - 2 && gems[i][j] == gems[i + 1][j] && gems[i][j] == gems[i + 2][j]) {
                // Highlight the gems that form the chain
                highlightedGems[i][j] = highlightedGems[i + 1][j] = highlightedGems[i + 2][j] = true;
                return; // Stop searching after finding the first match
            }
        }
    }
}

bool CheckIfAllGemsCleared(int numRows, int numColumns, int gems[][100]) {
    const int EMPTY = -1;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            if (gems[i][j] != EMPTY) {
                // If any gem is found, return false (not all gems cleared)
                return false;
            }
        }
    }
    // If no gems are found, return true (all gems cleared)
    return true;
}

void SwapGems(int startRow, int startColumn, int endRow, int endColumn) {
    // Ensure the start and end coordinates are within the bounds of the grid
    
    int numRows;
    int numColumns;
    
    if (startRow >= 0 && startRow < numRows && startColumn >= 0 && startColumn < numColumns &&
        endRow >= 0 && endRow < numRows && endColumn >= 0 && endColumn < numColumns) {
        // Calculate the distance between the start and end coordinates
        int distanceX = abs(endRow - startRow);
        int distanceY = abs(endColumn - startColumn);

        // Ensure the start and end coordinates are adjacent in either row or column, not in diagonal direction
        if ((distanceX == 1 && distanceY == 0) || (distanceX == 0 && distanceY == 1)) {
            // Swap the gems
            int temp = gems[startRow][startColumn];
            gems[startRow][startColumn] = gems[endRow][endColumn];
            gems[endRow][endColumn] = temp;
        } else {
            // Display a message indicating invalid move
            cout << "Invalid move! Gems should be swapped in adjacent rows or columns." << endl;
        }
    } else {
        // Display a message indicating invalid move
        cout << "Invalid move! Gems should be swapped within the grid." << endl;
    }

    // Redraw the game board
    glutPostRedisplay();
}



int GetRandomValue(int min, int max) {
    return min + rand() % (max - min + 1); // Generate a random number between min and max
}
void NextLevel(int numRows, int numColumns, int gems[][100]) {
    // Generate new level

    // For simplicity, let's just remove all empty gems
    const int EMPTY = -1;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            if (gems[i][j] == EMPTY) {
                // Generate random gem type
                int newGemType = GetRandomValue(0, 5); // 0 to 5 represents different gem types
                gems[i][j] = newGemType;
            }
        }
    }
}

/*void SaveGameState(int numRows, int numColumns, int gems[][100], int score) {
    // Save current game state (gems and score)
    // For simplicity, let's just print the current state to the console
    cout << "Game saved: Score: " << score << ", Gems:" << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            cout << static_cast<int>(gems[i][j]) << " ";
        }
        cout << endl;
    }
}*/

/*void LoadGameState(int numRows, int numColumns, int gems[][100], int &score) {

    // Load saved game state (gems and score)

    // For simplicity, let's just use the previously saved state

    score = 1000; // This should be loaded from the saved state

    // This should be loaded from the saved state

    for (int i = 0; i < numRows; ++i) {

        for (int j = 0; j < numColumns; ++j) {

            gems[i][j] = RED; // This should be loaded from the saved state

        }

    }

}*/

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 1020 x 840
	string PlayerName;
	cout<<"Enter your name: " << endl;
	cin>>PlayerName;
	
    int numRows = 8; // Example value for numRows
    int numColumns = 8; // Example value for numColumns
    int gems[100][100]; // Example 2D array for gems
    int score = 1000; // Example value for score
    /*SaveGameState(numRows, numColumns, gems, score);
    LoadGameState(numRows, numColumns, gems, score);*/


	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	
	return 1;
}
#endif /* AsteroidS_CPP_ */
