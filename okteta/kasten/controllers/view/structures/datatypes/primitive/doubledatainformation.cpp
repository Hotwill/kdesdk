/*
 *   This file is part of the Okteta Kasten Framework, made within the KDE community.
 *
 *   Copyright 2009, 2010, 2011  Alex Richardson <alex.richardson@gmx.de>
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2.1 of the License, or (at your option) version 3, or any
 *   later version accepted by the membership of KDE e.V. (or its
 *   successor approved by the membership of KDE e.V.), which shall
 *   act as a proxy defined in Section 6 of version 3 of the license.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */
#include "doubledatainformation.h"
#include <KDoubleNumInput>

QString DoubleDataInformation::valueString() const
{
    if (!mWasAbleToRead)
        return i18nc("invalid value (out of range)", "<invalid>");
    return valueString(mValue);
}

QWidget* DoubleDataInformation::createEditWidget(QWidget* parent) const
{
    return staticCreateEditWidget(parent);
}

QWidget* DoubleDataInformation::staticCreateEditWidget(QWidget* parent)
{
    KDoubleNumInput* ret = new KDoubleNumInput(parent);
    return ret;
}

QVariant DoubleDataInformation::dataFromWidget(const QWidget* w) const
{
    return staticDataFromWidget(w);
}

QVariant DoubleDataInformation::staticDataFromWidget(const QWidget* w)
{
    const KDoubleNumInput* spin = dynamic_cast<const KDoubleNumInput*> (w);
    Q_CHECK_PTR(spin);
    if (spin)
        return spin->value();
    return QVariant();
}

void DoubleDataInformation::setWidgetData(QWidget* w) const
{
    staticSetWidgetData(mValue, w);
}

void DoubleDataInformation::staticSetWidgetData(double value, QWidget* w)
{
    KDoubleNumInput* spin = dynamic_cast<KDoubleNumInput*> (w);
    Q_CHECK_PTR(spin);
    if (spin)
        spin->setValue(value);
}

AllPrimitiveTypes DoubleDataInformation::qVariantToAllPrimitiveTypes(const QVariant& value) const
{
    return AllPrimitiveTypes(value.toDouble());
}

AllPrimitiveTypes DoubleDataInformation::value() const
{
    return AllPrimitiveTypes(mValue);
}

void DoubleDataInformation::setValue(AllPrimitiveTypes newVal)
{
    mValue = newVal.doubleValue;
}

QScriptValue DoubleDataInformation::asScriptValue(double value, QScriptEngine* engine, ScriptHandlerInfo* handler)
{
    Q_UNUSED(engine);
    Q_UNUSED(handler);
    return QScriptValue(value);
}


QScriptValue DoubleDataInformation::valueAsQScriptValue() const
{
    return asScriptValue(mValue, 0, 0);
}
