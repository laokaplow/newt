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

#ifndef STATEMENTS_INFERRED_DECLARATION_STATEMENT_H_
#define STATEMENTS_INFERRED_DECLARATION_STATEMENT_H_

#include <declaration_statement.h>
#include <yyltype.h>
#include <string>

class Expression;
class TypeSpecifier;

class InferredDeclarationStatement: public DeclarationStatement {
public:
	InferredDeclarationStatement(const YYLTYPE position,
			const std::string* name, const YYLTYPE name_position,
			const Expression* initializer_expression);
	virtual ~InferredDeclarationStatement();

	virtual const LinkedList<const Error*>* preprocess(
			const ExecutionContext* execution_context) const;

	virtual const LinkedList<const Error*>* execute(
			ExecutionContext* execution_context) const;

	virtual const Expression* GetInitializerExpression() const;

	virtual const DeclarationStatement* WithInitializerExpression(
			const Expression* expression) const;

	virtual const TypeSpecifier* GetType() const;
	virtual const std::string* GetName() const;

	virtual const AnalysisResult Returns(
			const TypeSpecifier* type_specifier) const {
		return AnalysisResult::NO;
	}

private:
	const std::string* m_name;
	const YYLTYPE m_name_position;
	const Expression* m_initializer_expression;
};

#endif /* STATEMENTS_INFERRED_DECLARATION_STATEMENT_H_ */
