#include "textanalyzer.h"
#include <QDebug>
#include <QRegularExpression>

TextAnalyzer::TextAnalyzer(QTextEdit* analyzedText, QObject *parent)
    : m_analyzedText(analyzedText), QObject(parent) { }

void TextAnalyzer::analyzeText()
{
    m_info.text = m_analyzedText->toPlainText();

    countSymbols();
    countWords();
    countLetters();
    countSpaces();
}

void TextAnalyzer::countSymbols()
{
    m_info.symbolsCount = m_info.text.size();
}

void TextAnalyzer::countWords()
{
    QRegularExpression re("\\b\\w+\\b");
    m_info.wordsCount = m_info.text.count(re);
}

void TextAnalyzer::countLetters()
{
    int counter = 0;
    lettersFrequency.clear();

    for (auto sym : m_info.text) {
        if (sym.isLetter()) {
            lettersFrequency[sym.toLower()]++;
            counter++;
        }
    }
    m_info.lettersCount = counter;
}

void TextAnalyzer::countSpaces()
{
    m_info.spacesCount = m_info.text.count(" ");
}

TextAnalyzer::TextInfo TextAnalyzer::getInfo()
{
    return m_info;
}

QHash<QChar, int> TextAnalyzer::getLettersFrequency()
{
    return lettersFrequency;
}
