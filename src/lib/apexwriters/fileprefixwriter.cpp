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

#include "apexdata/fileprefix.h"

#include "apextools/xml/xmltools.h"

#include "common/global.h"

#include "fileprefixwriter.h"

using namespace apex;
using apex::data::FilePrefix;

QDomElement
apex::writer::FilePrefixWriter::addElement(QDomDocument *doc,
                                           const data::FilePrefix &d)
{
    QDomElement result = XmlUtils::createTextElement(doc, "prefix", d.value());
    if (d.type() == FilePrefix::PREFIX_MAINCONFIG)
        result.setAttribute(QSL("source"), QSL("apexconfig"));
    return result;
}
