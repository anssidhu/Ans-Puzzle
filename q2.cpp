#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int wordsize(char* string)
{
	int size = 0;
	int i = 0;

	while (string[i] != '\0')
	{
		size++;
		i++;
	}
	return size;
}
char** words(int count, int inline)
{
	ifstream file("Input.txt");
	if (file)
	{

		string dummyLine;
		for (int i = 0; i < inline; i++)
		{
			getline(file, dummyLine);
		}

		char** wordList = new char* [count];

		int i = 0;

		while (i < count)
		{
			char abc[80];

			file.getline(abc, 80);

			int cols = 0;
			cols = wordsize(abc);

			wordList[i] = new char[cols + 1];

			int j = 0;
			for (j = 0; j < cols; j++)
			{
				wordList[i][j] = abc[j];
			}
			wordList[i][j] = '\0';
			i++;
		}

		return wordList;
	}

}
char** scanGrid(int rows, int colm, int inline)
{
	ifstream file("Input.txt");
	if (file)
	{

		string dummyLine;
		for (int i = 0; i < inline; i++)
		{
			getline(file, dummyLine);
		}

		int i = 0;
		char** Grid = new char* [rows];
		while (i < rows)
		{
			char abc[80];

			file.getline(abc, 80);



			Grid[i] = new char[colm + 1];

			int j = 0;
			int k = 0;
			for (j = 0; j < colm && k < (colm + colm - 1); j++)
			{

				Grid[i][j] = abc[k];
				k += 2;

			}
			Grid[i][j] = '\0';
			i++;
		}

		return Grid;
	}

}

int* SearchAllDirections(char** grid, int gridRow, int gridCol, int row, int col, char* word)
{
	int rowDirection[] = { 0, 0, 1,-1, 1, 1, -1, -1 };
	int colDirection[] = { -1, 1, 0, 0, 1, -1, 1, -1 };

	int* arr = new int[3];


	if (grid[row][col] != word[0])
	{
		arr[0] = -1;
		arr[1] = 0;
		arr[2] = 0;
		return  arr;
	}


	int length = wordsize(word);


	for (int i = 0; i < 8; i++)
	{
		int j;
		int moveRow = row + rowDirection[i];
		int moveCol = col + colDirection[i];


		for (j = 1; j < length; j++)
		{

			if (moveRow >= gridRow || moveRow < 0 || moveCol >= gridCol || moveCol < 0)
			{
				break;
			}



			if (grid[moveRow][moveCol] != word[j])
			{
				break;
			}



			moveRow = moveRow + rowDirection[i];
			moveCol = moveCol + colDirection[i];
		}


		if (j == length)
		{
			moveRow = moveRow - rowDirection[i];
			moveCol = moveCol - colDirection[i];

			arr[0] = 1;
			arr[1] = moveRow;
			arr[2] = moveCol;

			return arr;
		}

	}
	arr[0] = -1;
	arr[1] = 0;
	arr[2] = 0;
	return  arr;
}


int* GridSearch(char** grid, int gridRow, int gridCol, char* word)
{
	int* returnArray = new int[4];
	int* arr = new int[3];

	for (int row = 0; row < gridRow; row++)
	{
		for (int col = 0; col < gridCol; col++)
		{
			arr = SearchAllDirections(grid, gridRow, gridCol, row, col, word);
			if (arr[0] == 1)
			{
				returnArray[0] = row;
				returnArray[1] = col;

				returnArray[2] = arr[1];
				returnArray[3] = arr[2];
				return returnArray;
			}

		}

	}
	delete[]arr;
	returnArray[0] = -1;
	returnArray[1] = 0;
	returnArray[2] = 0;
	returnArray[3] = 0;
	return returnArray;

}


void ShowCordinates(char** list, int numberOfWords, char** grid, int rows, int colm)
{
	ofstream file("Output.txt");
	if (file)
	{
		for (int i = 0; i < numberOfWords; i++)
		{

			int* resultArr = new int[4];

			resultArr = GridSearch(grid, rows, colm, list[i]);

			if (resultArr[0] == -1)
			{
				file << "nopeeeee";
			}
			else
			{
				file << "{" << resultArr[0] << "," << resultArr[1] << "}" << "{" << resultArr[2] << "," << resultArr[3] << "}";
			}
			file << endl;
			delete[]resultArr;


		}
	}
	file.close();


}
int main()
{
	ifstream fin("Input.txt");
	if (fin)
	{
		int rows, colm, count;

		fin >> rows >> colm >> count;

		int readLine;

		char** grid = 0;
		readLine = 2;
		grid = scanGrid(rows, colm, readLine);


		char** list = 0;
		readLine = 2 + rows;
		list = words(count, readLine);

		ShowCordinates(list, count, grid, rows, colm);
		cout << endl << "See the file";
	}



}

