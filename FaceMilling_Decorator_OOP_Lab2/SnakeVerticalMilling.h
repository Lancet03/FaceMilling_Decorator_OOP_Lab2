#pragma once
#include "IFaceMilling.h"

#include <string>
#include <array>
#include <iostream>

class SnakeVerticalMilling :
	public IFaceMilling
{
	std::array<bool, 4> ledgeSides = { false, false, false, false };
public:
	std::array<bool, 4> getLedgeSides() override { return this->ledgeSides; };
	void setLedgeSides(std::array<bool, 4> ledgeSides) override {
		this->ledgeSides = ledgeSides;
	}

	void mill() override {
		if (this->ledgeSides[0] && this->ledgeSides[2]) {
			std::cout << "Вертикальное фрезерование невозможно при стенках сверху и снизу." << std::endl;
		}
		else if (this->ledgeSides[2]) {
			if (this->ledgeSides[3]) std::cout << "Фрезерование змейкой с правого верхнего угла" << std::endl;
			else std::cout << "Фрезерование вертикальной змейкой с левого верхнего угла" << std::endl;
		}
		else {
			if (this->ledgeSides[3]) std::cout << "Фрезерование змейкой с правого нижнего угла" << std::endl;
			else std::cout << "Фрезерование вертикальной змейкой с левого нижнего угла" << std::endl;
		}
	}
};

