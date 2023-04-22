#ifndef CELLCONTAINER_H
#define CELLCONTAINER_H

#include "cell.h"

class CellContainer : public QObject, public QList<Cell*>
{
    Q_OBJECT
public:
    CellContainer() {};
    void initializeCells(const unsigned short boardSize);
    void initializeBlankCell();
    void setImagePixmapsToCells(QList<QPixmap*> *clippings);
    void setImagePixmapsVisibleBesidesBlank();
    void setCellStyles(Cell *cell);
    void setInitialPostions(const unsigned short boardSize);
    bool changeToOppositeVisibilty();
    void shuffle(unsigned short boardSize);
    void resetBlankToNormalCell();
    void swapCellAndBlankPosition(Cell *cell);
    void swapCellsByIndex(int firstIndex, int secondIndex);
    bool isCellCloseToBlank(Cell *cell);
    bool areIdsLinedUp();
    int getCellsWidth();
    int getCellsHeight();
signals:
    void cellsLinedUpSingal();
    void refreshBoardSignal();
private:
    Cell* blankCell;
public slots:
    void onCellClicked(Cell *cell);
};

#endif // CELLCONTAINER_H
