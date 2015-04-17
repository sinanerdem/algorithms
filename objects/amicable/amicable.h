#include "../util/util.h"

class amicable {
public:
	amicable(int x);
	virtual ~amicable();
	int findSumOfFactors(int x);
	bool inArray(int x);

private:
	int counter;
	int results[250][2];
};
