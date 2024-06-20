#include "collatz.h"

#include <bit>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <ranges>

namespace lumi
{

Collatz::Collatz()
{}

Collatz::~Collatz()
{}

int Collatz::run(uint64_t n)
{
#ifndef NDEBUG
	std::cout << "Seed: " << n << std::endl;
	const auto printBits = [](uint64_t n)
	{
		std::cout << "\t" << std::left << std::setw(6) << n << " 0b" << std::bitset<64>(n) << std::endl;
	};
#else
	const auto printBits = [](uint64_t) {};
#endif

	int count = 0;
	printBits(n);
	if(n % 2 == 0)
	{
		const auto step = std::countr_zero(n);
		n >>= step;
		count += step;
		printBits(n);
	}
	while (n != 1) [[likely]]
	{
		n = n * 3 + 1;
		printBits(n);
		const auto step = std::countr_zero(n);
		count += step + 1;
		n >>= step;
		printBits(n);
	}
	return count;
}

int Collatz::run(uint64_t low, uint64_t high)
{
	int max = 0;
	for(const auto& i : std::ranges::iota_view(low, high + 1))
	{
		int count = run(i);
		if(count > max)
		{
			max = count;
		}
	}
	return max;
}

} // namespace lumi
