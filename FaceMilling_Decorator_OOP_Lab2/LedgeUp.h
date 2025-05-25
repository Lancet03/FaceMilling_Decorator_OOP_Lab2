#pragma once
#include "Decorator.h"
#include "iostream"

class LedgeUp :
	public Decorator
{
	IFaceMilling* faceMill;
public:
	LedgeUp(IFaceMilling* faceMill) : Decorator(faceMill), faceMill(faceMill) {};
	std::array<bool, 4> getLedgeSides() override { return faceMill->getLedgeSides(); };
	void setLedgeSides(std::array<bool, 4> ledgeSides) override { faceMill->setLedgeSides(ledgeSides); }

	void mill() override {
		auto ledgeSides = faceMill->getLedgeSides();
		ledgeSides[0] = true; // Set the up ledge side to true
		faceMill->setLedgeSides(ledgeSides);

		faceMill->mill();
	}
};

