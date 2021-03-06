/*
 Copyright (C) 2015 The newt Authors.

 This file is part of newt.

 newt is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 newt is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with newt.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EXPRESSIONS_CONSTANT_EXPRESSION_H_
#define EXPRESSIONS_CONSTANT_EXPRESSION_H_

#include <string>

#include "expression.h"

class ConstantExpression: public Expression {
public:
	ConstantExpression(const YYLTYPE position, const bool value);
	ConstantExpression(const YYLTYPE position, const int value);
	ConstantExpression(const YYLTYPE position, const double value);
	ConstantExpression(const YYLTYPE position, const std::string* value);
	const static ConstantExpression* GetDefaultExpression(
			const TypeSpecifier* type, const TypeTable* type_table);

	virtual const TypeSpecifier* GetType(
			const ExecutionContext* execution_context) const;

	virtual const Result* Evaluate(
			const ExecutionContext* execution_context) const;

	virtual const bool IsConstant() const {
		return true;
	}

	virtual const LinkedList<const Error*>* Validate(
			const ExecutionContext* execution_context) const;

	static const Result* GetConstantExpression(const Expression* expression,
			const ExecutionContext* execution_context);

private:
	ConstantExpression(const YYLTYPE position, const TypeSpecifier* type,
			const void* value);
	const TypeSpecifier* m_type;
	const void* m_value;
};

#endif /* EXPRESSIONS_CONSTANT_EXPRESSION_H_ */
