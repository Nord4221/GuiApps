#include "FontEditor.h"
#include <QFontDialog>

FontEditor::FontEditor(QWidget *parent, QTextBrowser *_textBrowserPtr) : QWidget(parent)
{
    TextBrowserPtr = _textBrowserPtr;
}

void FontEditor::SlotChangeFont()
{
    static int state = ST_CENTRAL;
    if(TextBrowserPtr != nullptr)
    {
        QFont font = TextBrowserPtr->textCursor().charFormat().font();
        QTextBlockFormat fmt;
        switch (state)
        {
            case FontAlignments::ST_CENTRAL:
                fmt.setAlignment(Qt::AlignCenter);
                state = FontAlignments::ST_RIGHT;
                break;
            case FontAlignments::ST_RIGHT:
                fmt.setAlignment(Qt::AlignRight);
                state = FontAlignments::ST_LEFT;
                break;
            case FontAlignments::ST_LEFT:
                fmt.setAlignment(Qt::AlignLeft);
                state = FontAlignments::ST_CENTRAL;
                break;
        }
        TextBrowserPtr->textCursor().setBlockFormat(fmt);
    }
}

void FontEditor::SlotGetFontStyle()
{
    SavedFontState = TextBrowserPtr->textCursor().charFormat().font();
}

void FontEditor::SlotUseFontStyle()
{
    QTextCharFormat textCharFmt;
    textCharFmt.setFont(SavedFontState);
    TextBrowserPtr->textCursor().setCharFormat(textCharFmt);
}

void FontEditor::SlotEditFont()
{
    QFont font = TextBrowserPtr->textCursor().charFormat().font();
    QFontDialog fontDlg(font, this);

    bool b = true;
    font = fontDlg.getFont(&b);
    if (b)
    {
        QTextCharFormat textCharFmt;
        textCharFmt.setFont(font);
        TextBrowserPtr->textCursor().setCharFormat(textCharFmt);
    }
}

QMenu *FontEditor::GetFontMenu()
{
    MenuFontPtr = new QMenu(this);
    MenuFontPtr->setTitle(tr("Font"));
    MenuFontPtr->addAction(tr("Change alignment"), this, &FontEditor::SlotChangeFont,QKeySequence::Replace);
    MenuFontPtr->addAction(tr("Get char format"), this, &FontEditor::SlotGetFontStyle, QKeySequence("Ctrl+G"));
    MenuFontPtr->addAction(tr("Use char format"), this, &FontEditor::SlotUseFontStyle,QKeySequence("Ctrl+U"));
    MenuFontPtr->addAction(tr("Edit font format"), this, &FontEditor::SlotEditFont,QKeySequence("Ctrl+E"));
    return MenuFontPtr;
}
