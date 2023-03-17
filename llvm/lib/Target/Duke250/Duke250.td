//=== Duke250.td - Describe the Duke250 Target Machine ---------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Top tablegen file that pulls in code from the LLVM framework along with
// code specific to this target.
//
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

//===----------------------------------------------------------------------===//
// Calling Conv, Instruction Descriptions, Register information, etc
//===----------------------------------------------------------------------===//

include "Duke250Schedule.td"
include "Duke250RegisterInfo.td"
include "Duke250CallingConv.td"
include "Duke250InstrInfo.td"

def Duke250InstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// Duke250 processors supported
//===----------------------------------------------------------------------===//

def : ProcessorModel<"generic",  NoSchedModel, []>;

//===----------------------------------------------------------------------===//
// Duke250 Target declaration
//===----------------------------------------------------------------------===//

def Duke250 : Target {
  let InstructionSet = Duke250InstrInfo;
}

/*
cmake -G "Ninja" -DLLVM_ENABLE_PROJECTS="clang" -DLLVM_TARGETS_TO_BUILD="ARM;Lanai;RISCV" -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD="Duke250" -DCMAKE_BUILD_TYPE="Debug" -DLLVM_ENABLE_ASSERTIONS=On ../llvm
*/
