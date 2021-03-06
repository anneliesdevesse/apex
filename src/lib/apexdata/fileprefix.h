/******************************************************************************
 * Copyright (C) 2008  Tom Francart <tom.francart@med.kuleuven.be>            *
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

#ifndef _APEX_SRC_LIB_APEXDATA_FILEPREFIX_H_
#define _APEX_SRC_LIB_APEXDATA_FILEPREFIX_H_

#include <QString>

#include "apextools/global.h"

namespace apex
{

namespace data
{

/**
 * Represents a prefix as found in the experiment file
 * can be inline or from mainconfig
 */
class APEXDATA_EXPORT FilePrefix
{
public:
    enum Type { PREFIX_INLINE, PREFIX_MAINCONFIG };

    FilePrefix();

    QString value() const;
    void setValue(const QString &v);
    Type type() const;
    void setType(Type t);

    bool operator==(const FilePrefix &other) const;

private:
    Type mType;
    QString mValue;
};
}
}

#endif
