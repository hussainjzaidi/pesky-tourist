// Hussain Zaidi Midterm Project Pesky Tourist
#include "graphics.h" 
#include <stdio.h>
#include <iostream>
using namespace std;

void loadImage(int imageNumber); //function prototype
void bubbleSort(int numr[], int x); //function prototype

int main()
{

	int firstWindow = initwindow(200, 225, "picture 1"); // load first image
	int finalWindow = initwindow(200, 225, "finalPicture"); //load last image

	setcurrentwindow(firstWindow); //set current window to first window
	loadImage(0); //call load image function
	
	/*int redValueOfPixel = RED_VALUE(pixelValue);
	int greenValueOfPixel = GREEN_VALUE(pixelValue);
	int blueValueOfPixel = BLUE_VALUE(pixelValue);
	*/
	int window[200][225][9]; //[x], [y], xy are coordinates [9] # of pictures
	for (int i = 0; i < 9; i++) //display pictures
	{
		loadImage(i);
		for (int x = 0; x < 200; x++)
		{
			for (int y = 0; y < 225; y++) {
				window[x][y][i] = getpixel(x, y);
			}
		}
	}
	int gArray[9]; // initialize
	int rArray[9];
	int bArray[9];
	
	setcurrentwindow(finalWindow);
	for (int x = 0; x < 200; x++)
	{
		for (int y = 0; y < 225; y++)
		{
			for (int i = 0; i < 9; i++)
			{
				rArray[i] = RED_VALUE(window[x][y][i]); //obtain pixels
				bArray[i] = BLUE_VALUE(window[x][y][i]);
				gArray[i] = GREEN_VALUE(window[x][y][i]);
			}
			bubbleSort(rArray, 9); //sorts pixel from images
			bubbleSort(bArray, 9);//RGB calculations
			bubbleSort(gArray, 9);
			int rMed = rArray[4]; //median values
			int bMed = bArray[4];
			int gMed = gArray[4];
			putpixel(x, y, COLOR(rMed, gMed, bMed)); //takes in RGB value of medians
		}
	}

	
	//cout << window[0][0][0] << " " << RED_VALUE(window[0][0][0]) << endl; test to print
	//cout << window[0][0][0] << " " << GREEN_VALUE(window[0][0][0]) << endl;
	//cout << window[0][0][0] << " " << BLUE_VALUE(window[0][0][0]) << endl;



	getch(); //pauses the program

}

void loadImage(int imageNumber) //function loads image onto selected window
{
	char str[6];
	sprintf(str, "%i.jpg", imageNumber);
	readimagefile(str, 0, 0, 200, 225);
}

void bubbleSort(int num[], int x)
{
	bool swapped = true;
	int j = 0;
	int temp;
	while (swapped)
	{
		swapped = false;
		j++;
		for (int i = 0; i < x - j; i++) //ascending order
		{
			if (num[i] > num[i + 1]) {
				temp = num[i]; // swap elements
				num[i] = num[i + 1];
				num[i + 1] = temp;
				swapped = true;
			}
		}
	}
}