#include <iostream>
#include "IFaceMilling.h"
#include "LineVerticalMilling.h"
#include "LineHorizontalMilling.h"
#include "SnakeHorizontalMilling.h"
#include "SnakeVerticalMilling.h"
#include "LedgeBottom.h"
#include "LedgeUp.h"
#include "LedgeRight.h"
#include "LedgeLeft.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	IFaceMilling* faceMill = nullptr;


	std::cout << "Выберите способ обработки:\n1. Горизонтальной змейкой\n2. Горизонтальными линиями\n3. Вертикальной змейкой\n4. Вертикальными линиями\nСпособ фрезерования:: ";
	std::cin >> a;
	std::cout << std::endl;
	switch (a) {
	case 1:
	{
		faceMill = new SnakeHorizontalMilling();
		break;
	}
	case 2:
	{
		faceMill = new LineHorizontalMilling();
		break;
	}
	case 3:
	{
		faceMill = new SnakeHorizontalMilling();
		break;
	}
	case 4:
	{
		faceMill = new LineVerticalMilling();
		break;
	}
	default: {
		std::cout << "Неверный выбор способа обработки." << std::endl;
		return 1;
	}
	}
	std::cout << std::endl;

	bool endInput = false;
	while (!endInput) {
		std::cout << "Выберите сторону, с которой хотите добавить уступ:\n1. Сверху\n2. Справа\n3. Снизу\n4. Слева\nЛюбое другое значение. Конец ввода\nСторона: ";
		std::cin >> a;
		switch (a) {
		case 1: {
			faceMill = new LedgeUp(faceMill);
			break;
		}
		case 2: {
			faceMill = new LedgeRight(faceMill);
			break;
		}
		case 3: {
			faceMill = new LedgeBottom(faceMill);
			break;
		}
		case 4: {
			faceMill = new LedgeLeft(faceMill);
			break;
		}
		default: {
			endInput = true;
			break;
		}
		}
		std::cout << std::endl;
	}

	faceMill->mill();
	return 0;
}

