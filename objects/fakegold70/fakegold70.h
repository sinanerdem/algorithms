#include "../util/util.h"

class fakegold70 {
public:
	fakegold70();

private:
	void _createArray(int a);
	void _deleteArray();
	void _findFake();
	int _divideAndCompare(int min, int max);
	int _SIZE;
	int* _coinsArr;
	int _numberOfWeighings;
	int _minNumberOfWeighings;
	int _maxNumberOfWeighings;
};
