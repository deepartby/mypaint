#include "exception.h"

MemoryException::MemoryException()
{
    this->excepMessage = "Memory error!";
}

MemoryException::MemoryException(QString excepMessage)
{
    this->excepMessage += excepMessage;
}
void MemoryException::showMessage()
{
    QMessageBox::warning(0, "Warning Window", this->excepMessage);
}
