/***************************************************************************
    QgsAttributeFormLegacyInterfaceExt.h
     --------------------------------------
    Date                 : 13.5.2014
    Copyright            : (C) 2014 Matthias Kuhn
    Email                : matthias at opengis dot ch
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSATTRIBUTEFORMLEGACYINTERFACE_H
#define QGSATTRIBUTEFORMLEGACYINTERFACE_H

#include <QString>

#include "QgsAttributeFormInterfaceExt.h"
#include "qgis_gui.h"

#define SIP_NO_FILE

class QgsAttributeFormExt;

/**
 * \ingroup gui
 * This class helps to support legacy open form scripts to be compatible with the new
 * QgsAttributeFormExt style interface.
 * \note not available in Python bindings
 */
class QgsAttributeFormLegacyInterfaceExt : public QgsAttributeFormInterfaceExt
{
  public:
    explicit QgsAttributeFormLegacyInterfaceExt( const QString &function, const QString &pyFormName, QgsAttributeFormExt *form );
    ~QgsAttributeFormLegacyInterfaceExt() override;

    // QgsAttributeFormInterfaceExt interface
    void featureChanged() override;

  private:
    QString mPyFunctionName;
    QString mPyFormVarName;
    QString mPyLayerVarName;
};

#endif // QGSATTRIBUTEFORMLEGACYINTERFACE_H
