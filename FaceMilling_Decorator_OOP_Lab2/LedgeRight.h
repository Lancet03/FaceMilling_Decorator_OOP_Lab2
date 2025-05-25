#pragma once
#include "Decorator.h"
#include <iostream>

class LedgeRight :
	public Decorator
{
private:
	IFaceMilling* faceMill;
public:
	LedgeRight(IFaceMilling* faceMill) : Decorator(faceMill), faceMill(faceMill) {};
	std::array<bool, 4> getLedgeSides() override { return faceMill->getLedgeSides(); };
	void setLedgeSides(std::array<bool, 4> ledgeSides) override { faceMill->setLedgeSides(ledgeSides); }

	void mill() override {
		auto ledgeSides = faceMill->getLedgeSides();
		ledgeSides[1] = true; // Set the right ledge side to true
		faceMill->setLedgeSides(ledgeSides);

		faceMill->mill();
	}
};

