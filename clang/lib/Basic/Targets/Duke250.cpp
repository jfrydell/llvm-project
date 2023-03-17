//===--- Duke250.cpp - Implement Duke250 target feature support ---------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements Duke250TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "Duke250.h"
#include "clang/Basic/MacroBuilder.h"
#include "llvm/ADT/StringSwitch.h"

using namespace clang;
using namespace clang::targets;

const char *const Duke250TargetInfo::GCCRegNames[] = {
  // Integer registers
  "r0",  "r1",  "r2",  "r3",  "r4",  "r5",  "r6",  "r7",
};

const TargetInfo::GCCRegAlias GCCRegAliases[] = {
  {{"zero"}, "r0"}, {{"ra"}, "r1"},   {{"sp"}, "r2"},    {{"gp"}, "r3"},
  {{"tp"}, "r4"},   {{"t0"}, "r5"},   {{"t1"}, "r6"},    {{"t2"}, "r7"}};

ArrayRef<const char *> Duke250TargetInfo::getGCCRegNames() const {
  return llvm::makeArrayRef(GCCRegNames);
}

ArrayRef<TargetInfo::GCCRegAlias> Duke250TargetInfo::getGCCRegAliases() const {
  return llvm::makeArrayRef(GCCRegAliases);
}

void Duke250TargetInfo::getTargetDefines(const LangOptions &Opts,
                                       MacroBuilder &Builder) const {
  // Define the __Duke250__ macro when building for this target
  Builder.defineMacro("__Duke250__");
}
