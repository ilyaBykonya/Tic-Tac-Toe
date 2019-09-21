#include <iostream>
#include <string>

uint16_t getNumberOfMove(const char symbol)//получаем номер клетки, на котрую ходит игрок
{
	std::cout << "Введите номер квадрата на поле, ваш символ: " << symbol << std::endl;
	uint16_t playerMove;
	std::cin >> playerMove;
	return playerMove;
}

bool checkDraw(const std::string& place)
{
	for (uint16_t count = 0; count < 9; ++count)
	{
		if (place[count] != 'X' && place[count] != 'O')
			return false;
	}

	return true;
}

bool playerMove(std::string& place, const char symbol, uint16_t placeMove)//проверка правильности хода игрока
{
	if ((place[placeMove] == 'O') || (place[placeMove] == 'X'))
	{
		return false;
	}
	else
	{
		place[placeMove] = symbol;
		return true;
	}
}

void printPlace(const std::string& place)//выводим поле
{
	for (uint16_t i = 0; i < 3; ++i)
	{
		std::cout << '|';
		for (uint16_t j = 0; j < 3; ++j)
		{
			std::cout << place[3 * i + j] << '|';
		}
		std::cout << std::endl;
	}
}

void swapSymbol(char& symbol)//меняем очередь хода(смена символа, которым ходят)
{
	if (symbol == 'X')
		symbol = 'O';
	else
		symbol = 'X';
}

bool playerWin(const std::string &place,const char symbol)//проверяем, победил ли игрок, сделавший ход
{
	if (place[0] == symbol)
	{
		if (place[1] == symbol)
		{
			if (place[2] == symbol)
				return true;
		}
		else if (place[3] == symbol)
		{
			if (place[6] == symbol)
				return true;
		}
		else if (place[4] == symbol)
		{
			if (place[8] == symbol)
				return true;
		}
	}

	if (place[1] == symbol)
	{
		if (place[4] == symbol)
		{
			if (place[7] == symbol)
				return true;
		}
	}

	if (place[2] == symbol)
	{
		if (place[4] == symbol)
		{
			if (place[6] == symbol)
				return true;
		}
		else if (place[5] == symbol)
		{
			if (place[8] == symbol)
				return true;
		}
	}

	if (place[3] == symbol)
	{
		if (place[4] == symbol)
		{
			if (place[5] == symbol)
				return true;
		}
	}
	
	if (place[6] == symbol)
	{
		if (place[7] == symbol)
		{
			if (place[8] == symbol)
				return true;
		}
	}

	return false;
}

bool gameProcess(std::string &place,char &symbol)
{
	while (true)
	{
		printPlace(place);
		uint16_t numberMove = getNumberOfMove(symbol);

		if (!playerMove(place, symbol, numberMove))
		{
			std::cout << "Клетка занята, попробуйте другую..." << std::endl;
			continue;
		}

		if (playerWin(place, symbol))
		{
			printPlace(place);
			return true;
		}

		if (checkDraw(place))
		{
			return false;
		}

		swapSymbol(symbol);
		system("cls");
	}
}
int main()
{
	system("title Tic-Tac-Toe");
	setlocale(LC_ALL, "rus");

	std::string place = { "012345678" };
	char symbol = 'X';

	bool gameResult = gameProcess(place, symbol);

	if (!gameResult)
	{
		std::cout << "Ничья..." << std::endl;
	}
	else if (symbol == 'X')
	{
		std::cout << "Первый игрок победил!" << std::endl;
	}
	else
	{
		std::cout << "Второй игрок победил!" << std::endl;
	}
	return 0;
}
