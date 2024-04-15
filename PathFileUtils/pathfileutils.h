#ifndef PATHFILESUTILS_H
#define PATHFILESUTILS_H

#include <QString>
#include <QFileDialog>

namespace PathFileUtils
{
    QString filePathDialog(const QString &caption, QFileDialog::AcceptMode acceptMode, const QString &fileFilter, const QString &defaultFileName = QString());
}

#endif // PATHFILESUTILS_H
