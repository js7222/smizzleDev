//
//#include <memory>
//#include <utility>
//
//typedef std::pair<unsigned int, unsigned int> Coord;
//
//class PieceBase
//{
//    
//public:
//    enum class Colour { WHITE, BLACK };
//    PieceBase(Colour colour) : colour_(colour) {}
//    virtual ~PieceBase() = default;
//    virtual bool canMove(const Coord& from, const Coord& to) = 0;
//private:
//    Colour colour_;
//
//};
//
//template <class Derived>
//class Piece : public PieceBase
//{
//public:
//    Piece(Colour colour) : PieceBase(colour) {}
//    virtual ~Piece() = default;
//private:
//    virtual bool canMove(const Coord& from, const Coord& to)
//    {
//	return static_cast<Derived*>(this)->canMoveImpl(from, to);
//    }
//
//};
//
//
//
//class Rook : public Piece<Rook>
//{
//public:
//    Rook(Colour colour) : Piece<Rook>(colour) {}
//    virtual ~Rook() = default;
//    bool canMoveImpl(const Coord& from, const Coord& to);
//
//};
//
//class Board
//{
//public :
//    Board();
//private:
//    std::shared_ptr<PieceBase> board[8][8];
//    
//};
//
//
//class MyClass;
//
//template <typename T>
//class TemplatedClass
//{
//    T data();
//};
//
//TemplatedClass<MyClass> glob;
