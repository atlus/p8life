class AbstractCell
{
	protected:
		bool alive;
		int  neighbors;

	public:
		AbstractCell()
		{
			neighbors = 0;
		}

		bool isAlive()
		{
			return alive;
		}

		void incNeighbors()
		{
			++neighbors;
		}

		virtual char symbol() = 0;
		virtual int  evolve() = 0;
};
