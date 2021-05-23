#include "CArc.h"
#include <iostream>
CArc::CArc() {
}

CArc::CArc(CArc &ARCArg) {
	uiARCDestination = ARCArg.uiARCDestination;
}

CArc::CArc(unsigned int uiDestination) {
	uiARCDestination = uiDestination;
}

bool CArc::operator==(CArc &ARCArg) {
	return uiARCDestination == ARCArg.uiARCDestination;
}

unsigned int CArc::ARCGetDestination() {
	return uiARCDestination;
}

void CArc::ARCSetDestination(unsigned int uiNumero) {
	uiARCDestination = uiNumero;
}

void CArc::ARCAfficher() {
	std::cout << "Arc pointant vers le sommet : " << uiARCDestination << std::endl;
}



