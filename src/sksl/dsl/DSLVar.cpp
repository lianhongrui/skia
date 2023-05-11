/*
 * Copyright 2020 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "src/sksl/dsl/DSLVar.h"

#include "include/core/SkTypes.h"
#include "src/sksl/SkSLContext.h"
#include "src/sksl/SkSLThreadContext.h"
#include "src/sksl/dsl/DSLModifiers.h"
#include "src/sksl/dsl/DSLType.h"
#include "src/sksl/ir/SkSLExpression.h"
#include "src/sksl/ir/SkSLStatement.h"
#include "src/sksl/ir/SkSLSymbol.h"
#include "src/sksl/ir/SkSLSymbolTable.h"  // IWYU pragma: keep
#include "src/sksl/ir/SkSLVariable.h"

#include <type_traits>
#include <utility>

namespace SkSL {
namespace dsl {

/**
 * DSLVarBase
 */

DSLVarBase::DSLVarBase(VariableStorage storage, DSLType type, std::string_view name,
                       DSLExpression initialValue, Position pos, Position namePos)
    : DSLVarBase(storage, DSLModifiers(), std::move(type), name, std::move(initialValue),
                 pos, namePos) {}

DSLVarBase::DSLVarBase(VariableStorage storage, const DSLModifiers& modifiers, DSLType type,
                       std::string_view name, DSLExpression initialValue, Position pos,
                       Position namePos)
    : fModifiers(std::move(modifiers))
    , fType(std::move(type))
    , fNamePosition(namePos)
    , fName(name)
    , fInitialValue(std::move(initialValue))
    , fPosition(pos)
    , fStorage(storage) {}

void DSLVarBase::swap(DSLVarBase& other) {
    SkASSERT(this->storage() == other.storage());
    std::swap(fModifiers, other.fModifiers);
    std::swap(fType, other.fType);
    std::swap(fDeclaration, other.fDeclaration);
    std::swap(fVar, other.fVar);
    std::swap(fNamePosition, other.fNamePosition);
    std::swap(fName, other.fName);
    std::swap(fInitialValue.fExpression, other.fInitialValue.fExpression);
    std::swap(fInitialized, other.fInitialized);
    std::swap(fPosition, other.fPosition);
}

/**
 * DSLVar
 */

DSLVar::DSLVar() : DSLVarBase(SkSL::VariableStorage::kLocal) {}

DSLVar::DSLVar(DSLType type, std::string_view name, DSLExpression initialValue,
               Position pos, Position namePos)
        : INHERITED(SkSL::VariableStorage::kLocal, type, name, std::move(initialValue),
                    pos, namePos) {}

DSLVar::DSLVar(const DSLModifiers& modifiers, DSLType type, std::string_view name,
               DSLExpression initialValue, Position pos, Position namePos)
        : INHERITED(SkSL::VariableStorage::kLocal, modifiers, type, name, std::move(initialValue),
                    pos, namePos) {}

void DSLVar::swap(DSLVar& other) {
    INHERITED::swap(other);
}

/**
 * DSLGlobalVar
 */

DSLGlobalVar::DSLGlobalVar() : DSLVarBase(SkSL::VariableStorage::kGlobal) {}

DSLGlobalVar::DSLGlobalVar(DSLType type, std::string_view name, DSLExpression initialValue,
                           Position pos, Position namePos)
        : INHERITED(SkSL::VariableStorage::kGlobal, type, name, std::move(initialValue),
                    pos, namePos) {}

DSLGlobalVar::DSLGlobalVar(const DSLModifiers& modifiers, DSLType type, std::string_view name,
                           DSLExpression initialValue, Position pos, Position namePos)
        : INHERITED(SkSL::VariableStorage::kGlobal, modifiers, type, name, std::move(initialValue),
                    pos, namePos) {}

DSLGlobalVar::DSLGlobalVar(const char* name)
    : INHERITED(SkSL::VariableStorage::kGlobal, kVoid_Type, name, DSLExpression(),
                Position(), Position()) {
    fName = name;
    SkSL::Context& context = ThreadContext::Context();
    SkSL::Symbol* result = context.fSymbolTable->findMutable(fName);
    SkASSERTF(result, "could not find '%.*s' in symbol table", (int)fName.length(), fName.data());
    fVar = &result->as<SkSL::Variable>();
    fInitialized = true;
}

void DSLGlobalVar::swap(DSLGlobalVar& other) {
    INHERITED::swap(other);
}

/**
 * DSLParameter
 */

DSLParameter::DSLParameter() : DSLVarBase(SkSL::VariableStorage::kParameter) {}

DSLParameter::DSLParameter(DSLType type, std::string_view name, Position pos, Position namePos)
        : INHERITED(SkSL::VariableStorage::kParameter, type, name, DSLExpression(), pos, namePos) {}

DSLParameter::DSLParameter(const DSLModifiers& modifiers, DSLType type, std::string_view name,
                           Position pos, Position namePos)
        : INHERITED(SkSL::VariableStorage::kParameter, modifiers, type, name, DSLExpression(),
                    pos, namePos) {}

void DSLParameter::swap(DSLParameter& other) {
    INHERITED::swap(other);
}

} // namespace dsl
} // namespace SkSL
