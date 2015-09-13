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

#ifndef PRIMITIVE_TYPE_SPECIFIER_H_
#define PRIMITIVE_TYPE_SPECIFIER_H_

#include <type_specifier.h>
#include <assert.h>
#include <sstream>
#include <defaults.h>
#include <type.h>

class PrimitiveTypeSpecifier: public TypeSpecifier {
public:
	virtual ~PrimitiveTypeSpecifier() {
	}

	virtual const string ToString() const {
		return type_to_string(m_basic_type);
	}

	const string ToString(const void* value) const;

	virtual const bool IsAssignableTo(const TypeSpecifier* other) const;

	virtual const void* DefaultValue(const TypeTable* type_table) const;

	const BasicType GetBasicType() const {
		return m_basic_type;
	}

	static const PrimitiveTypeSpecifier* GetNone();

	static const PrimitiveTypeSpecifier* GetBoolean();

	static const PrimitiveTypeSpecifier* GetInt();

	static const PrimitiveTypeSpecifier* GetDouble();

	static const PrimitiveTypeSpecifier* GetString();

	static const PrimitiveTypeSpecifier* GetArray();

//	static const PrimitiveTypeSpecifier* GetCompound();

private:
	PrimitiveTypeSpecifier(const BasicType basic_type) :
			m_basic_type(basic_type) {
	}

	const BasicType m_basic_type;
};

#endif /* PRIMITIVE_TYPE_SPECIFIER_H_ */