class FredkinCell : public AbstractCell
{
	private:
		int age;

	public:
		FredkinCell()
		{
		}

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
