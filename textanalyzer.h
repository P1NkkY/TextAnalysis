#ifndef TEXTANALYZER_H
#define TEXTANALYZER_H

#include <QObject>
#include <QtWidgets/QTextEdit>
#include <QHash>

class TextAnalyzer : public QObject {
        Q_OBJECT
private:
    QTextEdit* m_analyzedText;

    struct TextInfo {
        QString text;
        int lettersCount;
        int symbolsCount;
        int wordsCount;
        int spacesCount;
    };

    TextInfo m_info;
    QHash<QChar, int> lettersFrequency;

public:
    explicit TextAnalyzer(QTextEdit* analyzedText, QObject *parent = nullptr);

    void analyzeText();

    TextInfo getInfo();

    QHash<QChar, int> getLettersFrequency();

private:
    void countSymbols();

    void countWords();

    void countLetters();

    void countSpaces();
};

#endif // TEXTANALYZER_H
