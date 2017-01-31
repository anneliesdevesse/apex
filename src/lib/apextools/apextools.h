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

#ifndef APEXAPEXTOOLS_H
#define APEXAPEXTOOLS_H

#include "global.h"

#include <string>

#include <QMap>
#include <QBitArray>
#include <QDebug>

class QString;
class QWidget;
class QChar;
class QSize;
class QFont;
class QScriptEngine;
class QScriptValue;

#include <QStringList>

namespace apex
{


/**
Misc tools

@author Tom Francart,,,
*/
class APEXTOOLS_EXPORT ApexTools
{
    private:
        ApexTools();

        ~ApexTools();

    public:
        static void connectSlotsByNameToPrivate(QObject *publicObject,
                QObject *privateObject);

        static QString MakeDirEnd(QString);
        static QString addPrefix(const QString& base, const QString& prefix);
        static QString absolutePath(const QString& path);
        static QString boolToString(bool b);
        static int RandomRange(int lowest_number, int highest_number=0);
        static float RandomRange(double lowest_number, double highest_number=0);
        static double Randn();
        static void InitRand();
        //static std::string Q2StdString(const QString& p);
        static bool bQStringToBoolean( const QString& ac_sBoolean );
        static QString removeXmlTags(const QString& str);

        static void ReplaceCharInString( QString& a_StringToSearch, const QChar& ac_ToReplace, const QString& ac_ReplaceWith );
        static void ReplaceWhiteSpaceWithNBSP( QString& a_StringToSearch );
        static QString escapeJavascriptString(const QString& s);

        /** Returns the maximum font size possible for fitting the string into
         * the given box.
         */
        static int maximumFontPointSize (const QString &text, const QSize &box,
                const QFont &originalFont);

        static void shrinkTillItFits (QWidget *widget, const QString &text,
                const QSize &border);

          /** Find a file with a certain number of possible prefixes and extensions in
         * different directories. If no existing readable file is found, an empty
         * string is returned. The current directory as well as the empty prefix and
         * extension are always included.
         *
         * @param baseName base file name that you want to look for
         * @param directories directories to search
         * @param extensions possible extensions of the file, the dot before the
         * extension has to be included, e.g., ".js"
         * @param prefixes possible prefixes to try
           */
        static QString findReadableFile (const QString &baseName,
                                         const QStringList &directories, const QStringList &extensions = QStringList(),
                                                 const QStringList &prefixes = QStringList());


        /*
         * Remove doubles from QStringList
         */
        static QStringList unique(const QStringList& list);

        static QStringList toStringList(const QList<int> intList);

        /**
         * Workaround for buggy Qt function
         */
        static QScriptValue QVariant2ScriptValue(QScriptEngine *e, QVariant var);

        /**
         * This method does the same as QMap's operator== but it dereferences
         * the pointer values.
         */
        template <class K, class V>
        static bool areEqualPointerMaps(const QMap<K, V*>& first,
                                        const QMap<K, V*>& second)
        {
            if (first.size() != second.size())
                return false;

            typename QMap<K, V*>::const_iterator it;
            for (it = first.begin(); it != first.end(); it++)
            {
                if (!(*second[it.key()] == *it.value()))
                    return false;
            }

            return true;
        }

        template <class K, class V>
        static bool areEqualPointerMaps(const std::map<K, V*> first,
                                        const std::map<K, V*> second)
        {
            return areEqualPointerMaps(QMap<K, V*>(first), QMap<K, V*>(second));
        }

        /**
         * This template function is used to check if two vectors or lists have the
         * same contents. It does not care about the order of the contents. If the
         * contents of the given containers are pointers, the pointers will be
         * dereferenced when comparing.
         *
         * @note    The contents of the containers should have an operator==.
         * @note    It should work with all index-based containers that have a
         *          const_iterator and a size() method.
         * @note    Because it does not work with maps, first.front() is called
         *          to generate a compile error if T is a map. If you  want
         *          to use this method with other containers than lists or vectors,
         *          make sure they have a front() method.
         */
        template<class T>
        static bool haveSameContents(const T& first, const T& second)
        {
            if (false)
                first.front(); //gives a compile error if T is a map

            if (first.size() != second.size())
                return false;

            int size = first.size();
            QBitArray used(size);

            typename T::const_iterator it1, it2;
            for (it1 = first.begin(); it1 != first.end(); it1++)
            {
                int i = 0; //holds index of it2 in second
                for (it2 = second.begin(); it2 != second.end(); it2++, i++)
                {
                    if (used[i])
                        continue;

                    if (areEqual(*it1, *it2))
                    {
                        used[i] = true;
                        break;
                    }
                }
            }

            for (int i = 0; i < size; i++)
            {
                if (!used[i])
                    return false;
            }

            return true;
        }

        template <typename T>
        static bool areEqual(T* const& first, T* const& second)
        {
            return *first == *second;
        }

        template <typename T>
        static bool areEqual(T const& first, T const& second)
        {
            return first == second;
        }
};


class APEXTOOLS_EXPORT RandomNumber
{
    public:

        RandomNumber()
        {
            ApexTools::InitRand();
        }

        unsigned int operator() (int count);


};

}

#endif