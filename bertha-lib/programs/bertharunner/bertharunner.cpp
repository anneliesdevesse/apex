/******************************************************************************
 * Copyright (C) 2008 Michael Hofmann <mh21@piware.de>                        *
 * Copyright (C) 2008 Division of Experimental Otorhinolaryngology K.U.Leuven *
 *                                                                            *
 * Original version written by Maarten Lambert.                               *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with this program; if not, write to the Free Software Foundation, Inc.,    *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                *
 ******************************************************************************/

#include "bertha/experimentprocessor.h"
#include "bertha/xmlloader.h"

#include <cstdio>
#include <iostream>

using namespace bertha;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    const QStringList arguments = app.arguments();
    if (arguments.count() < 2) {
        printf("Usage: %s experiment.xml\n", qPrintable(arguments[0]));
        return 1;
    }

    try {
        ExperimentProcessor processor(XmlLoader().loadFile(arguments[1]));
        processor.prepare();
        processor.start();

        printf("Experiment running. Press enter to stop");
        std::cin.get();

        processor.stop();
    } catch (const std::exception &e) {
        printf("Exception: %s\n", e.what());
        return 2;
    }

    return 0;
}
