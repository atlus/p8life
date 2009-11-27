class AbstractCell
{
/*! \var bool alive 
 *     \brief If the cell is alive or not
 *     */
 /*! \var int neighbors
 *     \brief Value of neighbors alive
 *     */
	protected:
		bool alive;
		int  neighbors;

	public:
	/**
	* Default Constructor
	*/
		AbstractCell()
		{
			neighbors = 0;
		}
/**
*@return if the cell is alive or not
*/
		bool isAlive()
		{
			return alive;
		}
/**
*Increments the cell's neighbor count
*/
		void incNeighbors()
		{
			++neighbors;
		}
/**
*The Cell's symbol
*@return Return's the cell's symbol
*/
		virtual char symbol() = 0;
		/**
		*Attempts to evolve the cell
		*@return REturns if the cell evolved
		*/
		virtual int  evolve() = 0;
};
