//This is some skeleton code for the PeskyTourist assignment.
//It shows you how to load images and get RGB pixel values and write RGB pixel values
//and gives you a function that laods an image for you
//It comes with suggestions on what I did, you do not need to follow these
//The pictures are 200 by 225 (so 200 width, 225 height)
//When you run this program you should see two windows-- one with a whole image and
//one with  a single pixel. Play around with these functions and get comforatable with them
//as you figure out the assignment.

//You can find the BGI documentation at https://www.cs.colorado.edu/~main/bgi/doc/

#include "graphics.h" 
#include <stdio.h>
using namespace std;

void loadImage(int imageNumber);

int main()
{

	//I used the first window as a place to load the images and get their pixel values
	//and the final window as a place to write my final picture
	int firstWindow = initwindow(200, 225, "picture 1"); //notice these window values are ints
	int finalWindow = initwindow(200, 225, "finalPicture"); //i.e. initwindow returns an int

															//Here is sample code that loads image 1 and grabs the 
															//Red Green and Blue Values at pixel 5,23   (so 5 to the right and 23 down wherever that is)

	setcurrentwindow(firstWindow); //BGI function that allows you to select the active window
								   //since I'm going to load an image to read I make the active window 'firstWindow'

	loadImage(0); //Now our firstWindow should have image(0) displayed

	int pixelValue = getpixel(5, 23); // getPixel is a BGI function that returns an integer
									  // That isn't easily understandable (it's hard to figure out what that int means)--> however
									  //there are three other BGI functions that take in this pixel integer
									  //value and returns the Red, Green,and Blue values (also integers from 0 to 255)

	int redValueOfPixel = RED_VALUE(pixelValue);
	int greenValueOfPixel = GREEN_VALUE(pixelValue);
	int blueValueOfPixel = BLUE_VALUE(pixelValue);

	//Finally, let's say we wanted to write this pixel value out to the final window
	//-- for example if we did all our calculationas and it turns out for pixel 5,23 
	//picture 1 has our median pixel value. we do it as follows
	setcurrentwindow(finalWindow); //we set it to our final window 
	putpixel(5, 23, COLOR(redValueOfPixel, greenValueOfPixel, blueValueOfPixel)); //COLOR takes in RGB values
																				  //and returns an integer that represents those values
	setcurrentwindow(firstWindow);
	outtextxy(0, 0, "Press any key");
	getch(); //pauses the program

}


//all the images are numbered 0 to 8
//this function takes that image number and loads it onto the 
//selected window (I loaded images onto the first window)
void loadImage(int imageNumber)
{
	char str[6];
	sprintf(str, "%i.jpg", imageNumber);
	readimagefile(str, 0, 0, 200, 225); //this is a BGI function that loads the image onto the current window
}