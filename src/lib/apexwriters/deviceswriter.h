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

#ifndef _APEX_SRC_LIB_APEXWRITERS_DEVICESWRITER_H_
#define _APEX_SRC_LIB_APEXWRITERS_DEVICESWRITER_H_

#include "apextools/global.h"

namespace apex
{
namespace data
{
class DevicesData;
class WavDeviceData;
class CohDeviceData;
}

namespace writer
{

class APEXWRITERS_EXPORT DevicesWriter
{
public:
    /**
    *Adds a <device> element to the document
    *
    *@param doc the document to place the element in
    *@param data the data to create the element with
    */
    static QDomElement addElement(QDomDocument *doc,
                                  const data::DevicesData &data);

private:
    /**
        * Finishes a partly created <device> element as a wavdevice
        *
        * @param dev the <device> element that needs to be finished
        * @param data the data to finish this element with
        */
    static void finishAsWav(QDomElement *dev, const data::WavDeviceData &data);
    /**
        * Finishes a partly created <device> element as an cohdevice
        *
        * @param dev the <device> element that needs to be finished
        * @param data the data to finish this element with
        */
    static void finishAsCoh(QDomElement *dev, const data::CohDeviceData &data);
};
}
}

#endif
