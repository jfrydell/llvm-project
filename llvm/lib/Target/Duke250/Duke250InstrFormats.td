//=== Duke250InstrFormats.td - Duke250 Instruction Formats -----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//
//  These instruction format definitions are structured to match the
//  description in the RISC-V User-Level ISA specification as closely as
//  possible. For instance, the specification describes instructions with the
//  MSB (31st bit) on the left and the LSB (0th bit) on the right. This is
//  reflected in the order of parameters to each instruction class.
//
//  One area of divergence is in the description of immediates. The
//  specification describes immediate encoding in terms of bit-slicing
//  operations on the logical value represented. The immediate argument to
//  these instruction formats instead represents the bit sequence that will be
//  inserted into the instruction. e.g. although JAL's immediate is logically
//  a 21-bit value (where the LSB is always zero), we describe it as an imm20
//  to match how it is encoded.
//
//===----------------------------------------------------------------------===//

// Format specifies the encoding used by the instruction. This is used by
// Duke250MCCodeEmitter to determine which form of fixup to use. These
// definitions must be kept in-sync with Duke250BaseInfo.h.
class InstFormat<bits<5> val> {
  bits<5> Value = val;
}
def InstFormatPseudo : InstFormat<0>;
def InstFormatR      : InstFormat<1>;
def InstFormatR4     : InstFormat<2>;
def InstFormatI      : InstFormat<3>;
def InstFormatS      : InstFormat<4>;
def InstFormatB      : InstFormat<5>;
def InstFormatU      : InstFormat<6>;
def InstFormatJ      : InstFormat<7>;
def InstFormatCR     : InstFormat<8>;
def InstFormatCI     : InstFormat<9>;
def InstFormatCSS    : InstFormat<10>;
def InstFormatCIW    : InstFormat<11>;
def InstFormatCL     : InstFormat<12>;
def InstFormatCS     : InstFormat<13>;
def InstFormatCA     : InstFormat<14>;
def InstFormatCB     : InstFormat<15>;
def InstFormatCJ     : InstFormat<16>;
def InstFormatOther  : InstFormat<17>;


/*

// The following opcode names match those given in Table 19.1 in the
// RISC-V User-level ISA specification ("RISC-V base opcode map").
class Duke250Opcode<bits<4> val> {
  bits<4> Value = val;
}

DUKE_TODO: What are these for? I think because funct bits are used for actual op, so these give categories

def OPC_LOAD      : Duke250Opcode<0b0000011>;
def OPC_LOAD_FP   : Duke250Opcode<0b0000111>;
def OPC_MISC_MEM  : Duke250Opcode<0b0001111>;
def OPC_OP_IMM    : Duke250Opcode<0b0010011>;
def OPC_AUIPC     : Duke250Opcode<0b0010111>;
def OPC_OP_IMM_32 : Duke250Opcode<0b0011011>;
def OPC_STORE     : Duke250Opcode<0b0100011>;
def OPC_STORE_FP  : Duke250Opcode<0b0100111>;
def OPC_AMO       : Duke250Opcode<0b0101111>;
def OPC_OP        : Duke250Opcode<0b0110011>;
def OPC_LUI       : Duke250Opcode<0b0110111>;
def OPC_OP_32     : Duke250Opcode<0b0111011>;
def OPC_MADD      : Duke250Opcode<0b1000011>;
def OPC_MSUB      : Duke250Opcode<0b1000111>;
def OPC_NMSUB     : Duke250Opcode<0b1001011>;
def OPC_NMADD     : Duke250Opcode<0b1001111>;
def OPC_OP_FP     : Duke250Opcode<0b1010011>;
def OPC_BRANCH    : Duke250Opcode<0b1100011>;
def OPC_JALR      : Duke250Opcode<0b1100111>;
def OPC_JAL       : Duke250Opcode<0b1101111>;
def OPC_SYSTEM    : Duke250Opcode<0b1110011>;
*/

class RWInst<dag outs, dag ins, string opcodestr, string argstr,
             list<dag> pattern, InstFormat format>
    : Instruction {
  field bits<32> Inst;
  // SoftFail is a field the disassembler can use to provide a way for
  // instructions to not match without killing the whole decode process. It is
  // mainly used for ARM, but Tablegen expects this field to exist or it fails
  // to build the decode table.
  field bits<32> SoftFail = 0;
  let Size = 2;

  bits<4> Opcode = 0;

  let Inst{15-12} = Opcode;

  let Namespace = "Duke250";

  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString = opcodestr # "\t" # argstr;
  let Pattern = pattern;

  let TSFlags{4-0} = format.Value;
}

// Pseudo instructions
class Pseudo<dag outs, dag ins, list<dag> pattern, string opcodestr = "",
             string argstr = "">
    : RWInst<outs, ins, opcodestr, argstr, pattern, InstFormatPseudo>,
      Sched<[]> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}

// Instruction formats are listed in the order they appear in the RISC-V
// instruction set manual (R, I, S, B, U, J) with sub-formats (e.g. RWInstR4,
// RWInstRAtomic) sorted alphabetically.

class RWInstR<bits<4> opcode, dag outs,
              dag ins, string opcodestr, string argstr>
    : RWInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<3> rs = 0;
  bits<3> rd = 0;
  bits<3> rt = 0;
  bits<3> shamt = 0;

  let Inst{11-9} = rs;
  let Inst{8-6} = rt;
  let Inst{5-3} = rd;
  let Inst{2-0} = shamt;
  
  let Opcode = opcode;
}

class RWInstI<bits<4> opcode, dag outs, dag ins,
              string opcodestr, string argstr>
    : RWInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<3> rs;
  bits<3> rt;
  bits<6> imm6;

  let Inst{11-9} = rs;
  let Inst{8-6} = rt;
  let Inst{5-0} = imm6;
  
  let Opcode = opcode;
}

class RWInstJ<bits<4> opcode, dag outs, dag ins, string opcodestr,
              string argstr>
    : RWInst<outs, ins, opcodestr, argstr, [], InstFormatU> {
  bits<12> imm12;

  let Inst{11-0} = imm12;
  
  let Opcode = opcode;
}
