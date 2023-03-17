//===-- Duke250InstrInfo.cpp - Duke250 Instruction Information ----------------===//
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

#include "Duke250InstrInfo.h"

#include "Duke250TargetMachine.h"
#include "Duke250MachineFunction.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/Debug.h"

using namespace llvm;

#define DEBUG_TYPE "Duke250-instrinfo"

#define GET_INSTRINFO_CTOR_DTOR
#include "Duke250GenInstrInfo.inc"

Duke250InstrInfo::Duke250InstrInfo(const Duke250Subtarget &STI)
    : Duke250GenInstrInfo(Duke250::ADJCALLSTACKDOWN, Duke250::ADJCALLSTACKUP),
      Subtarget(STI)
{
}
