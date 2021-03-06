#include <fstream>
#include <vector>

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

template <typename T>
class Life
{
/*! \var vector<vector<T> > grid
 *     \brief Grid of Cells
 *     */
 /*! \var int R
 *     \brief Row length
 *     */
 /*! \var int C
 *     \brief Column length
 *     */
 /*! \var int gen 
 *     \brief Generation
 *     */
 /*! \var int pop
 *     \brief Population
 *     */
	private:
		vector< vector<T> > grid;
		int R, C;
		int gen, pop;
/**
*Counts the Neightbors
*/
		void countNeighbors()
		{
			for (int r = 0; r < R; ++r)
				for (int c = 0; c < C; ++c)
					if (grid[r][c].isAlive())
					{
						if (r-1 >= 0 && c-1 >= 0 && grid[r-1][c-1].symbol() == '*' || grid[r-1][c-1].symbol() == '.')
							grid[r-1][c-1].incNeighbors();
						if (r-1 >= 0 && c+1 <  C && grid[r-1][c+1].symbol() == '*' || grid[r-1][c+1].symbol() == '.')
							grid[r-1][c+1].incNeighbors();
						if (r+1 <  R && c-1 >= 0 && grid[r+1][c-1].symbol() == '*' || grid[r+1][c-1].symbol() == '.')
							grid[r+1][c-1].incNeighbors();
						if (r+1 <  R && c+1 <  C && grid[r+1][c+1].symbol() == '*' || grid[r+1][c+1].symbol() == '.')
							grid[r+1][c+1].incNeighbors();
						if (c-1 >= 0)
							grid[r][c-1].incNeighbors();
						if (c+1 <  C)
							grid[r][c+1].incNeighbors();
						if (r-1 >= 0)
							grid[r-1][c].incNeighbors();
						if (r+1 <  R)
							grid[r+1][c].incNeighbors();
					}
		}

		/*void countNeighbors()
		{
			// inside
			for (int r = 1; r < R-1; ++r)
				for (int c = 1; c < C-1; ++c)
					if (grid[r][c].isAlive())
					{
						if (grid[r-1][c-1].symbol() == '*' || grid[r-1][c-1].symbol() == '.')
							grid[r-1][c-1].incNeighbors();
						if (grid[r-1][c+1].symbol() == '*' || grid[r-1][c+1].symbol() == '.')
							grid[r-1][c+1].incNeighbors();
						if (grid[r+1][c-1].symbol() == '*' || grid[r+1][c-1].symbol() == '.')
							grid[r+1][c-1].incNeighbors();
						if (grid[r+1][c+1].symbol() == '*' || grid[r+1][c+1].symbol() == '.')
							grid[r+1][c+1].incNeighbors();
						grid[r][c-1].incNeighbors();
						grid[r][c+1].incNeighbors();
						grid[r-1][c].incNeighbors();
						grid[r+1][c].incNeighbors();
					}
			// left & right walls
			for (int r = 1; r < R-1; ++r)
			{
				// left
				if (grid[r][0].isAlive())
				{
					if (grid[r-1][  1].symbol() == '*' || grid[r-1][  1].symbol() == '.')
						grid[r-1][  1].incNeighbors();
					if (grid[r+1][  1].symbol() == '*' || grid[r+1][  1].symbol() == '.')
						grid[r+1][  1].incNeighbors();
					grid[r-1][0].incNeighbors();
					grid[r+1][0].incNeighbors();
					grid[r][  1].incNeighbors();
				}
				// right
				if (grid[r][C-1].isAlive())
				{
					if (grid[r-1][C-2].symbol() == '*' || grid[r-1][C-2].symbol() == '.')
						grid[r-1][C-2].incNeighbors();
					if (grid[r+1][C-2].symbol() == '*' || grid[r+1][C-2].symbol() == '.')
						grid[r+1][C-2].incNeighbors();
					grid[r-1][C-1].incNeighbors();
					grid[r+1][C-1].incNeighbors();
					grid[r][  C-2].incNeighbors();
				}
			}
			// top & bottom walls
			for (int c = 1; c < C-1; ++c)
			{
				// top
				if (grid[0][c].isAlive())
				{
					if (grid[  1][c-1].symbol() == '*' || grid[  1][c-1].symbol() == '.')
						grid[  1][c-1].incNeighbors();
					if (grid[  1][c+1].symbol() == '*' || grid[  1][c+1].symbol() == '.')
						grid[  1][c+1].incNeighbors();
					grid[0][c-1].incNeighbors();
					grid[0][c+1].incNeighbors();
					grid[1][c  ].incNeighbors();
				}
				// bottom
				if (grid[R-1][c].isAlive())
				{
					if (grid[R-2][c-1].symbol() == '*' || grid[R-2][c-1].symbol() == '.')
						grid[R-2][c-1].incNeighbors();
					if (grid[R-2][c+1].symbol() == '*' || grid[R-2][c+1].symbol() == '.')
						grid[R-2][c+1].incNeighbors();
					grid[R-1][c-1].incNeighbors();
					grid[R-1][c+1].incNeighbors();
					grid[R-2][c  ].incNeighbors();
				}
			}
			// top left corner
			if (grid[0][0].isAlive())
			{
				if (grid[1][1].symbol() == '*' || grid[1][1].symbol() == '.')
					grid[1][1].incNeighbors();
				grid[0][1].incNeighbors();
				grid[1][0].incNeighbors();
			}
			// top right corner
			if (grid[0][C-1].isAlive())
			{
				if (grid[1][C-2].symbol() == '*' || grid[1][C-2].symbol() == '.')
					grid[1][C-2].incNeighbors();
				grid[0][C-2].incNeighbors();
				grid[1][C-1].incNeighbors();
			}
			// bottom left corner
			if (grid[R-1][0].isAlive())
			{
				if (grid[R-2][1].symbol() == '*' || grid[R-2][1].symbol() == '.')
					grid[R-2][1].incNeighbors();
				grid[R-1][1].incNeighbors();
				grid[R-2][0].incNeighbors();
			}
			// bottom right corner
			if (grid[R-1][C-1].isAlive())
			{
				if (grid[R-2][C-2].symbol() == '*' || grid[R-2][C-2].symbol() == '.')
					grid[R-2][C-2].incNeighbors();
				grid[R-1][C-2].incNeighbors();
				grid[R-2][C-1].incNeighbors();
			}
		}*/

	public:
	/**
	*Default constructor
	*/
		Life()
		{
			gen = 0;
			pop = 0;
		}
/**
*Reads in a local file and sets up the grid
*/
		void read(const char *file)
		{
			ifstream in;
			in.open(file);

			in >> R >> C;
			grid = vector< vector<T> >(R, vector<T>(C));

			char x;
			for (int r = 0; r < R; ++r)
				for (int c = 0; c < C; ++c)
				{
					in >> x;
					grid[r][c] = T(x);
					if (x != '.' && x != '-')
						++pop;
				}

			in.close();
		}
/**
*Simulates turns
*@param N number of turns to simulate
*/
		void simulate(int N)
		{
			for (int i = 0; i < N; ++i)
			{
				countNeighbors();
				for (int r = 0; r < R; ++r)
					for (int c = 0; c < C; ++c)
						pop += grid[r][c].evolve();
			}
			gen += N;
		}
/**
*Prints the grid
*/
		void print()
		{
			cout << "Generation = " << gen << ", Population = " << pop << "." << endl;
			for (int r = 0; r < R; ++r)
			{
				for (int c = 0; c < C; ++c)
					cout << grid[r][c].symbol();
				cout << endl;
			}
			cout << endl;
		}
};
