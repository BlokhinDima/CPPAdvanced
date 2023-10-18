#pragma once

#include <string>
#include <vector>
#include <iostream>

class BigInteger
{
public:
	BigInteger(const char* str_number);
	BigInteger(std::string str_number);
	BigInteger(const BigInteger& other);
	BigInteger(BigInteger&& other) noexcept;
	BigInteger& operator=(const BigInteger& other);
	BigInteger& operator=(BigInteger&& other) noexcept;
	BigInteger operator+(const BigInteger& other);
	BigInteger operator+(const long long int other);
	BigInteger operator*(const BigInteger& other);
	BigInteger operator*(const long long int other);
	friend std::ostream& operator<<(std::ostream& out, const BigInteger& big_integer);
	auto digitsNum() const { return digits_vector.size(); }

private:
	std::string str_representation;
	std::vector<int> digits_vector;
	std::vector<int> strToVectorRepresentation(const std::string& number);
	std::string vectorToStrRepresentation(const std::vector<int>& number);
	BigInteger sumBigIntegers(const BigInteger& smaller, const BigInteger& bigger);
	BigInteger multiplyBigIntegers(const BigInteger& smaller, const BigInteger& bigger);
};
