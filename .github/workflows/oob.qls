import cpp

// Define a class representing std::vector
class StdVector extends Class {
  StdVector() {
    hasName("std::vector")
  }
}

// Define a predicate to find potential out-of-bounds accesses
predicate findOutOfBoundsAccess() {
  from IndexAccess i
  where i.getBase().(ArrayType).getArrayElementType().hasName("std::vector") and
        i.getIndex().getType().(NamedType).getName() = "size_t" and
        i.getIndex().(BinaryExpr).getOp() = "<" and
        i.getIndex().(BinaryExpr).getRhs().(IntegerLiteral).getIntValue() >=
        i.getBase().(ArrayType).getArraySize().getValue()
  select i, "Potential out-of-bounds access"
}

// Entry point for the query
from StdVector v, IndexAccess i
where i.getBase() = v and
      findOutOfBoundsAccess()
select v, i
