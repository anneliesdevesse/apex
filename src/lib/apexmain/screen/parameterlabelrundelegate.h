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

#ifndef _EXPORL_SRC_LIB_APEXMAIN_SCREEN_PARAMETERLABELRUNDELEGATE_H_
#define _EXPORL_SRC_LIB_APEXMAIN_SCREEN_PARAMETERLABELRUNDELEGATE_H_

#include "labelrundelegatebase.h"
#include "parameterscontainerrundelegate.h"

namespace apex
{
class ExperimentRunDelegate;
namespace data
{
class ParameterLabelElement;
class ScreenElement;
}

namespace stimulus
{
class Stimulus;
}

namespace rundelegates
{

using data::ParameterLabelElement;
using data::ScreenElement;

/**
         * The ParameterLabelRunDelegate class is an implementation of
         * ScreenElementRunDelegate representing a LabelElement.
 */
class ParameterLabelRunDelegate : public LabelRunDelegateBase,
                                  public ParametersContainerRunDelegate
{
    Q_OBJECT

    const ParameterLabelElement *element;

public:
    ParameterLabelRunDelegate(ExperimentRunDelegate *p_exprd, QWidget *parent,
                              const ParameterLabelElement *e,
                              const QFont &font);

    virtual ~ParameterLabelRunDelegate(){};

    const ScreenElement *getScreenElement() const;

    void connectSlots(gui::ScreenRunDelegate *d);

    virtual void setEnabled(const bool);

public slots:
    void updateParameter(const QString &id, const QVariant &value);
};
}
}
#endif
