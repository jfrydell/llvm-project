; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc  -O0 -mtriple=mipsel-linux-gnu -global-isel  -verify-machineinstrs %s -o -| FileCheck %s -check-prefixes=MIPS32

define void @store_i32(i32 %val, i32* %ptr)  {
; MIPS32-LABEL: store_i32:
; MIPS32:       # %bb.0: # %entry
; MIPS32-NEXT:    sw $4, 0($5)
; MIPS32-NEXT:    jr $ra
; MIPS32-NEXT:    nop
entry:
  store i32 %val, i32* %ptr
  ret void
}

define void @store_i64(i64 %val, i64* %ptr)  {
; MIPS32-LABEL: store_i64:
; MIPS32:       # %bb.0: # %entry
; MIPS32-NEXT:    sw $4, 0($6)
; MIPS32-NEXT:    ori $1, $zero, 4
; MIPS32-NEXT:    addu $1, $6, $1
; MIPS32-NEXT:    sw $5, 0($1)
; MIPS32-NEXT:    jr $ra
; MIPS32-NEXT:    nop
entry:
  store i64 %val, i64* %ptr
  ret void
}