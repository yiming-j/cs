template <unsigned M>
size_t grade(const quiz<M> &lhsQ, const quiz<M> &rhsQ)
{
	return (lhsQ.bset ^ rhsQ.bset).flip().count();
}