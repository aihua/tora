//***************************************************************************
/* $Id$
**
** Copyright (C) 2000-2001 GlobeCom AB.  All rights reserved.
**
** This file is part of the Toolkit for Oracle.
**
** This file may be distributed under the terms of the Q Public License
** as defined by Trolltech AS of Norway and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.globecom.net/tora/ for more information.
**
** Contact tora@globecom.se if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef __TORESULTDEPEND_H
#define __TORESULTDEPEND_H

#include "toresultview.h"

/** This widget displays information about the dependencies of an object
 * specified by the first and second parameter in the query. The sql is not
 * used in the query. It will also recurs through all dependencies of the
 * objects depended on.
 */

class toResultDepend : public toResultView {
  /** Add children to this depend.
   */
  void addChilds(QListViewItem *item);
  /** Check if an object already exists.
   * @param owner Owner of object.
   * @param name Name of object.
   * @return True if object exists.
   */
  bool exists(const QString &owner,const QString &name);
public:
  /** Create the widget.
   * @param parent Parent widget.
   * @param name Name of widget.
   */
  toResultDepend(QWidget *parent,const char *name=NULL);

  /** Reimplemented for internal reasons.
   */
  virtual void query(const QString &sql,const toQList &param);
  /** Reimplemented for internal reasons.
   */
  void query(const QString &sql)
  { toQList p; query(sql,p); }
  /** Support Oracle
   */
  virtual bool canHandle(toConnection &conn)
  { return toIsOracle(conn); }
};

#endif
