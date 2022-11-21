/*
 * CProcessData.h
 *
 *  Created on: 16-Nov-2022
 *      Author: nayan
 */

#ifndef INTCODE_CPROCESSDATA_H_
#define INTCODE_CPROCESSDATA_H_

#include <string>
#include <iostream>
#include <vector>


class CProcessData
{
private:
	std::string m_data;
	std::vector<int> m_result;


public:
	CProcessData(std::string data = "");
	void dataProcessIntCode();

	void print();
	virtual ~CProcessData();
	const std::string& getMData() const;
	const std::vector<int>& getMResult() const;
};

#endif /* INTCODE_CPROCESSDATA_H_ */
