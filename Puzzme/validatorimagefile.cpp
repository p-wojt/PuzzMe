#include "validatorimagefile.h"
#include <QFileInfo>
#include <QString>
#include "validator.h"

ValidatorImageFile::ValidatorImageFile() : Validator<QString>() {

}


bool ValidatorImageFile::validate(QString fileName) {
    if (!fileName.isEmpty()) {
        QFileInfo *fileInfo = new QFileInfo(fileName);
        if (fileInfo->suffix() == "jpg" || fileInfo->suffix() == "png"){
            return true;
        }
    }
    return false;
}
