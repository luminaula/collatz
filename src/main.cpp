
#include <iostream>
#include <chrono>

#include "collatz.h"

using namespace lumi;

int main(int argc, char** argv)
{
	Collatz collatz;
	auto startTime = std::chrono::steady_clock::now();
	if(argc == 2)
	{
		auto value = std::stoull(argv[1]);
		auto count = collatz.run(std::stoull(argv[1]));
		std::cout << "Value: " << value << " Count: " << count << std::endl;
	}
	else if(argc == 3)
	{
		auto low = std::stoull(argv[1]);
		auto high = std::stoull(argv[2]);
		auto max = collatz.run(low, high);
		std::cout << "Low: " << low << " High: " << high << " Max: " << max << std::endl;
	}
	else
	{
		std::cerr << "Usage: " << "\t" << argv[0] << " <number>" << "\n" << "\t" << argv[0] << " <low> <high>" << std::endl;
		return -1;
	}

	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - startTime).count() << "ms" << std::endl;

	return 0;
}
