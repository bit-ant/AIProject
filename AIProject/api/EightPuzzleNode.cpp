#include <api/EightPuzzleNode.h>
#include <algorithm>

namespace api {

EightPuzzleNode::EightPuzzleNode(const gameBoard& state, const float& cost)
    : m_State(state),
      m_Cost(cost) {}

EightPuzzleNode::~EightPuzzleNode() {}

EightPuzzleNode::nodeChildren EightPuzzleNode::generateChildren() const
{
    nodeChildren result;

    // Possible moves are:
    // 1. Empty square moves left
    // 2. Empry square moves right
    // 3. Empty square moves up
    // 4. Empty square moves down

    // First, find the position of the empty square within the board
    auto emptyPosIt = std::find(std::begin(m_State), std::end(m_State), 0);
    if (std::end(m_State) != emptyPosIt)
    {
        // Empty square found! We can continue with the generation of possible moves
        const unsigned long indexOfEmpty = static_cast<unsigned long>(emptyPosIt - m_State.begin());

        // 1. Move left
        if (1 == indexOfEmpty|| 2 == indexOfEmpty || 4 == indexOfEmpty || 5 == indexOfEmpty || 7 == indexOfEmpty || 8 == indexOfEmpty)
        {
            gameBoard rightMove = m_State;
            std::swap(rightMove.at(indexOfEmpty),rightMove.at(indexOfEmpty - 1));
            result.emplace_back(std::make_shared<EightPuzzleNode>(rightMove, 0.0));
        }
        // 2. Move right
        if (0 == indexOfEmpty|| 1 == indexOfEmpty || 3 == indexOfEmpty || 4 == indexOfEmpty || 6 == indexOfEmpty || 7 == indexOfEmpty)
        {
            gameBoard leftMove = m_State;
            std::swap(leftMove.at(indexOfEmpty),leftMove.at(indexOfEmpty + 1));
            result.emplace_back(std::make_shared<EightPuzzleNode>(leftMove, 0.0));
        }
        // 3. Move up
        if (indexOfEmpty > 2)
        {
            gameBoard upMove = m_State;
            std::swap(upMove.at(indexOfEmpty), upMove.at(indexOfEmpty - 3));
            result.emplace_back(std::make_shared<EightPuzzleNode>(upMove, 0.0));
        }
        // 4. Move down
        if (indexOfEmpty < 6)
        {
            gameBoard downMove = m_State;
            std::swap(downMove.at(indexOfEmpty), downMove.at(indexOfEmpty + 3));
            result.emplace_back(std::make_shared<EightPuzzleNode>(downMove, 0.0));
        }
    }
    return result;
}

} // namespace core
