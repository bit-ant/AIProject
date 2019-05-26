#ifndef CORE_EIGHTPUZZLENODE_H
#define CORE_EIGHTPUZZLENODE_H

#include <array>
#include <vector>
#include <memory>

namespace api {

class EightPuzzleNode {

public:
    using gameBoard = std::array<uint8_t, 9 /* board size */>;
    using nodeChildren = std::vector<std::shared_ptr<EightPuzzleNode>>;

    ///
    /// \brief emptySquare To be used to indicate empty square within the board
    ///
    static const uint8_t emptySquare = 0;

    EightPuzzleNode(){}

    EightPuzzleNode(const gameBoard& state, const float& cost);

    ~EightPuzzleNode();

     nodeChildren generateChildren() const;

     inline void setState(const gameBoard& state){m_State = state;}

     inline void setCost(const float& cost){m_Cost = cost;}

     inline EightPuzzleNode::gameBoard getState() const {return m_State;}

     inline float getCost() const {return m_Cost;}

private:
    gameBoard m_State;
    float m_Cost;
};

} // namespace core

#endif // CORE_EIGHTPUZZLENODE_H
