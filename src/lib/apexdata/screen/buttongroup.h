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

#ifndef _EXPORL_SRC_LIB_APEXDATA_SCREEN_BUTTONGROUP_H_
#define _EXPORL_SRC_LIB_APEXDATA_SCREEN_BUTTONGROUP_H_

#include "apextools/global.h"

#include <QList>
#include <QString>

namespace apex
{
namespace data
{
/**
 * ButtonGroup
 *   a list containing the ID's of the ScreenElements that can
 *   accept user input.
 */
class APEXDATA_EXPORT ButtonGroup
{
public:
    /**
     * Constructor.
     * @param ac_sID a unique identifier
     */
    ButtonGroup(const QString &ac_sID);

    /**
     * Used to iterate the button ids. I know it looks strange but M$VC
     * cannot handle template inheritance across libraries...
     */
    struct APEXDATA_EXPORT const_iterator {
        const_iterator(const QList<QString>::const_iterator &it);
        const_iterator()
        {
        }

        const_iterator &operator=(const QList<QString>::const_iterator &it);
        const_iterator &operator++();   // prefix++
        const_iterator operator++(int); // postfix++
        bool operator==(const const_iterator &other) const;
        bool operator!=(const const_iterator &other) const;
        const QString &operator*() const;

    private:
        QList<QString>::const_iterator it;
    };

    QList<QString>::const_iterator begin() const;
    QList<QString>::const_iterator end() const;
    int size() const;
    void append(const QString &id);

    const QString getID() const
    {
        return id;
    }

    /**
     * Check whether the buttongroup contains an element with
     * the given ID
     * @param ac_sID
     */
    bool IsElement(const QString &ac_sID) const;

    bool operator==(const ButtonGroup &other) const;
    bool operator!=(const ButtonGroup &other) const;

private:
    QList<QString> buttonIds;

    const QString id;
};
}
}

#endif
