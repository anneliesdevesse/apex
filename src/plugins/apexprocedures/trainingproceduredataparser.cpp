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

#include "apexdata/procedure/trainingproceduredata.h"

#include "trainingproceduredataparser.h"

namespace apex
{

namespace parser
{

TrainingProcedureDataParser::TrainingProcedureDataParser()
{
}

void TrainingProcedureDataParser::Parse(const QDomElement &p_base,
                                        data::TrainingProcedureData *p_data)
{
    ProcedureDataParser::Parse(p_base, p_data);
}

bool TrainingProcedureDataParser::SetParameter(const QString &p_name,
                                               const QString &id,
                                               const QString &p_value,
                                               const QDomElement &node,
                                               data::ProcedureData *data)
{
    return ProcedureDataParser::SetParameter(p_name, id, p_value, node, data);
}
}
}
