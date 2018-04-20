<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl=
  "http://www.w3.org/1999/XSL/Transform">
<xsl:output method="xml"
  doctype-system="http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd"
  doctype-public="-//W3C//DTD XHTML 1.1//EN" indent="yes" encoding="UTF-8"/>

  <xsl:template match="/">
    <html>
      <body>
        <table>
            <thead>
              <tr>
                <th>Title</th>
                <th>Price</th>
                <th>Description</th>
                <th>Image</th>
              </tr>
            </thead>
            <tbody>
              <xsl:for-each select="items/item">
                  <tr>
                    <td>
                        <xsl:value-of select="title"/>
                    </td>
                     <td><xsl:value-of select="price"/></td>
                     <td><xsl:value-of select="description"/></td>
                      <td><xsl:element name="img">
                             <xsl:attribute name="src">
                                 <xsl:value-of select="image"/>
                             </xsl:attribute>
                         </xsl:element>
                      </td>
                  </tr>
              </xsl:for-each>
            </tbody>
        </table>
      </body>
    </html>
  </xsl:template>


</xsl:stylesheet>