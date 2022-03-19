/***************************************************************************
    QgsAttributeFormInterfaceExt.h
     --------------------------------------
    Date                 : 12.5.2014
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

#ifndef QGSATTRIBUTEFORMINTERFACEEXT_H
#define QGSATTRIBUTEFORMINTERFACEEXT_H

#include "qgis_gui.h"

class QgsAttributeFormExt;
class QgsFeature;

/**
 * \ingroup gui
 * \class QgsAttributeFormInterfaceExt
 */
class QgsAttributeFormInterfaceExt
{
  public:
    explicit QgsAttributeFormInterfaceExt( QgsAttributeFormExt *form );

    virtual ~QgsAttributeFormInterfaceExt() = default;

    virtual bool acceptChanges( const QgsFeature &feature );

    virtual void initForm();

    virtual void featureChanged();

    QgsAttributeFormExt *form();

    const QgsFeature &feature();

  private:
    QgsAttributeFormExt *mForm = nullptr;
};

#endif // QgsAttributeFormInterfaceExt_H
