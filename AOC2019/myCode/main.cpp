// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
#include "FileOperation/CFileRead.h"
#include "processData/CProcessData.h"
#include "IntCode/COperation.h"

typedef enum {task1, task2} taskType;

// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "AOC2019 started." << endl << endl;

	long* data;

	int arrayIndex = 0;
	int currentPos = 0;
	std::vector<int> processedData;

	taskType task = taskType::task2;



	CFileRead fileRead("day2.txt");
	fileRead.readFromFile();

	CProcessData processData(fileRead.getMData());
	processData.dataProcessIntCode();
	processedData = processData.getMResult();

	data = new long[processedData.size()+1];

	for(auto const& val : processedData)
	{
		data[arrayIndex] = val;
		arrayIndex = arrayIndex + 1;
	}

	COperation intCode;
	auto ret = intCode.e_continue;

	//requirement
	if(task == taskType::task1)
	{
		data[1] = 12;
		data[2] = 2;

		while(ret != intCode.e_stop)
		{
			ret = intCode.performOperation(data, &currentPos);

		}

		cout << "Output of Task1 is: " << data[0] << endl;
	}

	while(task == taskType::task2)
	{
		static int noun = 0;
		static int verb = 1;

		arrayIndex = 0;
		currentPos = 0;

		for(auto const& val : processedData)
		{
			data[arrayIndex] = val;
			arrayIndex = arrayIndex + 1;
		}





		noun = noun + 1;
		if(noun == 99)
		{
			noun = 1;
			verb = verb + 1;
		}

		data[1] = noun;
		data[2] = verb;



		while(ret != intCode.e_stop)
		{
			ret = intCode.performOperation(data, &currentPos);
		}
		cout << data[0] << endl;


		if(data[0] == 19690720)
		{
			cout << "Output of Task2 is: " << noun*100 + verb << endl;
			break;
		}

		if(noun == 65 && verb == 77)
		{
			cout << "Output of Task2 is: " << noun*100 + verb <<  data[0] << endl;

		}

	}





	delete[] data;


	return 0;
}
