//===-- Duke250InstrInfo.h - Duke250 Instruction Information ----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Duke250 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Duke250_Duke250INSTRINFO_H
#define LLVM_LIB_TARGET_Duke250_Duke250INSTRINFO_H

#include "Duke250.h"
#include "Duke250RegisterInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "Duke250GenInstrInfo.inc"

namespace llvm {

class Duke250InstrInfo : public Duke250GenInstrInfo {
public:
  explicit Duke250InstrInfo(const Duke250Subtarget &STI);

protected:
  const Duke250Subtarget &Subtarget;
};
}

#endif // end LLVM_LIB_TARGET_Duke250_Duke250INSTRINFO_H
