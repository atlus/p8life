class ConwayCell : public AbstractCell
{
	public:
	/**
	*Default Constructor
	*/
		ConwayCell()
		{
		}
/**
*Constructor takes in char to determine if it's alive or not
*@param x Character passed in
*/
		ConwayCell(char x)
		{
			if (x == '.')
				alive = false;
			else
				alive = true;
		}
/**
* Returns cell symbol
*@return Returns the Fredkin symbol
*/
		char symbol()
		{
			if (alive)
				return '*';
			return '.';
		}
/**
*Attempts to evolve
*@return Returns flag if evolved or not
*/ 
		int evolve()
		{
			if (!alive && neighbors == 3)
			{
				alive = true;
				neighbors = 0;
				return 1;
			}
			if (alive && (neighbors < 2 || neighbors > 3))
			{
				alive = false;
				neighbors = 0;
				return -1;
			}
			neighbors = 0;
			return 0;
		}
};
