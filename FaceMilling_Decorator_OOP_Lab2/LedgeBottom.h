#pragma once
#include "Decorator.h"
#include <iostream>

class LedgeBottom : public Decorator
{
	IFaceMilling* faceMill;
public:
	LedgeBottom(IFaceMilling* faceMill) : Decorator(faceMill), faceMill(faceMill) {};
	std::array<bool, 4> getLedgeSides() override { return faceMill->getLedgeSides(); };
	void setLedgeSides(std::array<bool, 4> ledgeSides) override { faceMill->setLedgeSides(ledgeSides); }

	void mill() override {
		auto ledgeSides = faceMill->getLedgeSides();
		ledgeSides[2] = true; // Set the bottom ledge side to true
		faceMill->setLedgeSides(ledgeSides);

		faceMill->mill();
	}
};

