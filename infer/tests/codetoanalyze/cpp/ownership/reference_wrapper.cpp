/*
 * Copyright (c) 2018-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */
struct B {
  B(int v) : f(v){};
  int f;
};

struct A {
  A(int f) { b = new B(f); }
  B* b;
  B* getb() { return b; };
  ~A() { delete b; }
};

struct ReferenceWrapperHeap {
  ReferenceWrapperHeap(A& a) : b(a.getb()){};
  B* b;
};

ReferenceWrapperHeap getwrapperHeap() {
  A a(1);
  return a; // We store a.b in ReferenceWrapper, but we delete a.b in the
            // destructor of A
}

int FN_reference_wrapper_heap_bad() {
  ReferenceWrapperHeap rw = getwrapperHeap();
  return rw.b->f; // we want to report use after lifetime bug here
}

struct ReferenceWrapperStack {
  ReferenceWrapperStack(B& bref) : b(&bref){};
  B* b;
};

ReferenceWrapperStack getwrapperStack() {
  B b(1);
  return b;
}

int FN_reference_wrapper_stack_bad() {
  ReferenceWrapperStack rw = getwrapperStack();
  return rw.b->f; // we want to report use after lifetime bug here
}
