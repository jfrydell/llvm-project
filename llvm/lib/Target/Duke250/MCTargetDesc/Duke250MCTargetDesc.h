//===-- Duke250MCTargetDesc.h - Duke250 Target Descriptions ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Duke250 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Duke250_MCTARGETDESC_Duke250MCTARGETDESC_H
#define LLVM_LIB_TARGET_Duke250_MCTARGETDESC_Duke250MCTARGETDESC_H

#include "Duke250BaseInfo.h"

// Defines symbolic names for Duke250 registers. This defines a mapping from
// register name to register number.
#define GET_REGINFO_ENUM
#include "Duke250GenRegisterInfo.inc"

// Defines symbolic names for the Duke250 instructions.
#define GET_INSTRINFO_ENUM
#include "Duke250GenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "Duke250GenSubtargetInfo.inc"

#endif // end LLVM_LIB_TARGET_Duke250_MCTARGETDESC_Duke250MCTARGETDESC_H
