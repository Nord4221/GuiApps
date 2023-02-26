#ifndef FONTEDITOR_H
#define FONTEDITOR_H

#include <QWidget>
#include <QTextBrowser>
#include <QMenuBar>

enum FontAlignments
{
    ST_RIGHT,
    ST_CENTRAL,
    ST_LEFT
};

class FontEditor : public QWidget
{
    Q_OBJECT
public:
    explicit FontEditor(QWidget *parent = nullptr, QTextBrowser *_textBrowserPtr = nullptr);
    QMenu *GetFontMenu();
signals:

public slots:
    void SlotChangeFont();
    void SlotGetFontStyle();
    void SlotUseFontStyle();
    void SlotEditFont();
private:
    QTextBrowser *TextBrowserPtr = nullptr;
    QMenu *MenuFontPtr;
    QFont SavedFontState;
};

#endif // FONTEDITOR_H
