//===-- Duke250TargetInfo.cpp - Duke250 Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "TargetInfo/Duke250TargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheDuke250Target() {
  static Target TheDuke250Target;
  return TheDuke250Target;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeDuke250TargetInfo() {
  RegisterTarget<Triple::Duke250> X(getTheDuke250Target(), "Duke250",
                                  "ECE 250", "Duke250");
}
