int A[10], B[11];
int * bar();

void foo() {
  for (int I = 0; I < 10; ++I) {
    int *X;
    if (I > 10)
      X = bar();
    A[I] = A[I] + 1;
    B[I+1] = B[I] + 1;
    if (I > 10)
      X[0] = I;
  }
}
//CHECK: Printing analysis 'Dependency Analysis (Metadata)' for function 'foo':
//CHECK:  loop at depth 1 redundant_4.c:5:3
//CHECK:    output:
//CHECK:     <A, 40> <B, 44> <X[0]:{12:7|6:10}, 4> bar():8:11 | <X:6:10, 8>
//CHECK:    anti:
//CHECK:     <A, 40> <B, 44> <X[0]:{12:7|6:10}, 4> bar():8:11 | <X:6:10, 8>
//CHECK:    flow:
//CHECK:     <A, 40> <B, 44>:[1,1] <X[0]:{12:7|6:10}, 4> bar():8:11 | <X:6:10, 8>
//CHECK:    induction:
//CHECK:     <I:5:12, 4>:[Int,0,10,1]
//CHECK:    redundant:
//CHECK:     <A, 40> <B, 44> <X[0]:{12:7|6:10}, 4> bar():8:11
//CHECK:    lock:
//CHECK:     <I:5:12, 4>
//CHECK:    header access:
//CHECK:     <A, 40> <B, 44> <X[0]:{12:7|6:10}, 4> bar():8:11 | <I:5:12, 4>
//CHECK:    explicit access:
//CHECK:     <A, 40> <B, 44> <X[0]:{12:7|6:10}, 4> bar():8:11 | <I:5:12, 4> | <X:6:10, 8>
//CHECK:    explicit access (separate):
//CHECK:     <I:5:12, 4> <X:6:10, 8> <X[0]:{12:7|6:10}, 4> bar():8:11
//CHECK:    redundant (separate):
//CHECK:     <X[0]:{12:7|6:10}, 4> bar():8:11
//REDUNDANT: Printing analysis 'Dependency Analysis (Metadata)' for function 'foo':
//REDUNDANT:  loop at depth 1 redundant_4.c:5:3
//REDUNDANT:    shared:
//REDUNDANT:     <A, 40>
//REDUNDANT:    output:
//REDUNDANT:     <X:6:10, 8>
//REDUNDANT:    anti:
//REDUNDANT:     <X:6:10, 8>
//REDUNDANT:    flow:
//REDUNDANT:     <B, 44>:[1,1] | <X:6:10, 8>
//REDUNDANT:    induction:
//REDUNDANT:     <I:5:12, 4>:[Int,0,10,1]
//REDUNDANT:    redundant:
//REDUNDANT:     <A, 40> <B, 44> <X[0]:{12:7|6:10}, 4> bar():8:11
//REDUNDANT:    lock:
//REDUNDANT:     <I:5:12, 4>
//REDUNDANT:    header access:
//REDUNDANT:     <A, 40> | <B, 44> | <I:5:12, 4>
//REDUNDANT:    explicit access:
//REDUNDANT:     <I:5:12, 4> | <X:6:10, 8>
//REDUNDANT:    explicit access (separate):
//REDUNDANT:     <I:5:12, 4> <X:6:10, 8> <X[0]:{12:7|6:10}, 4> bar():8:11
//REDUNDANT:    redundant (separate):
//REDUNDANT:     <X[0]:{12:7|6:10}, 4> bar():8:11