//===-- Duke250RegisterInfo.td - Duke250 Register defs ---------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the RISC-W register file
//===----------------------------------------------------------------------===//

let Namespace = "Duke250" in {
class Duke250Reg<bits<3> Enc, string n, list<string> alt = []> : Register<n> {
  let HWEncoding{2-0} = Enc;
  let AltNames = alt;
}
} // end Namespace

def r0 : Duke250Reg<0, "r0", []>, DwarfRegNum<[0]>;
def r1 : Duke250Reg<1, "r1", []>, DwarfRegNum<[1]>;
def r2 : Duke250Reg<2, "r2", []>, DwarfRegNum<[2]>;
def r3 : Duke250Reg<3, "r3", []>, DwarfRegNum<[3]>;
def r4 : Duke250Reg<4, "r4", []>, DwarfRegNum<[4]>;
def r5 : Duke250Reg<5, "r5", []>, DwarfRegNum<[5]>;
def r6 : Duke250Reg<6, "r6", []>, DwarfRegNum<[6]>;
def r7 : Duke250Reg<7, "r7", []>, DwarfRegNum<[7]>;

// The order of registers represents the preferred allocation sequence.
// Registers are listed in the order caller-save, callee-save, specials.
def GPR : RegisterClass<"Duke250", [i16], 16, (add
    (sequence "r%u", 1, 7), r0
  )>;

def SP : RegisterClass<"Duke250", [i16], 16, (add r6)>;
def LR : RegisterClass<"Duke250", [i16], 16, (add r7)>;
