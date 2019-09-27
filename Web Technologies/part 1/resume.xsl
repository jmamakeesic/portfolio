<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html" doctype-system="about:legacy-compat"/>
  <xsl:template match="/">
    <html>
      <head>
        <title><xsl:value-of select="resume/name"/> - Resume</title>
        <meta charset="UTF-8"/>
        <link rel="stylesheet" type="text/css" href="../shared/styles.css"/>
        <link rel="stylesheet" type="text/css" href="../shared/resume.css"/>
      </head>
      <body>
        <img id="banner" src="../shared/banner.jpg" alt=""/>
        <div id="content">
          <nav>
            <a href="../index.htm">Back</a>
          </nav>
          <h1>Resume</h1>
        </div>
        <div id="resume">
          <div id="name"><xsl:value-of select="resume/name"/></div>
          <table id="contact">
            <tr><td>
              <div id="email"><xsl:value-of select="resume/contact/email"/></div>
              <div id="phone"><xsl:value-of select="resume/contact/phone"/></div>
            </td><td>
              <div id="mail"><xsl:value-of select="resume/contact/mail"/></div>
            </td></tr>
          </table>
          <svg height="1" width="650" xmlns="http://www.w3.org/2000/svg">
            <line x1="1" y1="1" x2="650" y2="1" stroke="black"></line>
          </svg>

          <h2>Summary</h2>
          <div id="description"><xsl:value-of select="resume/description"/></div>

          <h2>Skills</h2>
          <div id="skills">
            <xsl:for-each select="resume/skills/sk">
              <div class="sk"><xsl:value-of select="."/></div>
            </xsl:for-each>
          </div>

          <h2>Qualities</h2>
          <div id="qualities">
            <xsl:for-each select="resume/qualities/qu">
              <div class="qu"><xsl:value-of select="."/></div>
            </xsl:for-each>
          </div>

          <h2>Education</h2>
          <div id="education">
            <xsl:for-each select="resume/education/program">
              <div class="program">
                <div class="pname">   <xsl:value-of select="pname"/>   </div>
                <div class="year">    <xsl:value-of select="year"/>    </div>
                <div class="school">  <xsl:value-of select="school"/>  </div>
                <div class="location"><xsl:value-of select="location"/></div>
                <div class="detail">  <xsl:value-of select="detail"/>  </div>
              </div>
            </xsl:for-each>
          </div>

          <h2>Experience</h2>
          <div id="experience">
            <xsl:for-each select="resume/experience/job">
              <div class="job">
                <div class="jtitle">  <xsl:value-of select="jtitle"/>  </div>
                <div class="year">    <xsl:value-of select="year"/>    </div>
                <div class="company"> <xsl:value-of select="company"/> </div>
                <div class="location"><xsl:value-of select="location"/></div>
                <xsl:for-each select="detail">
                  <div class="detail"><xsl:value-of select="."/>       </div>
                </xsl:for-each>
              </div>
            </xsl:for-each>
          </div>
        </div>
        <footer>©2019 Jonah Mamakeesic</footer>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
