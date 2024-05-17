#include "ast_evaluator.hh"
#include "../utils/errors.hh"

namespace ast {

int ASTEvaluator::visit(const IntegerLiteral &literal) {
  return (literal.value);
}

int ASTEvaluator::visit(const StringLiteral &literal) {
  utils::error("ERROR: StringLiteral evaluation");
  return (-1);
}

int ASTEvaluator::visit(const BinaryOperator &binop) {
	int left, right;

	left = binop.get_left().accept(*this);
	right = binop.get_right().accept(*this);
  if (binop.op == o_plus)
	  return left + right;
  if (binop.op == o_minus)
	  return left - right;
  if (binop.op == o_times)
	  return left * right;
  if (binop.op == o_divide)
	  return left / right;
  if (binop.op == o_eq)
	  return left == right;
  if (binop.op == o_neq)
	  return left != right;
  if (binop.op == o_lt)
	  return left < right;
  if (binop.op == o_le)
	  return left <= right;
  if (binop.op == o_gt)
	  return left > right;
  if (binop.op == o_ge)
	  return left >= right;
  utils::error("ERROR: BinaryOperator is unknown!");
  return (-1);
}

int ASTEvaluator::visit(const Sequence &seqExpr) {
  std::vector<Expr *> e;
  unsigned int i;

  e = seqExpr.get_exprs();
  if (e.empty())
  {
    utils::error("ERROR: Sequence is Empty!");
    return (-1);
  }
  for (i = 0; i < e.size() - 1; i++)
    e[i]->accept(*this);
  return (e[i]->accept(*this));
}

int ASTEvaluator::visit(const Let &let) {
  //let.get_decls()[0]->accept(*this); 
  //check var error [let var a := 10 in 20 end]
  //check func error [let function print_conditional() = 10 in 20 end]
  
  utils::error("ERROR: Let");
  return (-1);
}

int ASTEvaluator::visit(const Identifier &id) {
  utils::error("ERROR: Identifier");
  return (-1);
}

int ASTEvaluator::visit(const IfThenElse &ite) {
  if (ite.get_condition().accept(*this))
	  return (ite.get_then_part().accept(*this));
  return (ite.get_else_part().accept(*this));
}

int ASTEvaluator::visit(const VarDecl &decl) {
  utils::error("ERROR: VarDecl");
  return (-1);
}

int ASTEvaluator::visit(const FunDecl &decl) {
   utils::error("ERROR: FunDecl");
  return (-1);
}

int ASTEvaluator::visit(const FunCall &call) {
  utils::error("ERROR: FunCall");
  return (-1);
}

int ASTEvaluator::visit(const WhileLoop &loop) {
  utils::error("ERROR: WhileLoop");
  return (-1);
}

int ASTEvaluator::visit(const ForLoop &loop) {
  utils::error("ERROR: ForLoop");
  return (-1);
}

int ASTEvaluator::visit(const Break &brk) {
  utils::error("ERROR: Break");
  return (-1);
}

int ASTEvaluator::visit(const Assign &assign) {
  utils::error("ERROR: Assign");
  return (-1);
}

} // namespace ast