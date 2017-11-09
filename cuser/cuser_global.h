#ifndef CUSER_GLOBAL_H
#define CUSER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CUSER_LIBRARY)
#  define CUSERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CUSERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CUSER_GLOBAL_H
