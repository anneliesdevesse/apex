/******************************************************************************
 * Copyright (C) 2008  Job Noorman <jobnoorman@gmail.com>                     *
 *                                                                            *
 * This file is part of APEX 4.                                               *
 *                                                                            *
 * APEX 4 is free software: you can redistribute it and/or modify             *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 2 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * APEX 4 is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with APEX 4.  If not, see <http://www.gnu.org/licenses/>.            *
 *****************************************************************************/

#ifndef _APEX_SRC_LIB_APEXWRITERS_CONNECTIONSWRITER_H_
#define _APEX_SRC_LIB_APEXWRITERS_CONNECTIONSWRITER_H_

#include "apextools/global.h"

namespace apex
{
namespace data
{
class ConnectionsData;
class ConnectionData;
}

namespace writer
{

/**
*@author Job Noorman <jobnoorman@gmail.com>
*/
class APEXWRITERS_EXPORT ConnectionsWriter
{
public:
    /**
     *Adds a <connections> element to the document.
     *
     *@param doc  the document to place the element in
     *@param data the data to create the element with
     *
     *@return the created element
     */
    static QDomElement addElement(QDomDocument *doc,
                                  const data::ConnectionsData &data);

private:
    static QDomElement addConnection(QDomDocument *doc,
                                     const data::ConnectionData &data);
};
}
}

#endif
