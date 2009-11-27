class FredkinCell : public AbstractCell
{
 /*! \var int age
 *     \brief Value of cell's age
 *     */
	private:
		int age;
/**
* Default Constructor
*/
	public:
		FredkinCell()
		{
		}
/**
*Constructor takes in char to determine if it's alive or not
*@param x Character passed in
*/
		FredkinCell(char x)
		{
			if (x == '-')
			{
				alive = false;
				age = 0;
			}
			else
			{
				alive = true;
				age = x - '0';
			}
		}
/**
* Returns cell symbol
*@return Returns the Fredkin symbol
*/
		char symbol()
		{
			if (alive)
			{
				if (age > 9)
					return '+';
				return age + '0';
			}
			return '-';
		}
/**
*Attempts to evolve
*@return Returns flag if evolved or not
*/ 
		int evolve()
		{
			if (!alive && (neighbors == 1 || neighbors == 3))
			{
				alive = true;
				neighbors = 0;
				return 1;
			}
			if (alive && (neighbors == 0 || neighbors == 2 || neighbors == 4))
			{
				alive = false;
				neighbors = 0;
				age = 0;
				return -1;
			}
			neighbors = 0;
			if (alive)
				++age;
			return 0;
		}
};

