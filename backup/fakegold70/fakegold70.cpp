#include "fakegold70.h"


fakegold70::fakegold70(): _SIZE(70), _numberOfWeighings(0), _minNumberOfWeighings(70), _maxNumberOfWeighings(1){
	for(int i=1 ; i<=70 ; i++){
		_createArray(i);
		cout << "Fake coin is in slot: " << i << endl;
		_findFake();
		cout << "Number of weighings: " << _numberOfWeighings << endl;
		if (_numberOfWeighings < _minNumberOfWeighings) {_minNumberOfWeighings=_numberOfWeighings;}
		if (_numberOfWeighings > _maxNumberOfWeighings) {_maxNumberOfWeighings=_numberOfWeighings;}
		_numberOfWeighings=0;
		_deleteArray();
	}
	cout << "---------------------------------" << endl;
	cout << "Minimum number of weighings: " << _minNumberOfWeighings << endl;
	cout << "Maximum number of weighings: " << _maxNumberOfWeighings << endl;
}
void fakegold70::_createArray(int a){
	_coinsArr = new int[71]();
	_coinsArr[a] = 1;
}

void fakegold70::_deleteArray(){
	delete[] _coinsArr;
}
void fakegold70::_findFake(){
	_divideAndCompare(1, _SIZE);
}
int fakegold70::_divideAndCompare(int min, int max){
	int result = 0;
	int firstHalfSum = 0;
	int secondHalfSum = 0;
	int noOfCoins = max - min + 1;
	if (noOfCoins == 2){
		cout << "Weighing " << min << " and " << max << endl;
		_numberOfWeighings++;
		return (_coinsArr[min]>_coinsArr[max]) ? min : max;
	}
	int count = noOfCoins / 2;
	int mid = min + count - 1;
	int end = mid + count;
	for (int i=min ; i<=mid ; i++){
		firstHalfSum += _coinsArr[i];
	}
	for (int i=mid+1 ; i<=end ; i++){
		secondHalfSum += _coinsArr[i];
	}
	cout << "Weighing " << min << "-" << mid << " and " << mid+1 << "-" << end << endl;
	_numberOfWeighings++;
	if (firstHalfSum>secondHalfSum){
		result = _divideAndCompare(min,mid);
	} else if (firstHalfSum<secondHalfSum){
		result = _divideAndCompare(mid+1,end);
	} else{
		return end + 1;
	}
	return result;
}

