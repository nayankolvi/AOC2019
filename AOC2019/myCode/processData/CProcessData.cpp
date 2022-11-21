/*
 * CProcessData.cpp
 *
 *  Created on: 16-Nov-2022
 *      Author: nayan
 */

#include "CProcessData.h"

using namespace std;

CProcessData::CProcessData(std::string data)
{
	m_data = data;
}

void CProcessData::dataProcessIntCode()
{
	int startPos = 0;
	int endPos = 0;

	for (auto const& val : m_data)
	{
		if(val ==  ',')
		{
			m_result.push_back(std::stoi(m_data.substr(startPos, endPos-startPos)));
			startPos = endPos + 1;
		}

		endPos = endPos + 1;
	}
	m_result.push_back(std::stoi(m_data.substr(startPos, endPos-startPos)));
}

void CProcessData::print()
{
	for(auto const& v : m_result)
	{
		cout << v << endl;
	}
}

CProcessData::~CProcessData()
{
	// TODO Auto-generated destructor stub
}

const std::string& CProcessData::getMData() const
{
	return m_data;
}

const std::vector<int>& CProcessData::getMResult() const
{
	return m_result;
}
