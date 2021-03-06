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

#include "apexdata/screen/answerlabelelement.h"

#include "screen/screenrundelegate.h"

#include "answerlabelrundelegate.h"

namespace apex
{
namespace rundelegates
{

AnswerLabelRunDelegate::AnswerLabelRunDelegate(ExperimentRunDelegate *p_exprd,
                                               QWidget *parent,
                                               const AnswerLabelElement *e,
                                               const QFont &defaultFont)
    : LabelRunDelegateBase(p_exprd, parent, e, defaultFont), element(e)
{
}

void AnswerLabelRunDelegate::newAnswer(const QString &answer)
{
    //    qCDebug(APEX_RS, "AnswerLabelRunDelegate::newAnswer: %s",
    //    qPrintable(answer));
    LabelRunDelegateBase::setText(answer);
}

const ScreenElement *AnswerLabelRunDelegate::getScreenElement() const
{
    return element;
}
}
}

void apex::rundelegates::AnswerLabelRunDelegate::connectSlots(
    gui::ScreenRunDelegate *d)
{
    connect(d, SIGNAL(newAnswer(const QString &)), this,
            SLOT(newAnswer(const QString &)));
}
