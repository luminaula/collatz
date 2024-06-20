#include <cstdint>

namespace lumi
{

class Collatz
{
public:
	Collatz();
	~Collatz();
	int run(uint64_t n);
	int run(uint64_t low, uint64_t high);
};

}
