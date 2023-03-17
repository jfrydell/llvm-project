//=== Duke250CallingConv.td - Calling Conventions for Duke250 --*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for Duke250 architecture.
//===----------------------------------------------------------------------===//

def Duke250_CCallingConv : CallingConv<[
  // Handles byval parameters. Tell LLVM what the size and alignment
  // requirements of each stack slot are
  CCIfByVal<CCPassByVal<2, 2>>,

  // Promote i8 to i32
  CCIfType<[i1, i8], CCPromoteToType<i16>>,

  // The first 4 arguments are passed in r1, r2, r3, r4
  CCIfType<[i16], CCAssignToReg<[r1, r2, r3, r4]>>,

  // Integer values get stored in stack slots that are 2 bytes in size and
  // 2-byte aligned
  CCIfType<[i16], CCAssignToStack<2, 2>>
]>;

// BeyondRISC C Return Convention
def Duke250_CRetConv : CallingConv<[
  CCIfType<[i1, i8], CCPromoteToType<i16>>,

  // i16 are returned in registers r1, r2
  CCIfType<[i16], CCAssignToReg<[r1, r2]>>,

  // Integer values get stored in stack slots that are 2 bytes in size and
  // 2-byte aligned
  CCIfType<[i16], CCAssignToStack<2, 2>>
]>;

def Duke250_CalleeSavedRegs : CalleeSavedRegs<(add r5)>;
