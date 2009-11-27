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

        const_pointer get () const {
            return _p;}

    public:
		Cell()
		{
			_p = 0;
		}

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

		bool isAlive()
		{
			return _p->isAlive();
		}

		void incNeighbors()
		{
			_p->incNeighbors();
		}

		char symbol()
		{
			return _p->symbol();
		}

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
