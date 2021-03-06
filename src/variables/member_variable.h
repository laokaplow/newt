/*
 * member_variable.h
 *
 *  Created on: Aug 29, 2015
 *      Author: caleb
 */

#ifndef MEMBER_VARIABLE_H_
#define MEMBER_VARIABLE_H_

#include <variable.h>
#include <assignment_type.h>

class MemberVariable: public Variable {
public:
	MemberVariable(const Variable* container_variable,
			const Variable* member_variable);
	virtual ~MemberVariable();

	virtual const TypeSpecifier* GetType(const ExecutionContext* context) const;

	virtual const string* ToString(const ExecutionContext* context) const;

	virtual const LinkedList<const Error*>* Validate(
			const ExecutionContext* context) const;

	virtual const Result* Evaluate(const ExecutionContext* context) const;

	virtual const LinkedList<const Error*>* AssignValue(
			const ExecutionContext* context, const Expression* expression,
			const AssignmentType op) const;

	const Variable* GetContainer() const {
		return m_container;
	}

	const Variable* GetMemberVariable() const {
		return m_member_variable;
	}

protected:
	virtual const LinkedList<const Error*>* SetSymbol(
			const ExecutionContext* context, const bool* value) const;

	virtual const LinkedList<const Error*>* SetSymbol(
			const ExecutionContext* context, const int* value) const;

	virtual const LinkedList<const Error*>* SetSymbol(
			const ExecutionContext* context, const double* value) const;

	virtual const LinkedList<const Error*>* SetSymbol(
			const ExecutionContext* context, const string* value) const;

	virtual const LinkedList<const Error*>* SetSymbol(
			const ExecutionContext* context, const Array* value) const;

	virtual const LinkedList<const Error*>* SetSymbol(
			const ExecutionContext* context,
			const CompoundTypeInstance* value) const;

private:
	const Variable* m_container;
	const Variable* m_member_variable;
};

#endif /* MEMBER_VARIABLE_H_ */
