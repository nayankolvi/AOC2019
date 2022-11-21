/*
 * COperation.h
 *
 *  Created on: 16-Nov-2022
 *      Author: nayan
 */

#ifndef INTCODE_COPERATION_H_
#define INTCODE_COPERATION_H_

class COperation
{
	int m_operation;
	int m_locOp1;
	int m_locOp2;
	int m_locResult;
public:
	enum operationStatus{e_continue, e_stop};

	COperation(int operation = 0, int locOp1 = 0, int locOp2 = 0, int  locResult = 0);
	operationStatus performOperation(long* array, int* currentPos);
	void addAndStore(long* array);
	void multiplyAndStore(long* array);
	virtual ~COperation();
};

#endif /* INTCODE_COPERATION_H_ */
