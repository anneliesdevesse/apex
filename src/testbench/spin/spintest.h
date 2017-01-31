    /******************************************************************************
 * Copyright (C) 2008  Tom Francart <tom.francart@med.kuleuven.be>            *
 *                                                                            *
 * This file is part of APEX 3.                                               *
 *                                                                            *
 * APEX 3 is free software: you can redistribute it and/or modify             *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 2 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * APEX 3 is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with APEX 3.  If not, see <http://www.gnu.org/licenses/>.            *
    *****************************************************************************/

#ifndef WRITERS_UNIT_TEST_H
#define WRITERS_UNIT_TEST_H

#include "testbench.h"

class SpinTest : public ApexTest
{
    Q_OBJECT
    Q_INTERFACES(ApexTest)

    public:

        QString name() const;

    private Q_SLOTS:

        void initTestCase();
        void cleanupTestCase();
        void testSnrDefined();

        /**
         * Test whether the combination of all gains in file results in
         * the desired level or snr
         */
        void testTotalGain();

        void testAdaptiveWithoutNoise();
        void testAdaptiveWithNoiseAdaption();

        void testAudioDriver_data();
        void testAudioDriver();

        void testCalibration();

    private:
};

#endif