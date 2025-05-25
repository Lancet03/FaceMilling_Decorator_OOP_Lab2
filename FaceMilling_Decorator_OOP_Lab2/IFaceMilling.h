#pragma once
#include <string>

class IFaceMilling {

public:
	virtual void mill() = 0;
	virtual std::array<bool, 4> getLedgeSides() = 0;
	virtual void setLedgeSides(std::array<bool, 4> ledgeSides) = 0;
};