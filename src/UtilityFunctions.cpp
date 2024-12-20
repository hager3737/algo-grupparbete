#include "../include/UtilityFunctions.h"

std::string padString(const std::string& accountNumber) {
    std::ostringstream padded;
    padded << std::setw(4) << std::setfill('0') << accountNumber;
    return padded.str();
}