/*
Fake coin is in slot: 1
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 1-4 and 5-8
Weighing 1-2 and 3-4
Weighing 1 and 2
Number of weighings: 6
Fake coin is in slot: 2
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 1-4 and 5-8
Weighing 1-2 and 3-4
Weighing 1 and 2
Number of weighings: 6
Fake coin is in slot: 3
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 1-4 and 5-8
Weighing 1-2 and 3-4
Weighing 3 and 4
Number of weighings: 6
Fake coin is in slot: 4
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 1-4 and 5-8
Weighing 1-2 and 3-4
Weighing 3 and 4
Number of weighings: 6
Fake coin is in slot: 5
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 1-4 and 5-8
Weighing 5-6 and 7-8
Weighing 5 and 6
Number of weighings: 6
Fake coin is in slot: 6
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 1-4 and 5-8
Weighing 5-6 and 7-8
Weighing 5 and 6
Number of weighings: 6
Fake coin is in slot: 7
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 1-4 and 5-8
Weighing 5-6 and 7-8
Weighing 7 and 8
Number of weighings: 6
Fake coin is in slot: 8
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 1-4 and 5-8
Weighing 5-6 and 7-8
Weighing 7 and 8
Number of weighings: 6
Fake coin is in slot: 9
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 9-12 and 13-16
Weighing 9-10 and 11-12
Weighing 9 and 10
Number of weighings: 6
Fake coin is in slot: 10
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 9-12 and 13-16
Weighing 9-10 and 11-12
Weighing 9 and 10
Number of weighings: 6
Fake coin is in slot: 11
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 9-12 and 13-16
Weighing 9-10 and 11-12
Weighing 11 and 12
Number of weighings: 6
Fake coin is in slot: 12
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 9-12 and 13-16
Weighing 9-10 and 11-12
Weighing 11 and 12
Number of weighings: 6
Fake coin is in slot: 13
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 9-12 and 13-16
Weighing 13-14 and 15-16
Weighing 13 and 14
Number of weighings: 6
Fake coin is in slot: 14
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 9-12 and 13-16
Weighing 13-14 and 15-16
Weighing 13 and 14
Number of weighings: 6
Fake coin is in slot: 15
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 9-12 and 13-16
Weighing 13-14 and 15-16
Weighing 15 and 16
Number of weighings: 6
Fake coin is in slot: 16
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Weighing 9-12 and 13-16
Weighing 13-14 and 15-16
Weighing 15 and 16
Number of weighings: 6
Fake coin is in slot: 17
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 1-8 and 9-16
Number of weighings: 3
Fake coin is in slot: 18
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 18-21 and 22-25
Weighing 18-19 and 20-21
Weighing 18 and 19
Number of weighings: 6
Fake coin is in slot: 19
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 18-21 and 22-25
Weighing 18-19 and 20-21
Weighing 18 and 19
Number of weighings: 6
Fake coin is in slot: 20
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 18-21 and 22-25
Weighing 18-19 and 20-21
Weighing 20 and 21
Number of weighings: 6
Fake coin is in slot: 21
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 18-21 and 22-25
Weighing 18-19 and 20-21
Weighing 20 and 21
Number of weighings: 6
Fake coin is in slot: 22
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 18-21 and 22-25
Weighing 22-23 and 24-25
Weighing 22 and 23
Number of weighings: 6
Fake coin is in slot: 23
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 18-21 and 22-25
Weighing 22-23 and 24-25
Weighing 22 and 23
Number of weighings: 6
Fake coin is in slot: 24
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 18-21 and 22-25
Weighing 22-23 and 24-25
Weighing 24 and 25
Number of weighings: 6
Fake coin is in slot: 25
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 18-21 and 22-25
Weighing 22-23 and 24-25
Weighing 24 and 25
Number of weighings: 6
Fake coin is in slot: 26
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 26-29 and 30-33
Weighing 26-27 and 28-29
Weighing 26 and 27
Number of weighings: 6
Fake coin is in slot: 27
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 26-29 and 30-33
Weighing 26-27 and 28-29
Weighing 26 and 27
Number of weighings: 6
Fake coin is in slot: 28
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 26-29 and 30-33
Weighing 26-27 and 28-29
Weighing 28 and 29
Number of weighings: 6
Fake coin is in slot: 29
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 26-29 and 30-33
Weighing 26-27 and 28-29
Weighing 28 and 29
Number of weighings: 6
Fake coin is in slot: 30
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 26-29 and 30-33
Weighing 30-31 and 32-33
Weighing 30 and 31
Number of weighings: 6
Fake coin is in slot: 31
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 26-29 and 30-33
Weighing 30-31 and 32-33
Weighing 30 and 31
Number of weighings: 6
Fake coin is in slot: 32
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 26-29 and 30-33
Weighing 30-31 and 32-33
Weighing 32 and 33
Number of weighings: 6
Fake coin is in slot: 33
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Weighing 26-29 and 30-33
Weighing 30-31 and 32-33
Weighing 32 and 33
Number of weighings: 6
Fake coin is in slot: 34
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Weighing 18-25 and 26-33
Number of weighings: 3
Fake coin is in slot: 35
Weighing 1-35 and 36-70
Weighing 1-17 and 18-34
Number of weighings: 2
Fake coin is in slot: 36
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 36-39 and 40-43
Weighing 36-37 and 38-39
Weighing 36 and 37
Number of weighings: 6
Fake coin is in slot: 37
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 36-39 and 40-43
Weighing 36-37 and 38-39
Weighing 36 and 37
Number of weighings: 6
Fake coin is in slot: 38
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 36-39 and 40-43
Weighing 36-37 and 38-39
Weighing 38 and 39
Number of weighings: 6
Fake coin is in slot: 39
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 36-39 and 40-43
Weighing 36-37 and 38-39
Weighing 38 and 39
Number of weighings: 6
Fake coin is in slot: 40
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 36-39 and 40-43
Weighing 40-41 and 42-43
Weighing 40 and 41
Number of weighings: 6
Fake coin is in slot: 41
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 36-39 and 40-43
Weighing 40-41 and 42-43
Weighing 40 and 41
Number of weighings: 6
Fake coin is in slot: 42
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 36-39 and 40-43
Weighing 40-41 and 42-43
Weighing 42 and 43
Number of weighings: 6
Fake coin is in slot: 43
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 36-39 and 40-43
Weighing 40-41 and 42-43
Weighing 42 and 43
Number of weighings: 6
Fake coin is in slot: 44
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 44-47 and 48-51
Weighing 44-45 and 46-47
Weighing 44 and 45
Number of weighings: 6
Fake coin is in slot: 45
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 44-47 and 48-51
Weighing 44-45 and 46-47
Weighing 44 and 45
Number of weighings: 6
Fake coin is in slot: 46
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 44-47 and 48-51
Weighing 44-45 and 46-47
Weighing 46 and 47
Number of weighings: 6
Fake coin is in slot: 47
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 44-47 and 48-51
Weighing 44-45 and 46-47
Weighing 46 and 47
Number of weighings: 6
Fake coin is in slot: 48
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 44-47 and 48-51
Weighing 48-49 and 50-51
Weighing 48 and 49
Number of weighings: 6
Fake coin is in slot: 49
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 44-47 and 48-51
Weighing 48-49 and 50-51
Weighing 48 and 49
Number of weighings: 6
Fake coin is in slot: 50
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 44-47 and 48-51
Weighing 48-49 and 50-51
Weighing 50 and 51
Number of weighings: 6
Fake coin is in slot: 51
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Weighing 44-47 and 48-51
Weighing 48-49 and 50-51
Weighing 50 and 51
Number of weighings: 6
Fake coin is in slot: 52
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 36-43 and 44-51
Number of weighings: 3
Fake coin is in slot: 53
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 53-56 and 57-60
Weighing 53-54 and 55-56
Weighing 53 and 54
Number of weighings: 6
Fake coin is in slot: 54
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 53-56 and 57-60
Weighing 53-54 and 55-56
Weighing 53 and 54
Number of weighings: 6
Fake coin is in slot: 55
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 53-56 and 57-60
Weighing 53-54 and 55-56
Weighing 55 and 56
Number of weighings: 6
Fake coin is in slot: 56
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 53-56 and 57-60
Weighing 53-54 and 55-56
Weighing 55 and 56
Number of weighings: 6
Fake coin is in slot: 57
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 53-56 and 57-60
Weighing 57-58 and 59-60
Weighing 57 and 58
Number of weighings: 6
Fake coin is in slot: 58
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 53-56 and 57-60
Weighing 57-58 and 59-60
Weighing 57 and 58
Number of weighings: 6
Fake coin is in slot: 59
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 53-56 and 57-60
Weighing 57-58 and 59-60
Weighing 59 and 60
Number of weighings: 6
Fake coin is in slot: 60
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 53-56 and 57-60
Weighing 57-58 and 59-60
Weighing 59 and 60
Number of weighings: 6
Fake coin is in slot: 61
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 61-64 and 65-68
Weighing 61-62 and 63-64
Weighing 61 and 62
Number of weighings: 6
Fake coin is in slot: 62
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 61-64 and 65-68
Weighing 61-62 and 63-64
Weighing 61 and 62
Number of weighings: 6
Fake coin is in slot: 63
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 61-64 and 65-68
Weighing 61-62 and 63-64
Weighing 63 and 64
Number of weighings: 6
Fake coin is in slot: 64
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 61-64 and 65-68
Weighing 61-62 and 63-64
Weighing 63 and 64
Number of weighings: 6
Fake coin is in slot: 65
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 61-64 and 65-68
Weighing 65-66 and 67-68
Weighing 65 and 66
Number of weighings: 6
Fake coin is in slot: 66
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 61-64 and 65-68
Weighing 65-66 and 67-68
Weighing 65 and 66
Number of weighings: 6
Fake coin is in slot: 67
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 61-64 and 65-68
Weighing 65-66 and 67-68
Weighing 67 and 68
Number of weighings: 6
Fake coin is in slot: 68
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Weighing 61-64 and 65-68
Weighing 65-66 and 67-68
Weighing 67 and 68
Number of weighings: 6
Fake coin is in slot: 69
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Weighing 53-60 and 61-68
Number of weighings: 3
Fake coin is in slot: 70
Weighing 1-35 and 36-70
Weighing 36-52 and 53-69
Number of weighings: 2
---------------------------------
Minimum number of weighings: 2
Maximum number of weighings: 6
*/
