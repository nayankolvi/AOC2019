/*
 * COperation.cpp
 *
 *  Created on: 16-Nov-2022
 *      Author: nayan
 */

#include "COperation.h"
#include <iostream>


COperation::COperation(int operation, int locOp1, int locOp2, int locResult)
{
	m_locResult = locResult;
	m_locOp2 = locOp2;
	m_locOp1 = locOp1;
	m_operation = operation;
}

COperation::operationStatus COperation::performOperation(long* array, int* currentPos)
{
	m_operation = array[*currentPos];
	m_locOp1 = array[*currentPos + 1];
	m_locOp2 = array[*currentPos + 2];
	m_locResult = array[*currentPos + 3];

	if(m_operation == 1)
	{
		addAndStore(array);
	}
	else if(m_operation == 2)
	{
		multiplyAndStore(array);
	}
	else if(m_operation == 99)
	{
		return e_stop;
	}
	else
	{
		return e_continue;
	}

	*currentPos =  *currentPos + 4;
	return e_continue;

}

void COperation::addAndStore(long *array)
{
	int opVal1 = array[m_locOp1];
	int opVal2 = array[m_locOp2];

	int result = opVal1 + opVal2 ;

	array[m_locResult] = result;
}

void COperation::multiplyAndStore(long *array)
{
	int opVal1 = array[m_locOp1];
	int opVal2 = array[m_locOp2];

	int result = opVal1 * opVal2 ;

	array[m_locResult] = result;
}

COperation::~COperation()
{
	// TODO Auto-generated destructor stub
}

