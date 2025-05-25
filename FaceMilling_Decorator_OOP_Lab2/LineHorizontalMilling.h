#pragma once
#include "IFaceMilling.h"
#include <array>
#include <iostream>

class LineHorizontalMilling : public IFaceMilling
{
	std::array<bool, 4> ledgeSides = { false, false, false, false };
public:
	std::array<bool, 4> getLedgeSides() override { return this->ledgeSides; };
	void setLedgeSides(std::array<bool, 4> ledgeSides) override {
		this->ledgeSides = ledgeSides;
	}

	void mill() override {
		if (this->ledgeSides[1] && this->ledgeSides[3]) {
			std::cout << "Горизонтальное фрезерование невозможно при стенках слева и справа." << std::endl;
		}
		else if (this->ledgeSides[3]) {
			if (this->ledgeSides[2]) std::cout << "Фрезерование змейкой с правого верхнего угла" << std::endl;
			else std::cout << "Фрезерование горизонтальными линиями с правого нижнего угла" << std::endl;
		}
		else {
			if (this->ledgeSides[2]) std::cout << "Фрезерование змейкой с левого верхнего угла" << std::endl;
			else std::cout << "Фрезерование горизонтальными линиями с левого нижнего угла" << std::endl;
		}
	}
};

