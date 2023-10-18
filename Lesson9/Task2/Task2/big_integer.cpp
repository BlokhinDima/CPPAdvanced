#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include "big_integer.h"


BigInteger::BigInteger(const char* str_number) : str_representation{ str_number }
{
	digits_vector = strToVectorRepresentation(str_representation);
}


BigInteger::BigInteger(std::string str_number) : str_representation{ str_number }
{
	digits_vector = strToVectorRepresentation(str_representation);
}


BigInteger::BigInteger(const BigInteger& other)
{
	str_representation = other.str_representation;
	digits_vector = other.digits_vector;
}


BigInteger::BigInteger(BigInteger&& other) noexcept
{
	str_representation = std::move(other.str_representation);
	digits_vector = std::move(other.digits_vector);
}


BigInteger& BigInteger::operator=(const BigInteger& other)
{
	if (&other == this)
		return *this;

	str_representation = other.str_representation;
	digits_vector = other.digits_vector;
	return *this;
}


BigInteger& BigInteger::operator=(BigInteger&& other) noexcept
{
	if (&other == this)
		return *this;

	str_representation = std::move(other.str_representation);
	digits_vector = std::move(other.digits_vector);
	return *this;
}


BigInteger BigInteger::operator+(const BigInteger& other)
{
	if (this->digitsNum() >= other.digitsNum())
	{
		return sumBigIntegers(other, *this);
	}
	else
	{
		return sumBigIntegers(*this, other);
	}
}


BigInteger BigInteger::operator+(const long long int other)
{
	BigInteger other_big_integer(std::to_string(other));
	return operator+(other_big_integer);
}


BigInteger BigInteger::sumBigIntegers(const BigInteger& less_digits, const BigInteger& more_digits)
{
	std::vector<int> sum;
	int carry = 0;

	for (int i = less_digits.digitsNum() - 1, j = more_digits.digitsNum() - 1; 
		j >= 0; 
		--i, --j)
	{
		int digits_sum = 0;

		if (i >= 0)
		{
			digits_sum = less_digits.digits_vector[i] + more_digits.digits_vector[j] + carry;
		}
		else
		{
			digits_sum = more_digits.digits_vector[j] + carry;
		}
		const int new_digit = digits_sum % 10;
		carry = digits_sum / 10;
		sum.insert(sum.begin(), new_digit);
	}

	if (carry != 0)
	{
		sum.insert(sum.begin(), carry);
	}

	auto str_representation = vectorToStrRepresentation(sum);
	return BigInteger(str_representation);
}


BigInteger BigInteger::operator*(const BigInteger& other)
{
	if (this->digitsNum() >= other.digitsNum())
	{
		return multiplyBigIntegers(other, *this);
	}
	else
	{
		return multiplyBigIntegers(*this, other);
	}
}


BigInteger BigInteger::operator*(const long long int other)
{
	BigInteger other_big_integer(std::to_string(other));
	return operator*(other_big_integer);
}


BigInteger BigInteger::multiplyBigIntegers(const BigInteger& smaller, const BigInteger& bigger)
{
	std::vector<int> multiplication;
	int carry = 0;
	int digit_shift = 0;

	for (int i = smaller.digitsNum() - 1; i >= 0; --i)
	{
		for (int j = bigger.digitsNum() - 1; j >= 0; --j)
		{
			int digits_multiplication = smaller.digits_vector[i] * bigger.digits_vector[j] + carry;
			int new_digit = digits_multiplication % 10;
			carry = digits_multiplication / 10;

			if (i == smaller.digitsNum() - 1)
			{
				multiplication.insert(multiplication.begin(), new_digit);
			}
			else
			{
				if (j - digit_shift < 0)
				{
					multiplication.insert(multiplication.begin(), 0);
					digit_shift--;
				}

				multiplication[j - digit_shift] = multiplication[j - digit_shift] + new_digit;
				carry += multiplication[j - digit_shift] / 10;
				multiplication[j - digit_shift] %= 10;
			}
		}
		digit_shift++;
		
		if (carry != 0)
		{
			multiplication.insert(multiplication.begin(), carry);
			digit_shift--;
			carry = 0;
		}
	}

	auto str_representation = vectorToStrRepresentation(multiplication);
	return BigInteger(str_representation);
}


std::vector<int> BigInteger::strToVectorRepresentation(const std::string& number)
{
	std::vector<int> vector;
	for (const auto& digit : number)
	{
		vector.push_back(digit - '0');
	}
	return vector;
}


std::string BigInteger::vectorToStrRepresentation(const std::vector<int>& number)
{
	std::string str;
	for (int i = 0; i < number.size(); ++i)
	{
		str += std::to_string(number[i]);
	}
	return str;
}


std::ostream& operator<<(std::ostream& out, const BigInteger& big_integer)
{
	out << big_integer.str_representation;
	return out;
}
