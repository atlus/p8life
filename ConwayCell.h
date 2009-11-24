class ConwayCell : public AbstractCell
{
	public:
		ConwayCell()
		{
		}

		ConwayCell(char x)
		{
			if (x == '.')
				alive = false;
			else
				alive = true;
		}

		char symbol()
		{
			if (alive)
				return '*';
			return '.';
		}

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
