template <typename E, typename N>
void Graph<E, N>::IterativeDFS(Node n)
{
    Stack<Node> stack;

    stack.Push(n);

    while(!stack.IsEmpty())
    {
        Node u = stack.Read();

        stack.Pop();

        if(!IsMarked(u))
        {
            std::cout << ReadNode(u) << " ";

            MarkVisited(u);

            NodeList adjnodes = Adjacent(u);

            NodeList::position pos = adjnodes.FirstPosition();

            while(!adjnodes.End(pos))
            {
                stack.Push(adjnodes.ReadList(pos));

                pos = adjnodes.NextPosition(pos);
            }
        }
    }
