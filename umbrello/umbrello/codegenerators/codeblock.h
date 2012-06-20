/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2003      Brian Thomas <thomas@mail630.gsfc.nasa.gov>   *
 *   copyright (C) 2004-2011                                               *
 *   Umbrello UML Modeller Authors <uml-devel@uml.sf.net>                  *
 ***************************************************************************/

#ifndef CODEBLOCK_H
#define CODEBLOCK_H

#include "textblock.h"

/**
 * A "chunk" of code within the code document.
 */
class CodeBlock : public TextBlock
{
public:

    /**
     * Describes the creation of the content.
     */
    enum ContentType {
        AutoGenerated=0,  ///< the content was generated by code generation itself
        UserGenerated     ///< the content was entered by the user
    };

    explicit CodeBlock(CodeDocument * parent, const QString & body = "");
    virtual ~CodeBlock();

    void setContentType(ContentType new_var);
    ContentType contentType() const;

    static QString enumToString(const ContentType& val);

    virtual void saveToXMI(QDomDocument & doc, QDomElement & root);
    virtual void loadFromXMI(QDomElement & root);

    virtual void setAttributesFromObject(TextBlock * obj);

    friend QDebug operator<<(QDebug str, const CodeBlock& obj);

protected:

    virtual void setAttributesOnNode(QDomDocument & doc, QDomElement & blockElement);
    virtual void setAttributesFromNode(QDomElement & element);

private:

    // specifies whether the content (text) of this object
    // was generated by the code generator or was supplied by the user (or some other way).
    ContentType m_contentType;

};

#endif // CODEBLOCK_H