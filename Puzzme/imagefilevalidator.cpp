#include "imagefilevalidator.h"
#include <QFileInfo>
#include <QString>
#include "validator.h"

ImageFileValidator::ImageFileValidator() : Validator<QString>() {

}


bool ImageFileValidator::validate(QString fileName) {
    if (!fileName.isEmpty()) {
        QFileInfo *fileInfo = new QFileInfo(fileName);
        if (fileInfo->suffix() == "jpg" || fileInfo->suffix() == "png"){
            return true;
        }
    }
    return false;
}
