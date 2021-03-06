/*
    This file is part of the Okteta Kasten module, made within the KDE community.

    Copyright 2009 Friedrich W. H. Kossebau <kossebau@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library. If not, see <http://www.gnu.org/licenses/>.
*/

#include "sint16editor.h"

// C++
#include <limits>


SInt16Editor::SInt16Editor( QWidget* parent )
  : SIntSpinBox( parent )
{
    const qint16 int16Max = std::numeric_limits<qint16>::max();
    const qint16 int16Min = std::numeric_limits<qint16>::min();

    setRange( int16Min, int16Max );
}

void SInt16Editor::setData( SInt16 data )
{
    setValue( data.value );
}

SInt16 SInt16Editor::data() const
{
    return value();
}

SInt16Editor::~SInt16Editor() {}
