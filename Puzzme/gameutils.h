#ifndef GAMEUTILS_H
#define GAMEUTILS_H

/*!
 * \brief Klasa użyteczna zawierająca statyczne zmienne globalne.
 */
class GameUtils {
public:
    static bool isGameStarted;
    static bool areNumberCellsActive;
    static bool isAiSolvingGame;
    static const unsigned short MIN_BOARD_SIZE;
    static const unsigned short MAX_BOARD_SIZE;
};

#endif // GAMEUTILS_H
