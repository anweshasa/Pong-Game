#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <SFML/Graphics.hpp>

int main()
{
// Create a video mode object


// Create and open a window for the game

//Declare and initialize score and lives variable


// Create a bat


//Create a ball

// Create a Text object called HUD (Heads Up Display)


// load font 

// Set the font

// Set font size


// Choose a color

//set position of the text


// Declare clock object for timing


	while (window.isOpen())
		{
		//Handle the player input

		// Quit the game when the window is closed


		// Handle the player quitting

		// Handle the playing inputs
		//Left cursor movement

		//Right cursor movement

		// Update the delta time
		
		
		//Update the bat
		
		//Update ball
		
		// Update the HUD text

		// Handle ball hitting the bottom

		// Handle ball hitting top

		// Handle ball hitting sides

		// Has the ball hit the bat?
		
			// If hit detected, reverse the ball and score a point

		//Draw the bat, the ball and the HUD

	}//End of while(window.isOpen())

	return 0;
	
}//End of main()

