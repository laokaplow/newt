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

#include "statement_block.h"

#include <assert.h>
#include "statement.h"
#include "statement_list.h"
#include <execution_context.h>
#include <type_specifier.h>

using namespace std;

StatementBlock::StatementBlock(const LinkedList<const Statement*>* statements) :
		m_statements(statements) {
}

bool StatementBlock::empty() {
	return m_statements == StatementList::Terminator;
}

const LinkedList<const Error*>* StatementBlock::preprocess(
		const ExecutionContext* execution_context) const {
	const LinkedList<const Error*>* errors =
			LinkedList<const Error*>::Terminator;
	const LinkedList<const Statement*>* subject = m_statements;
	while (subject != LinkedList<const Statement*>::Terminator) {
		const Statement* statement = subject->GetData();
		//TODO: handle nested statement blocks
		const LinkedList<const Error*>* statement_errors =
				statement->preprocess(execution_context);
		errors = errors->Concatenate(statement_errors, true);

		subject = subject->GetNext();
	}

	return errors;
}

const LinkedList<const Error*>* StatementBlock::execute(
		ExecutionContext* execution_context) const {
	const LinkedList<const Statement*>* list = m_statements;
	while (list != StatementList::Terminator) {
		const Statement* statement = list->GetData();
		auto errors = statement->execute(execution_context);
		if (errors != LinkedList<const Error*>::Terminator
				|| execution_context->GetReturnValue() != nullptr) {
			return errors;
		}
		list = (LinkedList<const Statement*>*) list->GetNext();
	}

	return LinkedList<const Error*>::Terminator;
}

const AnalysisResult StatementBlock::Returns(
		const TypeSpecifier* type_specifier,
		const ExecutionContext* execution_context) const {
	AnalysisResult result = AnalysisResult::NO;
	const LinkedList<const Statement*>* list = m_statements;
	while (list != StatementList::Terminator) {
		const Statement* statement = list->GetData();
		result = static_cast<AnalysisResult>(result
				| statement->Returns(type_specifier, execution_context));
		list = (LinkedList<const Statement*>*) list->GetNext();
	}

	return result;
}

