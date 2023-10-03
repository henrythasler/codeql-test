/**
 * @name Unsafe vector access
 * @description std::vector::operator[] does not do any runtime
 *              bounds-checking, so it is safer to use std::vector::at()
 * @kind problem
 * @problem.severity warning
 * @id cpp/unsafe-vector-access
 * @tags security
 *       external/cwe/cwe-125
 */

import cpp

// A call to `operator[]`.
class ArrayIndexCall extends FunctionCall {
  ClassTemplateInstantiation ti;
  TemplateClass tc;

  ArrayIndexCall() {
    this.getTarget().getName() = "operator[]" and
    ti = this.getQualifier().getType().getUnspecifiedType() and
    tc = ti.getTemplate() and
    tc.getSimpleName() != "map"
  }

  ClassTemplateInstantiation getClassTemplateInstantiation() { result = ti }
}

from ArrayIndexCall call
select call, "Unsafe use of operator[]. Use the at() method instead."