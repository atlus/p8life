#include <algorithm>

class AbstractCell;

class Cell {
    /*friend bool operator == (const Cell& lhs, const Cell& rhs) {
        return (!lhs._p && !rhs._p) || (*lhs._p == *rhs._p);}

    friend bool operator != (const Cell& lhs, const Cell& rhs) {
        return !(lhs == rhs);}*/
 /*! \var pointer _p
 *     \brief Points to a cell of AbstractCell
 *     */

    public:
        typedef AbstractCell      value_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

    private:
        pointer _p;

    protected:
    /**
    *Returns the pointer
    *@return Returns the pointer
    */
        pointer get () {
            return _p;}
    /**
    *Returns const pointer
    *@return Returns a const pointer
    */
        const_pointer get () const {
            return _p;}

    public:
      /**
    *Default Constructor
    */
		Cell()
		{
			_p = 0;
		}
    /**
    *Conway or Fredkin Constructor
    *@param x Determines the type of cell
    */
		Cell(char x)
		{
			if (x == '*' || x == '.')
				_p = new ConwayCell(x);
			else
				_p = new FredkinCell(x);
		}

        Cell (pointer p) {
            _p = p;}

        Cell (const Cell& that) {
            if (!that._p)
                _p = 0;
            else
                //_p = that._p->clone();
				assert(false);
			}

        ~Cell () {
            delete _p;}

        Cell& operator = (Cell that) {
            swap(that);
            return *this;}

        void swap (Cell& that) {
            std::swap(_p, that._p);}
    /**
    *@return True if alive else dead
    */
		bool isAlive()
		{
			return _p->isAlive();
		}
/**
*Increments its neighbors
*/
		void incNeighbors()
		{
			_p->incNeighbors();
		}

/**
*@return Returns the cell's symbol
*/
		char symbol()
		{
			return _p->symbol();
		}
/**
*Attempts to evolve, if Fredkin Cell age is two and can evolve it becomes conway
@return int of population change
*/
		int evolve()
		{
			int r = _p->evolve();
			if (symbol() == '2')
			{
				delete _p;
				_p = new ConwayCell('*');
			}
			return r;
		}
};
