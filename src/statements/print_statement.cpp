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

#include <expression.h>
#include "print_statement.h"
#include <defaults.h>

PrintStatement::PrintStatement(const int line_number,
		const Expression* expression) :
		m_line_number(line_number), m_expression(expression) {
}

PrintStatement::~PrintStatement() {
}

const LinkedList<const Error*>* PrintStatement::execute(
		ExecutionContext* execution_context) const {
	const LinkedList<const Error*>* errors =
			LinkedList<const Error*>::Terminator;

	const Result* string_result = m_expression->ToString(execution_context);
	errors = string_result->GetErrors();

	if (errors == LinkedList<const Error*>::Terminator) {
		std::cout << *((string*) string_result->GetData()) << "\n";
	}

	return errors;
}
