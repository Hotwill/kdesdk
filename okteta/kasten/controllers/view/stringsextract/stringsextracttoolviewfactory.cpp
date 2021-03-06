/*
    This file is part of the Kasten Framework, made within the KDE community.

    Copyright 2010 Friedrich W. H. Kossebau <kossebau@kde.org>

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

#include "stringsextracttoolviewfactory.h"

// lib
#include "stringsextracttoolview.h"
#include "stringsextracttool.h"
// KDE
#include <KLocale>


namespace Kasten2
{

StringsExtractToolViewFactory::StringsExtractToolViewFactory() {}

QString StringsExtractToolViewFactory::iconName() const { return QString::fromLatin1("text-plain"); }
QString StringsExtractToolViewFactory::title()       const { return i18nc("@title:window", "Strings"); }
QString StringsExtractToolViewFactory::id()       const { return QString::fromLatin1("org.kde.okteta.StringsToolView"); }
SidePosition StringsExtractToolViewFactory::defaultPosition() const { return RightSidePosition; }

AbstractToolView* StringsExtractToolViewFactory::create( AbstractTool* tool )
{
    return new StringsExtractToolView( qobject_cast<StringsExtractTool*>(tool) );
}

StringsExtractToolViewFactory::~StringsExtractToolViewFactory() {}

}
