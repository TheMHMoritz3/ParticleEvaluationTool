#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PARTILCLEEVALUATIONMODEL_LIB)
#  define PARTILCLEEVALUATIONMODEL_EXPORT Q_DECL_EXPORT
# else
#  define PARTILCLEEVALUATIONMODEL_EXPORT Q_DECL_IMPORT
# endif
#else
# define PARTILCLEEVALUATIONMODEL_EXPORT
#endif
