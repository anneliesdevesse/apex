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

#include "apextools/xml/xmltools.h"

#include "common/global.h"

#include "randomgeneratorparameters.h"

using namespace apex::data;

namespace apex
{

RandomGeneratorParameters::RandomGeneratorParameters()
    : ApexParameters(), m_dMin(0), m_dMax(0)
{
}

RandomGeneratorParameters::~RandomGeneratorParameters()
{
}

bool RandomGeneratorParameters::SetParameter(const QString &p_name,
                                             const QString & /*p_id*/,
                                             const QString &p_value,
                                             const QDomElement &)
{
    if (p_name == "min") {
        m_dMin = p_value.toDouble();
    } else if (p_name == "max") {
        m_dMax = p_value.toDouble();
    } else if (p_name == "parameter") {
        m_sParam = p_value;
    } else if (p_name == "type") {
        if (p_value == "int") {
            m_nValueType = VALUE_INT;
        } else if (p_value == "double") {
            m_nValueType = VALUE_DOUBLE;
        } else {
            Q_ASSERT(("invalid value " + p_value, false));
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool RandomGeneratorParameters::Parse(const QDomElement &p_paramElement)
{
    QString type = p_paramElement.attribute(QSL("xsi:type"));

    if (type == "apex:uniform") {
        m_nType = TYPE_UNIFORM;
    } else if (type == "apex:gaussian") {
        m_nType = TYPE_GAUSSIAN;
    } else {
        Q_ASSERT(0 && "Unknown type");
        return false;
    }

    return ApexParameters::Parse(p_paramElement);
}

bool RandomGeneratorParameters::
operator==(const RandomGeneratorParameters &other) const
{
    return ApexParameters::operator==(other) && m_dMin == other.m_dMin &&
           m_dMax == other.m_dMax && m_sParam == other.m_sParam &&
           m_nType == other.m_nType && m_nValueType == other.m_nValueType;
}
}
